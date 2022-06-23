#include<iostream>
#include <algorithm>
#include <fstream>
#include "user.h"
#include "base.h"
#include "admin.h"


using namespace std;


int main() {

    ifstream fsss("data.txt", ios::in);
    if (!fsss.good()){
        addDefaultUser();
    }
    fsss.close();

    while (true) {
        string username, password;
        int ch;
        cout << " *******  Welcome to application ********";
        cout << "\n 1. Login Else Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << " Username : ";
                cin >> username;
                cout << " Password : ";
                cin >> password;
                break;
            default:
                exit(1);
        }

        switch (login(username, password)) {
            case 0 :
                adminPanel();
                break;
            case 1 :
                userPanel();
                break;
            default:
                cout << "Wrong username or password";
                break;
        }

    }

}
