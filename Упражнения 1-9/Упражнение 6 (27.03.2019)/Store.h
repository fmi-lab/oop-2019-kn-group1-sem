#pragma once
#include"Product.h"
#include"User.h"

class Store {
    Product* products;
    int number_of_products;
    int capacity_of_products;

    User* users;
    int number_of_users;
    int capacity_of_users;

public:
    Store() {
        number_of_products = 0;
        capacity_of_products = 10;
        products = new Product[capacity_of_products];

        number_of_users = 0;
        capacity_of_users = 8;                  // Any power of 2 is OK here
        users = new User[capacity_of_users];
    }

    Store(const Store& other) {
        number_of_products = other.number_of_products;
        capacity_of_products = other.capacity_of_products;
        products = new Product[capacity_of_products];

        number_of_users = other.number_of_users;
        capacity_of_users = other.capacity_of_users;
        users = new User[capacity_of_users];

        for (int i = 0; i < number_of_products; i++) {
            products[i] = other.products[i];
        }
        for (int i = 0; i < number_of_users; i++) {
            users[i] = other.users[i];
        }
    }

    Store& operator=(const Store& other) {
        if (this != &other) {
            delete[] products;
            delete[] users;

            number_of_products = other.number_of_products;
            capacity_of_products = other.capacity_of_products;
            products = new Product[capacity_of_products];

            number_of_users = other.number_of_users;
            capacity_of_users = other.capacity_of_users;
            users = new User[capacity_of_users];

            for (int i = 0; i < number_of_products; i++) {
                products[i] = other.products[i];
            }
            for (int i = 0; i < number_of_users; i++) {
                users[i] = other.users[i];
            }
        }
        return *this;
    }

    ~Store() {
        delete[] products;
        delete[] users;
    }

    const Product* get_products() const {
        return products;
    }
    const User* get_users() const {
        return users;
    }
    int get_number_of_products() const {
        return number_of_products;
    }
    int get_number_of_users() const {
        return number_of_users;
    }

    void operator+= (const Product& _product) {

        // Check if the product exists
        for (int i = 0; i < number_of_products; i++) {
            if (strcmp(products[i].get_name(), _product.get_name())) {
                int updated_quantity = products[i].get_quantity() + _product.get_quantity();
                products[i].set_quantity(updated_quantity);
                return;
            }
        }

        // Now we are sure - we must add the product

        if (number_of_products == capacity_of_products) {

            // Memory is full, we need new memory

            capacity_of_products += 10;
            Product* helper = new Product[capacity_of_products];

            for (int i = 0; i < number_of_products; i++) {
                helper[i] = products[i];
            }
            helper[number_of_products] = _product;
            number_of_products++;

            delete[] products;
            products = helper;
        }

        else {
            // There is memory, so we just add the new product
            products[number_of_products] = _product;
            number_of_products++;
        }
    }
    void operator+= (const User& _user) {

        if (number_of_users == capacity_of_users) {

            // Memory is full, we need new memory

            capacity_of_users *= 2;
            User* helper = new User[capacity_of_users];

            for (int i = 0; i < number_of_users; i++) {
                helper[i] = users[i];
            }
            helper[number_of_users] = _user;
            number_of_users++;

            delete[] users;
            users = helper;
        }

        else {
            // There is memory, so we just add the new product
            users[number_of_users] = _user;
            number_of_users++;
        }
    }
};
