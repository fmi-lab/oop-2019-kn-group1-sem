// This is the code we wrote in class
// This code is NOT READY

#include<iostream>
#include<cstring>
using namespace std;


class Product {
    char name[128];
    int cost;
    char description[128];
    int quantity;

public:
    char* get_name() {
        return name;
    }
    int get_cost() {
        return cost;
    }
    char* get_description() {
        return description;
    }
    int get_quantity() {
        return quantity;
    }

    void set_name(char* _name) {
        strcpy(name, _name);
    }
    void set_cost(int _cost) {
        cost = _cost;
    }
    void set_description(char* _description) {
        strcpy(description, _description);
    }
    void set_quantity(int _quantity) {
        quantity = _quantity;
    }
};


class User {
    char username[128];
    char password[128];

public:
    char* get_username() {
        return username;
    }

    void set_username(char* _username) {
        strcpy(username, _username);
    }
    void set_password(char* _password) {
        strcpy(password, _password);
    }

    bool matches(char* _username, char* _password) {
        return strcmp(username, _username) == 0
            && strcmp(password, _password) == 0;
    }
};


class Store {
    Product products[128];
    User users[128];
    int number_of_products = 0;
    int number_of_users = 0;

public:
    Product* get_products() {
        return products;
    }
    User* get_users() {
        return users;
    }
    int get_number_of_products() {
        return number_of_products;
    }
    int get_number_of_users() {
        return number_of_users;
    }

    void add_product(Product _product) {
        products[number_of_products] = _product;
        number_of_products++;
    }
    void add_user(User _user) {
        users[number_of_users] = _user;
        number_of_users++;
    }
};


int main() {
    Store store;

    int number_of_products_in_store;
    cout << "number_of_products_in_store: ";
    cin >> number_of_products_in_store;

    for (int i = 0; i < number_of_products_in_store; i++) {
        Product _product;
        char name[128];
        int cost;
        char description[128];
        int quantity;

        cin.ignore(); cin.getline(name, 128);

        cin >> cost;

        cin.ignore(); cin.getline(description, 128);

        cin >> quantity;

        _product.set_name(name);
        _product.set_cost(cost);
        _product.set_description(description);
        _product.set_quantity(quantity);

        store.add_product(_product);
    }


    int number_of_users_in_store;
    cout << "number_of_users_in_store: ";
    cin >> number_of_users_in_store;

    for (int i = 0; i < number_of_users_in_store; i++) {
        User _user;
        char _username[128];
        char _password[128];

        cout << "Username and password: ";
        cin >> _username >> _password;      // Usernames and passwords usually have no spaces in them
        _user.set_username(_username);
        _user.set_password(_password);

        store.add_user(_user);
    }

    
    char username[100];
    char password[100];
    cout << "Enter your username: "; cin >> username;
    cout << "Enter your password: "; cin >> password;

    bool logged_in = false;       // logged_in == true  <=>  there is logged user

    for (int i = 0; i < store.get_number_of_users(); i++) {
        if (store.get_users()[i].matches(username, password)) {
            logged_in = true;
            break;
        }
    }

    if (logged_in) {
        cout << "Successfully logged in" << endl;
    }
    else {
        cout << "Incorrect username or password" << endl;
    }
}