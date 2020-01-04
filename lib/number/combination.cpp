#ifndef COMBINATION
#define COMBINATION

#include "../template.cpp"

#include "factorial.cpp"

template<typename Field>
struct Comb {
    Fact<Field> fact;

    Comb(int n) : fact(n) {}

    Field operator()(int n, int r) {
        if (n < 0 || n-r < 0 || r < 0) {
            return Field{0};
        }
        return fact[n] / (fact[n-r] * fact[r]);
    }
};

#endif
