#include "../template.cpp"
#include "combination.cpp"

// スターリング数
// Stirling(n, k) := 区別できるn 個のボールを
//                   区別できないk 個の箱に入れる場合の数
//                   (ただし空箱はNG)
template<typename Field>
Field Stirling(int64_t n, int k) {
    Combination<Field> comb(k+1);

    Field ret = 0;
    for (int i = 0; i <= k; ++i) {
        ret += comb.C(k, i) * Field{k-i}.pow(n) * (i & 1 ? -1 : 1);
    }
    return ret /= comb.fact(k);
}
