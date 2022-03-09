$BuildFolder = "build" 
$ExecutableName = "math.exe"

function Build-Number {
    echo "Building Number:"
    g++ -c staticLib0/number.cpp -o build/number.o
    ar rvs build/number.lib build/number.o
    echo "[DONE]"
    echo ""
}

function Build-Vector {
    echo "Building Vector:"
    g++ -c -IstaticLib0 Dll1/Vector.cpp -o build/Vector.o
    g++ -shared -o build/libVector.dll build/Vector.o build/number.lib
    echo "[DONE]"
    echo ""
}

function Build-App {
    echo "Building App:"
    g++ -IstaticLib0 -IDll1 -Lbuild/ -lVector testOSLib1/testOSLib1.cpp -o build/$ExecutableName
    echo "[DONE]"
    echo ""
}

function Build {
    if (-Not (Test-Path -Path $BuildFolder)) {
        mkdir $BuildFolder
    }
    Build-Number
    Build-Vector
    Build-App   
}

function Clean{
    echo "Cleaning build files"
    if (Test-Path -Path $BuildFolder) {
        rm -r $BuildFolder
    }
    echo "[DONE]"
    echo ""
}

function Run {   
    echo "Running the project at $BuildFolder/${ExecutableName}:"
    if (Test-Path -Path $BuildFolder/$ExecutableName) {
        &".\build\$ExecutableName"
    } else {
        echo "$ExecutableName not found. Firstly, consider building the project."
    }
    echo "[DONE]"
    echo ""
}

Build
Run
pause