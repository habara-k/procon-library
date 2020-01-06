#include "../template.cpp"
#include "../structure/binary_indexed_tree.cpp"

template<typename T>
LL inversion(const vector<T>& A)
{
    map<T, int> idx;
    for (T& a : A) idx[a] = -1;

    int cnt = 0;
    for (auto& p : idx) p.second = cnt++;

    assert(cnt == A.size());

    BIT<int> bit(cnt+1);
    LL res = 0;
    for (int i = 0; i < A.size(); ++i) {
        res += i - bit.sum(idx[A[i]]);
        bit.add(idx[A[i]], 1);
    }

    return res;
}
