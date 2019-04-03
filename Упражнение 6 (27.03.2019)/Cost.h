#pragma once

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
