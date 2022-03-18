#pragma once
//
// Created by Jan on 18.03.2022.
//

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

template<class T>
class BufferedChannel {

private:

    std::queue<T> buffer;
    int size;
    std::mutex mutex;
    std::condition_variable cVar;
    bool isOpened;

public:

    BufferedChannel() : size(1337), isOpened(true) {}

    BufferedChannel(int _size) : size(_size), isOpened(true) {}

    void send(T data) {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        if (!isOpened) {
            throw std::runtime_error("This channel is closed atm!");
        }

        cVar.wait(uniqueLock, [&]() { return buffer.size() != size && isOpened; });
        buffer.push(data);
        uniqueLock.unlock();
        cVar.notify_one();
    }


    std::pair<T, bool> recv() {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        cVar.wait(uniqueLock, [&]() { return !buffer.empty(); });
        T var = buffer.front();
        buffer.pop();
        uniqueLock.unlock();
        cVar.notify_one();
        return std::make_pair<T, bool>(var, isOpened);
    }


    void close() {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        isOpened = false;
        uniqueLock.unlock();
        cVar.notify_all();
    }
};
