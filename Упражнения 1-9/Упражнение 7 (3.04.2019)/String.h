#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class String {
    char* arr;

public:
    String() {
        arr = new char[1];
        arr[0] = '\0';
    }

    String(const char* _arr) {
        arr = new char[strlen(_arr) + 1];
        strcpy(arr, _arr);
    }

    String(const String& other) {
        arr = new char[strlen(other.arr) + 1];
        strcpy(arr, other.arr);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] arr;
            arr = new char[strlen(other.arr) + 1];
            strcpy(arr, other.arr);
        }
        return *this;
    }

    String& operator=(const char* _arr) {
        delete[] arr;
        arr = new char[strlen(_arr) + 1];
        strcpy(arr, _arr);
        return *this;
    }

    ~String() {
        delete[] arr;
    }

    char* to_char_array() const {
        return arr;
    }

    int lenght() const {
        return strlen(arr);
    }

    void print() const {
        cout << arr;
    }

    char& operator[] (int i) {
        return arr[i];
    }

    char operator[] (int i) const {
        return arr[i];
    }

    void operator+=(const String& other) {
        *this = *this + other;
    }

    String operator+(const String& other) const {
        char* result = new char[strlen(arr) + strlen(other.arr) + 1];
        result[0] = '\0';
        strcat(result, arr);
        strcat(result, other.arr);
        return String(result);
    }

    String operator+(const char* _arr) const {
        char* result = new char[strlen(arr) + strlen(_arr) + 1];
        result[0] = '\0';
        strcat(result, arr);
        strcat(result, _arr);
        return String(result);
    }
};