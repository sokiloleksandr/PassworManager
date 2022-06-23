//
// Created by s25416 on 5/14/2022.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "user.h"
#include "base.h"


using namespace std;

class User {

private:
    string username;
    string password;
    unsigned int role;
    string category;


public:
    User() : username(""), password(""), category(""), role(99) {}

    void setUsername(const string &username) {
        User::username = username;
    }

    void setPassword(const string &password) {
        User::password = password;
    }

    void setRole(unsigned int role) {
        User::role = role;
    }

    const string &getUsername() const {
        return username;
    }

    const string &getPassword() const {
        return password;
    }

    unsigned int getRole() const {
        return role;
    }

    const string &getCategory() const {
        return category;
    }

    void setCategory(const string &category) {
        User::category = category;
    }

    void registerUser() {

        ofstream fs("data.txt", ios::app);
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter category: ";
        cin >> category;
        cout << "Press 0. Admin 1. User" << endl;
        cin >> role;
        if (passwordCheck(password) > 50)
            fs << username << " " << password << " " << category << " " << role << " \n";
        else
            cout << "ERROR 260097: password is too weak!";
        fs.close();
    }

    void registerDefaultUser() {

        ofstream fs("data.txt", ios::app);
        fs << "admin" << " " << "1234" << " " << "adm" << " " << "0" << " \n";
        fs.close();
    }


};


