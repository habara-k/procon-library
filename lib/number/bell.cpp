#include "../template.cpp"
#include "stirling.cpp"

// Bell 数
// Bell(n, k) := 区別できるn 個のボールを,
//               区別できないk 個の箱に入れる場合の数
template<typename Field>
Field Bell(ll n, int k) {
    Field ret = 0;
    for (int i = 0; i <= k; ++i) {
        ret += Stirling<Field>(n, i);
    }
    return ret;
}
