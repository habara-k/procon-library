#ifndef FACTORIAL
#define FACTORIAL

#include "../template.cpp"

template<typename Ring>
struct Fact {

    vector<Ring> fact;

    Fact(int n) {
        fact.resize(n+1);
        fact[0] = Ring{1};
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i-1] * Ring{i};
        }
    }

    Ring operator[](int i) {
        return fact[i];
    }
};

#endif
