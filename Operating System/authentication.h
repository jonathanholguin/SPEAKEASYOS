#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream>
#include <string>
using namespace std;

class Authentication{
    private:
        string username = "admin";
        string password = "123";

    public:
        Authentication();
        bool login(string username, string password);
};

#endif