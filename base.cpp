//
// Created by s25416 on 5/14/2022.
//

#include <iostream>
#include <fstream>
#include "base.h"
#include "user.h"

using namespace std;

int getSizeOfFile(string name) {
    ifstream fsc(name, ios::in);
    const int usersSize = std::count(istreambuf_iterator<char>(fsc),
                                     istreambuf_iterator<char>(), '\n');
    fsc.close();
    return usersSize;
}


int login(string un, string pw) {

    ifstream fs("data.txt", ios::in);

    if (!fs.good()){
        addNewUser();
    }
    string username;
    string password;
    unsigned int role;
    while (!fs.eof()) {
        fs >> username >> password >> role;
        if (un == username && pw == password) {
            if (role == 0) {
                return 0;
            } else if (role == 1) {
                return 1;
            }
        }

    }
    fs.close();
    return -1;
}