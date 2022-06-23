//
// Created by s25416 on 5/14/2022.
//

#include <iostream>
#include "admin.h"
#include "user.h"


using namespace std;

void adminPanel() {
    cout << " *******  Admin Menu ********";
    bool isRun = true;
    while (isRun) {
        cout << "\n 1. Users \n 2. Users Edit \n Else Exit " << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        if (cin.good()) {
            switch (choice) {
                case 1 :
                    userManageBase();
                    break;
                case 2 :
                    userManage();
                    break;
                default:
                    isRun = false;
                    break;
            }
        } else {
            cin.clear();

            isRun = false;
        }
    }


}
