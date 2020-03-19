#ifndef COMBINATION
#define COMBINATION
#include "../template.cpp"
#include "factorial.cpp"

template<typename Field>
struct Combination {
    Factorial<Field> _fact;

    Combination(int n) : _fact(n) {}

    inline Field fact(int n) const {
        return _fact(n);
    }

    Field operator()(int n, int r) const {
        if (n < 0 || n-r < 0 || r < 0) {
            return Field{0};
        }
        return fact(n) / (fact(n-r) * fact(r));
    }
};
#endif
