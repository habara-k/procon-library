#ifndef FACTORIAL
#define FACTORIAL
#include "../template.cpp"

template<typename Ring>
struct Factorial {
    vector<Ring> fact;

    Factorial(int n) {
        fact.resize(n);
        fact[0] = Ring{1};
        for (int i = 1; i < n; ++i) {
            fact[i] = fact[i-1] * Ring{i};
        }
    }

    inline Ring operator()(int i) const {
        return fact.at(i);
    }
};
#endif
