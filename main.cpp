#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "compile.hpp"

using namespace std;
string argv;
string file;

int main(int argc, char** argv)
{
    cout << "MWLang @ Copyright MultiWu 2019" << endl;
    if (argc <2) {
        cout << "Compiling: mwlang -c filename.mw" << endl;
        cout << "New .mw file: mwlang -n filename.mw" << endl;
    }
    else if (argc <3 && string (argv[1]) == "-c") {
        cout << "USAGE: " << "mwlang";
    }
    else if (argc == 3 && string (argv[1]) == "-c") {
        fstream plik;
        plik.open(argv[2], ios::in);

        if (plik.good()==false) {
            cout << "Error! There is no such file!" << endl;
            cout << "Error Code: 1" << endl;
            return 1;
        }
        else {
            stringstream argvx;
            argvx << argv[2];
            plik.close();
            compile(argvx);
        }
    }
    else if (argc <3 && string (argv[1]) == "-c") {
        cout << "USAGE: " << "mwlang" << " " << argv[1] << " " << "file.mw" << endl;
        Sleep(1250);
    }
    else if (argc == 3 && string (argv[1]) == "-n") {
        fstream plik1;
        plik1.open(argv[2], ios::out);
        plik1 << "" << endl;
        plik1.close();
    }
    return 0;
}
