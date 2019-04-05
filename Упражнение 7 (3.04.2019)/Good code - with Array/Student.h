#pragma once
#include"String.h"
#include"Array.h"

// Good version
class Student {
    String name;
    Array<double> grades;

public:
    void add_grade(double _grade) {
        grades.add_element(_grade);
    }

    int get_number_of_grades() const {
        return grades.get_number_of_elements();
    }

    double operator [] (int i) const {
        return grades[i];
    }

    double& operator [] (int i) {
        return grades[i];
    }
};
