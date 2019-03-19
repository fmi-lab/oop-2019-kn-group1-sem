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

    Cost(const Cost& other) {
        lv = other.lv;
        st = other.st;
    }

    void operator=(const Cost& other) {
        lv = other.lv;
        st = other.st;
    }

    int get_lv() const {
        return lv;
    }
    int get_st() const {
        return st;
    }

    void set_lv(int _lv) {
        lv = _lv;
    }
    void set_st(int _st) {
        st = _st;
    }

    bool is_valid() const {
        return lv >= 0 && st >= 0 && st < 100;
    }

    void operator+=(int added_lv) {
        lv = lv + added_lv;
    }

    void operator+= (const Cost& other) {
        int sum_of_lv = lv + other.lv;
        int sum_of_st = st + other.st;
        lv = sum_of_lv + sum_of_st / 100;
        st = sum_of_st % 100;
    }
};

Cost operator+(const Cost& a, const Cost& b) {
    int sum_of_lv = a.get_lv() + b.get_lv();
    int sum_of_st = a.get_st() + b.get_st();
    return Cost(sum_of_lv + sum_of_st / 100, sum_of_st % 100);
}

bool operator==(const Cost& a, const Cost& b) {
    return a.get_lv() == b.get_lv() && a.get_st() == b.get_st();
}

bool operator<(const Cost& a, const Cost& b) {  // TODO
    return a.get_lv() < b.get_lv()
       || (a.get_lv() == b.get_lv() && a.get_st() < b.get_st());
}

Cost operator*(const Cost& c, int n) {      // TODO
    int all_st_in_old_cost = c.get_lv() * 100 + c.get_st();
    int all_st_in_new_cost = all_st_in_old_cost * n;
    int new_lv = all_st_in_new_cost / 100;
    int new_st = all_st_in_new_cost % 100;
    return Cost(new_lv, new_st);
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
    Product(char* _name, const Cost& _cost, char* _description, int _quantity) {
        strcpy(name, _name);
        cost = _cost;
        strcpy(description, _description);
        quantity = _quantity;
    }

    Product(const Product& other) {
        strcpy(name, other.name);
        cost = other.cost;
        strcpy(description, other.description);
        quantity = other.quantity;
    }

    void operator=(const Product& other) {
        strcpy(name, other.name);
        cost = other.cost;
        strcpy(description, other.description);
        quantity = other.quantity;
    }

    const char* get_name() const {
        return name;
    }
    Cost get_cost() const {
        return cost;
    }
    const char* get_description() const {
        return description;
    }
    int get_quantity() const {
        return quantity;
    }

    void set_name(char* _name) {
        strcpy(name, _name);
    }
    void set_cost(const Cost& _cost) {
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

    User(const User& other) {
        strcpy(username, other.username);
        strcpy(password, other.password);
    }

    void operator=(const User& other) {
        strcpy(username, other.username);
        strcpy(password, other.password);
    }

    const char* get_username() const {
        return username;
    }

    void set_username(char* _username) {
        strcpy(username, _username);
    }
    void set_password(char* _password) {
        strcpy(password, _password);
    }

    bool matches(char* _username, char* _password) const {
        return strcmp(username, _username) == 0
            && strcmp(password, _password) == 0;
    }
};


class Store {
    Product products[128];
    User users[128];
    int number_of_products;
    int number_of_users;

public:
    Store() {
        number_of_products = 0;
        number_of_users = 0;
    }

    Store(const Store& other) {
        number_of_products = other.number_of_products;
        number_of_users = other.number_of_users;

        for (int i = 0; i < number_of_products; i++) {
            products[i] = other.products[i];
        }
        for (int i = 0; i < number_of_users; i++) {
            users[i] = other.users[i];
        }
    }

    void operator=(const Store& other) {
        number_of_products = other.number_of_products;
        number_of_users = other.number_of_users;

        for (int i = 0; i < number_of_products; i++) {
            products[i] = other.products[i];
        }
        for (int i = 0; i < number_of_users; i++) {
            users[i] = other.users[i];
        }
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
        for (int i = 0; i < number_of_products; i++) {
            if (strcmp(products[i].get_name(), _product.get_name())) {
                int updated_quantity = products[i].get_quantity() + _product.get_quantity();
                products[i].set_quantity(updated_quantity);
                return;
            }
        }
        products[number_of_products] = _product;
        number_of_products++;
    }
    void operator+= (const User& _user) {
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

        store += _product;
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

        store += _user;
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
