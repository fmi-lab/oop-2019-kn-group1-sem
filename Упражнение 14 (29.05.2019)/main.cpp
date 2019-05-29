#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

template<typename T, typename S>
class Pair {
    T first;
    S second;

public:
    void set_first(const T& _first) {
        first = _first;
    }
    void set_second(const S& _second) {
        second = _second;
    }

    T get_first() const {
        return first;
    }
    S get_second() const {
        return second;
    }
};

template<typename T, typename S>
void reverse_pairs(Pair<T, S>* pairs, int n) {
    for (int i = 0; i < n; i++) {
        T old_first = pairs[i].get_first();
        S old_second = pairs[i].get_second();
        pairs[i].set_first(old_second);
        pairs[i].set_second(old_first);
    }
}

template<typename V>
//using V = int;
class Dictionary {
    vector<Pair<string, V>> pairs;
public:
    void print_all_pairs() const {
        for (int i = 0; i < pairs.size(); i++) {
            cout << pairs[i].get_first() << ' '
                << pairs[i].get_second() << '\n';
        }
    }

    bool has_key(string key) const {
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].get_first() == key) {
                return true;
            }
        }
        return false;
    }

    void add_pair(string key, V value) {
        if (has_key(key)) {
            return;
        }
        Pair<string, V> new_pair;
        new_pair.set_first(key);
        new_pair.set_second(value);

        pairs.push_back(new_pair);
    }

    void update_value(string key, V new_value) {
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].get_first() == key) {
                pairs[i].set_second(new_value);
                return;
            }
        }

        // Сега сме сигурни, че няма двойка с този ключ,
        // затова добавяме нова двойка
        add_pair(key, new_value);
    }

    V get_value(string key) const {
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].get_first() == key) {
                return pairs[i].get_second();
            }
        }
    }

    void print_all_pairs_in_json() const {
        cout << "{ ";

        for (int i = 0; i < pairs.size(); i++) {
            cout << '"' << pairs[i].get_first() << '"'
                << ": " << pairs[i].get_second();
            
            if (i != pairs.size() - 1) {
                cout << ',';
            }
        }
        cout << " }";
    }

    void read_from_file(const char* filename) {
        pairs.clear();      // Make pair empty again

        ifstream in;
        in.open(filename);

        string dummy;
        in >> dummy;        // Dictionary:

        while (!in.eof()) {
            string word;
            V value;
            in >> word >> value;

            if (word != "") {
                add_pair(word, value);
            }
        }
    }

    void write_to_file(const char* filename) {
        ofstream out;
        out.open(filename);

        out << "Dictionary:\n";
        for (int i = 0; i < pairs.size(); i++) {
            out << pairs[i].get_first() << ' '
                << pairs[i].get_second() << '\n';
        }
    }

    void read_from_file_json(const char* filename) {
        pairs.clear();      // Make pair empty again

        ifstream in;
        in.open(filename);

        char symbol;
        string word;
        V value;

        while (true) {
            in >> symbol;

            if (symbol == '}') {
                return;
            }

            in >> symbol;

            word = "";
            while (in.peek() != '"') {      // peek() returns the symbol
                char next_letter_in_word;   // which will be read next
                in >> next_letter_in_word;
                word += next_letter_in_word;
            }

            in >> symbol >> symbol;
            in >> value;

            add_pair(word, value);
        }
    }

    void write_to_file_json(const char* filename) {
        ofstream out;
        out.open(filename);

        out << "{ ";
        for (int i = 0; i < pairs.size(); i++) {
            out << '"' << pairs[i].get_first() << '"'
                << ": " << pairs[i].get_second();
            
            if (i != pairs.size() - 1) {
                out << ",";
            }
            out << ' ';
        }
        out << "}";
    }
};

int main() {
    Dictionary<int> dictionary;

    string command;

    while (command != "exit") {
        cin >> command;
        if (command == "open") {
            string filename;
            cin >> filename;
            dictionary.read_from_file_json(filename.c_str());
        }
        else if (command == "save") {
            string filename;
            cin >> filename;
            dictionary.write_to_file_json(filename.c_str());
        }
    }
}
