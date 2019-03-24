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

    Cost& operator=(const Cost& other) {
        lv = other.lv;
        st = other.st;
        return *this;
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

bool operator<(const Cost& a, const Cost& b) {
    return a.get_lv() < b.get_lv()
        || (a.get_lv() == b.get_lv() && a.get_st() < b.get_st());
}

Cost operator*(const Cost& c, int n) {
    int all_st_in_old_cost = c.get_lv() * 100 + c.get_st();
    int all_st_in_new_cost = all_st_in_old_cost * n;
    int new_lv = all_st_in_new_cost / 100;
    int new_st = all_st_in_new_cost % 100;
    return Cost(new_lv, new_st);
}


class Product {
    char* name;
    Cost cost;
    char* description;
    int quantity;

public:
    Product() {
        name = new char[1];
        name[0] = '\0';
        cost = 0;
        description = new char[1];
        description[0] = '\0';
        quantity = 0;
    }
    Product(const char* _name, const Cost& _cost, const char* _description, const int _quantity) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        cost = _cost;
        description = new char[strlen(_description) + 1];
        strcpy(description, _description);
        quantity = _quantity;
    }

    Product(const Product& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        cost = other.cost;

        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);

        quantity = other.quantity;
    }

    Product& operator=(const Product& other) {
        if (this != &other) {
            delete[] name;
            delete[] description;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            cost = other.cost;

            description = new char[strlen(other.description) + 1];
            strcpy(description, other.description);

            quantity = other.quantity;
        }
        return *this;
    }

    ~Product() {
        delete[] name;
        delete[] description;
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

    void set_name(const char* _name) {
        delete[] name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    void set_cost(const Cost& _cost) {
        cost = _cost;
    }
    void set_description(const char* _description) {
        delete[] description;
        description = new char[strlen(_description) + 1];
        strcpy(description, _description);
    }
    void set_quantity(int _quantity) {
        quantity = _quantity;
    }

    void print() const {
        cout << name << ' '
            << cost.get_lv() << '.' << cost.get_st() << ' '
            << description << ' ' << quantity;
    }
};


class User {
    char* username;
    char* password;

public:
    User() {
        username = new char[1];
        username[0] = '\0';
        password = new char[1];
        password[0] = '\0';
    }
    User(const char* _username, const char* _password) {
        username = new char[strlen(_username) + 1];
        strcpy(username, _username);
        password = new char[strlen(_password) + 1];
        strcpy(password, _password);
    }

    User(const User& other) {
        username = new char[strlen(other.username) + 1];
        strcpy(username, other.username);
        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);
    }

    User& operator=(const User& other) {
        if (this != &other) {
            delete[] username;
            delete[] password;
            username = new char[strlen(other.username) + 1];
            strcpy(username, other.username);
            password = new char[strlen(other.password) + 1];
            strcpy(password, other.password);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] password;
    }

    const char* get_username() const {
        return username;
    }

    void set_username(const char* _username) {
        delete[] username;
        username = new char[strlen(_username) + 1];
        strcpy(username, _username);
    }
    void set_password(const char* _password) {
        delete[] password;
        password = new char[strlen(_password) + 1];
        strcpy(password, _password);
    }

    bool matches(const char* _username, const char* _password) const {
        return strcmp(username, _username) == 0
            && strcmp(password, _password) == 0;
    }

    void print() const {
        cout << username << ' ' << password;
    }
};


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

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

int main() {
    // TODO: Write some tests
}
