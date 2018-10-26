rmdir /s /q build 
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_MAKE_PROGRAM=c:\ninja\ninja.exe -DCMAKE_BUILD_TYPE=Release
c:\ninja\ninja.exe
