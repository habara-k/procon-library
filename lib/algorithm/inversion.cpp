#include "../template.cpp"
#include "../structure/binary_indexed_tree.cpp"

template<typename T>
int64_t inversion(const vector<T>& A)
{
    map<T, int> idx;
    for (const T& a : A) idx[a] = -1;

    int cnt = 0;
    for (auto& p : idx) p.second = cnt++;

    assert(cnt == A.size());

    BIT<int> bit(cnt+1);
    int64_t res = 0;
    for (int i = 0; i < A.size(); ++i) {
        res += i - bit.sum(idx[A[i]]);
        bit.add(idx[A[i]], 1);
    }

    return res;
}
