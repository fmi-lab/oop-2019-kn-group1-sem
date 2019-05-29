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

    void operator=(const Product& other) {
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

    void operator=(const User& other) {
        delete[] username;
        delete[] password;
        username = new char[strlen(other.username) + 1];
        strcpy(username, other.username);
        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);
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

double* copy_of(const double* arr, int size) {
    double* result = new double[size];
    for (int i = 0; i < size; i++) {
        result[i] = arr[i];
    }
    return result;
}

char* copy_of(const char* str) {
    char* result = new char[strlen(str) + 1];
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}

char* find_capitals(const char* str) {
    int number_of_capitals = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            number_of_capitals++;
        }
    }

    char* result = new char[number_of_capitals + 1];
    int result_i = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            result[result_i] = str[i];
            result_i++;
        }
    }

    result[result_i] = '\0';
    return result;
}

char* concat(const char* a, const char* b) {
    char* result = new char[strlen(a) + strlen(b) + 1];
    int result_i = 0;

    for (int i = 0; a[i] != '\0'; i++) {
        result[result_i] = a[i];
        result_i++;
    }

    for (int i = 0; b[i] != '\0'; i++) {
        result[result_i] = b[i];
        result_i++;
    }

    result[result_i] = '\0';
    return result;
}

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

int main() {
    char* p;

    p = copy_of("zaicheta");
    cout << p;
    expect("zaicheta");
    delete[] p;

    p = find_capitals("United States of America");
    cout << p;
    expect("USA");
    delete[] p;

    p = concat("Abc", "Def");
    cout << p;
    expect("AbcDef");
    delete[] p;

    Product pr1;
    pr1.print();
    expect(" 0.0  0");

    Product pr2("Sirene", Cost(9, 99), "Frensko", 50);
    pr2.print();
    expect("Sirene 9.99 Frensko 50");

    Product pr3(pr2);
    pr3.print();
    expect("Sirene 9.99 Frensko 50");

    pr3.set_name("Sirine");
    pr3.set_description("fr.");
    pr3.print();
    expect("Sirine 9.99 fr. 50");

    pr3 = pr2;
    pr3.print();
    expect("Sirene 9.99 Frensko 50");

    User u1;
    cout << "--"; u1.print(); cout << "--";
    expect("-- --");

    User u2("integralcho", "1234");
    u2.print();
    expect("integralcho 1234");

    User u3(u2);
    u3.print();
    expect("integralcho 1234");

    u3.set_username("the_maniac");
    u3.print();
    expect("the_maniac 1234");

    u3 = u2;
    u3.print();
    expect("integralcho 1234");
}