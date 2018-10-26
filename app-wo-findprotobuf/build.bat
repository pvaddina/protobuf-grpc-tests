rmdir /s /q build 
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_MAKE_PROGRAM=c:\ninja\ninja.exe
c:\ninja\ninja.exe
