g++ to_do.cpp -o to_do.exe
g++ bf.cpp -o bf.exe -O2 -Wl,--stack=268435456
g++ std.cpp -o std.exe -Wl,--stack=268435456
g++ case.cpp -o case.exe -O2 -Wl,--stack=268435456

to_do.exe

pause