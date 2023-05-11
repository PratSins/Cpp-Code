C++ Location for CPP-properties.json
    C:\\MinGW\\bin\\gcc.exe

Commands to run files involving User-defined header files in C++
1.
    g++ -o k.exe main.cpp Player.cpp
           file name - k.exe, and the cpp files to be compiled along       
2.
    .\k.exe 
    .\(file name)

3.
    g++ -E  main.cpp -o  pre.cpp
    to get the cpp file with cpp file with pre-processor stuff
4.
    additional .cpp files for the header files are created for modularity of the project
    They are NOT necessary.

5. MakeFile Info:
    Nothing... As yet..