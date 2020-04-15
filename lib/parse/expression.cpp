#include "./parser.cpp"

int number(State& begin) {
    int ret = 0;
    while ('0' <= *begin and *begin <= '9') {
        ret *= 10;
        ret += *begin - '0';
        ++begin;
    }
    return ret;
}

int expression(State& begin);

int factor(State& begin) {
    if (*begin == '(') {
        ++begin;
        int ret = expression(begin);
        if (*begin != ')') {
            throw ParseError();
        }
        ++begin;
        return ret;
    } else {
        return number(begin);
    }
}

int term(State& begin) {
    int prod = factor(begin);
    while (true) {
        if (*begin == '*') {
            ++begin;
            prod *= factor(begin);
        }
        else if (*begin == '/') {
            ++begin;
            prod /= factor(begin);
        }
        else {
            return prod;
        }
    }
}

int expression(State& begin) {
    int sum = term(begin);
    while (true) {
        if (*begin == '+') {
            ++begin;
            sum += term(begin);
        } else if (*begin == '-') {
            ++begin;
            sum -= term(begin);
        } else {
            return sum;
        }
    }
}
