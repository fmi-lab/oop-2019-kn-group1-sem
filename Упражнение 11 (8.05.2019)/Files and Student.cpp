#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Student {
public:
    string name;
    int fn;
    double grades[20];
    int number_of_grades = 0;

    void save_into_stream(ofstream& out) {
        out << name << '\n';
        out << fn << '\n';
        out << number_of_grades << '\n';
        for (int i = 0; i < number_of_grades; i++) {
            out << grades[i] << ' ';
        }
    }

    void read_from_stream(ifstream& in) {
        in >> name;
        in >> fn;
        in >> number_of_grades;
        for (int i = 0; i < number_of_grades; i++) {
            in >> grades[i];
        }
    }
};

int main() {
    Student st;
    ifstream in;
    ofstream out;
    string command;
    bool running = true;

    while (running) {
        cin >> command;

        if (command == "open") {
            string file_name;
            cin >> file_name;

            in.open(file_name);

            st.read_from_stream(in);
            in.close();
        }
        else if (command == "print") {
            cout << st.name << '\n';
            cout << st.fn << '\n';
            cout << st.number_of_grades << '\n';
            for (int i = 0; i < st.number_of_grades; i++) {
                cout << st.grades[i];
            }
        }
        else if (command == "save") {
            string file_name;
            cin >> file_name;
            
            out.open(file_name);
           
            st.save_into_stream(out);
            out.close();
        }
        else if (command == "edit") {
            // ...
        }
        else if (command == "exit") {
            running = false;
        }
    }
}
