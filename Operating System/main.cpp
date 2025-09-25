#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <Windows.h>
#include "authentication.h"

using namespace std;

int main() {
    Authentication auth;
    string username, password;

    cout << "Booting SpeakeasyOS...\n\n";
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
    cout << "[ S P E A K E A S Y ]";\
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
    cout << "Starting Speakeasy...\n";
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");

    do {

    cout << "USER: ";
    cin >> username;
    cout << "PASS: ";
    cin >> password;

    if(auth.login(username, password)){
        system("cls");
        cout << "Access granted." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        return 0;
        
    }
    //else{
    //    cout << "Access denied." << endl;
    //}
    } while (password != "cancel");

    return 0;
}