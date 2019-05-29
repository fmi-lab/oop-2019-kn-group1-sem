#pragma once
#include<iostream>
#include"String.h"
using namespace std;

class User {
    String username;
    String password;

public:
    User(const String& _username, const String& _password) {
        username = _username;
        password = _password;
    }

    String get_username() const {
        return username;
    }

    void set_username(const String& _username) {
        username = _username;
    }
    void set_password(const String& _password) {
        password = _password;
    }

    // ?
    bool matches(const String& _username, const String& _password) const {
        return username == _username && password == _password;
    }

    void print() const {
        username.print();
        cout << ' ';
        password.print();
    }
};

