#ifndef COMPILE_HPP_INCLUDED
#define COMPILE_HPP_INCLUDED
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int i;
int i2;
string parametr;
string line[100];
string linia;
string konc[1];

string plik2;

int compile(stringstream& plik) {
    for (i=0; i<=2; i++) {
        getline(plik, konc[i], '.');
    }
    plik2 = konc[0] + ".cpp";
    fstream file2(plik2);
    fstream file(plik.str());
    for (i=1; i<=100; i++) {
        getline(file, line[i], ' ');
    }
    file.close();
    for (i=1; i<=100; i++) {
        if (line[i] == "") {}
        else {
            cout << line[i] << endl;
        }
    }
    file2.open( plik2, ios::out | ios::app );
    file2 << "// Created by MWLang Alpha Development Kit @ Copyright MultiWu 2019" << endl;
    file2 << endl;
    file2 << "void main() {" << endl;
    for (i=1; i<=100; i++) {
        if (line[i] == "print") {
            i = i2;
            i2++;
            file2 << "cout << ";
            file2 << "\"";
            file2 << line[i2];
            file2 << "\" << endl;" << endl;
        }
        if (line[i] == "exit") {
            file2 << "return 0;" << endl;
        }
        if (line[i] == "sum") {
            i = i2;
            i2++;
            file2 << "cout << ";
            file2 << line[i2];
            i2++;
            file2 << " ";
            file2 << line[i2];
            i2++;
            file2 << " ";
            file2 << line[i2];
            i2++;
            file2 << " ";
            file2 << "endl;";
            }
    }
    file2 << "}" << endl;
    file2.close();
    return 0;
}

#endif // COMPILE_HPP_INCLUDED
