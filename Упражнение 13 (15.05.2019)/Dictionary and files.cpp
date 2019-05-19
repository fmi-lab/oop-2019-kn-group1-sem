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
};

int main() {
    ifstream in;

    in.open("words.txt");

    string word;

    Dictionary<int> counts;

    while (!in.eof()) {
        in >> word;

        if (counts.has_key(word)) {
            // Намираме старата бройка
            int old_count = counts.get_value(word);

            // Обновяваме стойността за думата
            counts.update_value(word, old_count + 1);
        }
        else {
            // Добавяме двойка с думата word и числото 1
            counts.add_pair(word, 1);
        }
    }

    counts.print_all_pairs();
}
