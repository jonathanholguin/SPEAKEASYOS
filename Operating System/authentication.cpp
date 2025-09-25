#include <iostream>
#include <cstdlib>
#include <thread>
#include <Windows.h>
#include "authentication.h"
using namespace std;

Authentication::Authentication(){
 
}

bool Authentication::login(string inputUsername, string inputPassword){
    if (inputUsername.empty() || inputPassword.empty()){
        cout << "Username or password cannot be empty." << endl;
        return false;
    }

        if (inputUsername == username && inputPassword == password) {
            system("cls");
            cout << "Logging in..." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            return true;
        }
        else {
            system("cls");
            cout << "Invalid username or password." << endl;
            return false;
        }

}