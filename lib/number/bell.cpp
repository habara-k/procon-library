#include "../template.cpp"
#include "combination.cpp"
#include "stirling.cpp"

// Bell number
// Bell(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//
// require Comb<Field> GREATER THAN OR EQUAL TO k
template<typename Field>
Field Bell(LL n, LL k, Comb<Field>& comb) {
    Field ret = 0;
    for (LL l = 0; l <= k; ++l) {
        ret += Stirling(n, l, comb);
    }
    return ret;
}
