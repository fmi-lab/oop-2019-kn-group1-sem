// This is the code we wrote in class
// This code is NOT READY

#include<iostream>
#include<cstring>
using namespace std;


class Cost {
    int lv;
    int st;
public:
    Cost() {
        lv = 0;
        st = 0;
    }
    Cost(int _lv, int _st) {
        lv = _lv;
        st = _st;
    }
    Cost(int _lv) {
        lv = _lv;
        st = 0;
    }

    int get_lv() {
        return lv;
    }
    int get_st() {
        return st;
    }

    void set_lv(int _lv) {
        lv = _lv;
    }
    void set_st(int _st) {
        st = _st;
    }

    bool is_valid() {
        return lv >= 0 && st >= 0 && st < 100;
    }
};

Cost sum_of_costs(Cost a, Cost b) {
    int sum_of_lv = a.get_lv() + b.get_lv();
    int sum_of_st = a.get_st() + b.get_st();
    return Cost(sum_of_lv + sum_of_st / 100, sum_of_st % 100);
}

class Product {
    char name[128];
    Cost cost;
    char description[128];
    int quantity;

public:
    Product() {
        name[0] = '\0';
        cost = 0;
        description[0] = '\0';
        quantity = 0;
    }
    Product(char* _name, Cost _cost, char* _description, int _quantity) {
        strcpy(name, _name);
        cost = _cost;
        strcpy(description, _description);
        quantity = _quantity;
    }

    char* get_name() {
        return name;
    }
    Cost get_cost() {
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
    void set_cost(Cost _cost) {
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
    User() {
        username[0] = '\0';
        password[0] = '\0';
    }
    User(char* _username, char* _password) {
        strcpy(username, _username);
        strcpy(password, _password);
    }

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
        char name[128];
        int cost;
        char description[128];
        int quantity;

        cin.ignore(); cin.getline(name, 128);
        cin >> cost;
        cin.ignore(); cin.getline(description, 128);
        cin >> quantity;

        Product _product(name, cost, description, quantity);

        store.add_product(_product);
    }


    int number_of_users_in_store;
    cout << "number_of_users_in_store: ";
    cin >> number_of_users_in_store;

    for (int i = 0; i < number_of_users_in_store; i++) {
        char _username[128];
        char _password[128];

        cout << "Username and password: ";
        cin >> _username >> _password;      // Usernames and passwords usually have no spaces in them
        
        User _user(_username, _password);

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