void userPanel() {
    cout << " *******  User Menu ********";
    bool isRun = true;
    while (isRun) {
        cout << "\n 1. Users \n else Exit " << endl;
        int choise;
        cout << "Enter choice: ";
        cin >> choise;
        if (cin.good()) {
            switch (choise) {
                case 1 :
                    userManageBase();
                    break;

                default:
                    isRun = false;
                    break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isRun = false;
        }
    }
}

void userManage() {
    bool isRun = true;
    while (isRun) {
        cout
                << "\n 1. Show all users \n 2. Add new user \n 3. Update user \n 4. Remove user \n 5. Remove category \n Else Exit"
                << endl;
        int choise;
        cout << "Enter choice: ";
        cin >> choise;
        if (cin.good()) {
            switch (choise) {
                case 1 :
                    showAllUsers();
                    break;
                case 2 :
                    addNewUser();
                    break;
                case 3:
                    updateUser();
                    break;
                case 4:
                    removeUser();
                    break;
                case 5:
                    removeCategory();
                    break;
                default:
                    isRun = false;
                    break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isRun = false;
        }
    }
}


void userManageBase() {
    bool isRun = true;
    while (isRun) {
        cout << "\n 1. Show all users \n 2. Sort users \n 3. Search data \n Else Exit" << endl;
        int choise;
        cout << "Enter choice: ";
        cin >> choise;
        if (cin.good()) {
            switch (choise) {
                case 1 :
                    showAllUsers();
                    break;
                case 2 :
                    sortAllUsers();
                    break;
                case 3 :
                    searchAllUsers();
                    break;
                default:
                    isRun = false;
                    break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isRun = false;
        }
    }
}


bool compareByName(User const &a, User const &b) {
    return a.getUsername().at(0) < b.getUsername().at(0);
}

bool compareByCategory(User const &a, User const &b) {
    return a.getCategory() < b.getCategory();
}

void sortAllUsers() {
    int usersSize = getSizeOfFile("data.txt");
    string username;
    string password;
    string category;
    unsigned int role;
    User *l1 = new User[usersSize];
    ifstream fs("data.txt", ios::in);
    for (int i = 0; i < usersSize; i++) {
        fs >> username >> password >> category >> role;
        l1[i].setUsername(username);
        l1[i].setPassword(password);
        l1[i].setCategory(category);
        l1[i].setRole(role);
    }
    fs.close();
    bool isRun = true;
    while (isRun) {
        cout << "\n 1. Sort by category \n 2. Sort by username \n else exit"
             << endl;
        int option;
        cout << "Enter choice: ";
        cin >> option;
        if (cin.good()) {
            switch (option) {
                case 1 :
                    std::sort(l1, l1 + usersSize, compareByCategory);
                    break;
                case 2 :
                    std::sort(l1, l1 + usersSize, compareByName);
                    break;
                default:
                    isRun = false;
                    break;
            }

            cout << "| User name | Password | Category | Role | \n";
            for (int i = 0; i < usersSize; ++i) {
                cout << "| " << l1[i].getUsername() << " |" << l1[i].getPassword() << " |" << l1[i].getCategory()
                     << " |" << l1[i].getRole() << " |" << " |\n";
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isRun = false;
        }
    }

    delete[] l1;
}

void searchAllUsers() {
    int usersSize = getSizeOfFile("data.txt");
    string username;
    string password;
    string category;
    unsigned int role;
    User *l1 = new User[usersSize];
    ifstream fs("data.txt", ios::in);
    for (int i = 0; i < usersSize; i++) {
        fs >> username >> password >> category >> role;
        l1[i].setUsername(username);
        l1[i].setPassword(password);
        l1[i].setCategory(category);
        l1[i].setRole(role);
    }
    fs.close();
    bool isRun = true;
    while (isRun) {
        cout << "\n 1. Search by category \n 2. Search by name \n 3. Search by role \n else exit"
             << endl;
        int option;
        cout << "Enter choice: ";
        cin >> option;
        if (cin.good()) {
            switch (option) {
                case 1 : {
                    string category;
                    cout << "Enter category: ";
                    cin >> category;
                    if (cin.good()) {
                        cout << "| User name | Password | Category | Role | \n";
                        for (int i = 0; i < usersSize; ++i) {
                            if (l1[i].getCategory() == category) {
                                cout << "| " << l1[i].getUsername() << " |" << l1[i].getPassword() << " |"
                                     << l1[i].getCategory()
                                     << " |" << l1[i].getRole() << " |" << " |\n";
                            }
                        }
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }
                case 2 : {
                    string username;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "| User name | Password | Category | Role | \n";
                    for (int i = 0; i < usersSize; ++i) {
                        if (l1[i].getUsername() == username) {
                            cout << "| " << l1[i].getUsername() << " |" << l1[i].getPassword() << " |"
                                 << l1[i].getCategory()
                                 << " |" << l1[i].getRole() << " |" << " |\n";
                        }
                    }


                    break;
                }
                case 3 : {
                    int role;
                    cout << "Enter role(0. admin or 1.user): ";
                    cin >> role;
                    if (cin.good()) {
                        cout << "| User name | Password | Category | Role | \n";
                        for (int i = 0; i < usersSize; ++i) {
                            if (l1[i].getRole() == role) {
                                cout << "| " << l1[i].getUsername() << " |" << l1[i].getPassword() << " |"
                                     << l1[i].getCategory()
                                     << " |" << l1[i].getRole() << " |" << " |\n";
                            }
                        }
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }
                default:
                    isRun = false;
                    break;
            }


        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isRun = false;
        }
    }

    delete[] l1;
}

void removeUser() {
    string username;
    cout << "Write username : ";
    cin >> username;
    removeUser(username);
}

void updateUser() {

    string username, newUsername, newPassword, newCategory;
    unsigned int newRole;
    cout << "Write last username : ";
    cin >> username;
    cout << "Write new username : ";
    cin >> newUsername;
    cout << "Write new password : ";
    cin >> newPassword;
    cout << "Write new category : ";
    cin >> newCategory;
    cout << "Write new role 0. Admin 1. User: ";
    cin >> newRole;
    removeUser(username);
    ofstream fs("data.txt", ios::app);
    if (passwordCheck(newPassword) > 50)
        fs << newUsername << " " << newPassword << " " << newCategory << " " << newRole << " \n";
    else
        cout << "ERROR 260097: password is too weak!";
    fs.close();


}

void removeUser(string un) {
    ifstream fs("data.txt", ios::in);
    ofstream temp("temp.txt", ios::app);
    string username;
    string password;
    string category;
    unsigned int role;
    while (!fs.eof()) {
        fs >> username >> password >> category >> role;
        if (un != username) {
            temp << username << " " << password << " " << category << " " << role << " \n";
        }
    }
    fs.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");

}

void removeCategory() {
    string category;
    cout << "Write category : ";
    cin >> category;
    removeCategory(category);
}

void removeCategory(string ct) {
    ifstream fs("data.txt", ios::in);
    ofstream temp("temp.txt", ios::app);
    string username;
    string password;
    string category;
    unsigned int role;
    while (!fs.eof()) {
        fs >> username >> password >> category >> role;
        if (ct != category) {
            temp << username << " " << password << " " << category << " " << role << " \n";
        }
    }
    fs.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}


void addNewUser() {
    User().registerUser();
}

void addDefaultUser() {
    User().registerDefaultUser();
}

void showAllUsers() {
    int usersSize = getSizeOfFile("data.txt");
    string username;
    string password;
    string role;
    string category;
    User *l1 = new User[usersSize];
    ifstream fs("data.txt", ios::in);
    for (int i = 0; i < usersSize; i++) {
        fs >> username >> password >> category >> role;
        l1[i].setUsername(username);
        l1[i].setPassword(password);
        l1[i].setCategory(category);
        l1[i].setRole(stoi(role));
    }
    fs.close();
    cout << "| User name | Password | Category | Role | \n";
    for (int i = 0; i < usersSize; ++i) {
        cout << "| " << l1[i].getUsername() << " |" << l1[i].getPassword() << " |" << l1[i].getCategory()
             << " |" << l1[i].getRole() << " |\n";
    }
    delete[] l1;

}

int passwordCheck(string password) {

    int excess = password.size() - 6;
    int baseScore = 50;

    int numUpper = 0;
    int numSymbol = 0;
    int numLower = 0;
    int numDigit = 0;

    int bonusExcess = 3;
    int bonusUpper = 4;
    int bonusNumbers = 5;
    int bonusSymbols = 5;
    int bonusCombo = 0;
    int bonusFlatLower = 0;
    int bonusFlatNumber = 0;

    int i;
    for (i = 0; i < password.size(); i++) {
        if (password[i] >= 48 && password[i] <= 57) {  // 0-9
            numDigit++;
        }
        if (password[i] >= 97 && password[i] <= 125) { // a-z
            numLower++;
        }
        if (password[i] >= 65 && password[i] <= 90) { // A-Z
            numUpper++;
        }
        if (password[i] >= 33 && password[i] <= 47) { //symbols
            numSymbol++;
        }
    }

    if (numUpper > 0 && numDigit > 0 && numSymbol > 0) {
        bonusCombo = 25;
    } else if ((numUpper > 0 && numDigit > 0) || (numUpper > 0 && numSymbol > 0) || (numDigit > 0 && numSymbol > 0)) {
        bonusCombo = 15;
    }

    int score = baseScore + (excess * bonusExcess) + (numUpper * bonusUpper) +
                (numDigit * bonusNumbers) + (numSymbol * bonusSymbols) +
                bonusCombo + bonusFlatLower + bonusFlatNumber;

    return score;
}
