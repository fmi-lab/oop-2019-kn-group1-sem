#pragma once
#include<iostream>
#include"String.h"
#include"Cost.h"
using namespace std;

class Product {
    String name;
    Cost cost;
    String description;
    int quantity;

public:
    Product(const String& _name, const Cost& _cost, const String& _description, int _quantity) {
        name = _name;
        cost = _cost;
        description = _description;
        quantity = _quantity;
    }

    String get_name() const {
        return name;
    }
    Cost get_cost() const {
        return cost;
    }
    String get_description() const {
        return description;
    }
    int get_quantity() const {
        return quantity;
    }

    void set_name(const String& _name) {
        name = _name;
    }
    void set_cost(const Cost& _cost) {
        cost = _cost;
    }
    void set_description(const String& _description) {
        description = _description;
    }
    void set_quantity(int _quantity) {
        quantity = _quantity;
    }

    void print() const {
        name.print();
        cout << ' ' << cost.get_lv() << '.' << cost.get_st() << ' ';
        description.print();
        cout << ' ' << quantity;
    }
};
