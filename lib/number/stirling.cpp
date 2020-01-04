#include "../template.cpp"
#include "combination.cpp"

// Stirling number
// Stirling(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//            s.t. each box contains at least one ball.
//
// require Comb<Field> GREATER THAN OR EQUAL TO k
template<typename Field>
Field Stirling(LL n, LL k, Comb<Field>& comb) {
    Field ret = 0;
    for (LL l = 0; l <= k; ++l) {
        ret += comb(k, l) * Field(k-l).pow(n) * (l & 1 ? -1 : 1);
    }
    return ret /= comb.fact[k];
}
