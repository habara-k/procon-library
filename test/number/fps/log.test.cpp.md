---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/convolution.hpp
    title: ac-library/atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/dsu.hpp
    title: ac-library/atcoder/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/fenwicktree.hpp
    title: ac-library/atcoder/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_bit.hpp
    title: ac-library/atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_csr.hpp
    title: ac-library/atcoder/internal_csr.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_math.hpp
    title: ac-library/atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_queue.hpp
    title: ac-library/atcoder/internal_queue.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_scc.hpp
    title: ac-library/atcoder/internal_scc.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_type_traits.hpp
    title: ac-library/atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/lazysegtree.hpp
    title: ac-library/atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/math.hpp
    title: ac-library/atcoder/math.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/maxflow.hpp
    title: ac-library/atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/mincostflow.hpp
    title: ac-library/atcoder/mincostflow.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/modint.hpp
    title: ac-library/atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/scc.hpp
    title: ac-library/atcoder/scc.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/segtree.hpp
    title: ac-library/atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/string.hpp
    title: ac-library/atcoder/string.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/twosat.hpp
    title: ac-library/atcoder/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: lib/number/fps.cpp
    title: lib/number/fps.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/number/fps/log.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
    #define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios()\
    \ {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n  \
    \      cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll =\
    \ long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a\
    \ = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a,\
    \ T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const map<T, U> &mp);\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '[';\n\
    \    REP(i, v.size()) {\n        if (i) os << ',';\n        os << v[i];\n    }\n\
    \    return os << ']';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    return os << '(' << p.first << ' ' << p.second\
    \ << ')';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const\
    \ map<T, U> &mp) {\n    os << '{';\n    for (const auto &p : mp) {\n        os\
    \ << p << endl;\n    }\n    return os << '}';\n}\n\nconst int INF = numeric_limits<int>::max();\n\
    const ll LINF = numeric_limits<ll>::max();\n\ntemplate<class T>\nstruct edge {\n\
    \    int from, to; T cost;\n    edge(int to, T cost) :\n        from(-1), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost) :\n        from(from), to(to),\
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/fps.cpp\"\n#include<atcoder/all>\n\
    using namespace atcoder;\n\n\n// https://opt-cp.com/fps-fast-algorithms\ntemplate<class\
    \ T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n \
    \   using vector<T>::operator=;\n    using F = FormalPowerSeries;\n\n    F operator-()\
    \ const {\n        F res(*this);\n        for (auto &e : res) e = -e;\n      \
    \  return res;\n    }\n    F &operator*=(const T &g) {\n        for (auto &e :\
    \ *this) e *= g;\n        return *this;\n    }\n    F &operator/=(const T &g)\
    \ {\n        assert(g != T(0));\n        *this *= g.inv();\n        return *this;\n\
    \    }\n    F &operator+=(const F &g) {\n        int n = this->size(), m = g.size();\n\
    \        REP(i, min(n, m)) (*this)[i] += g[i];\n        return *this;\n    }\n\
    \    F &operator-=(const F &g) {\n        int n = this->size(), m = g.size();\n\
    \        REP(i, min(n, m)) (*this)[i] -= g[i];\n        return *this;\n    }\n\
    \    F &operator<<=(const int d) {\n        int n = this->size();\n        if\
    \ (d >= n) *this = F(n);\n        this->insert(this->begin(), d, 0);\n       \
    \ this->resize(n);\n        return *this;\n    }\n    F &operator>>=(const int\
    \ d) {\n        int n = this->size();\n        this->erase(this->begin(), this->begin()\
    \ + min(n, d));\n        this->resize(n);\n        return *this;\n    }\n\n  \
    \  // O(n log n)\n    F inv(int d = -1) const {\n        int n = this->size();\n\
    \        assert(n != 0 && (*this)[0] != 0);\n        if (d == -1) d = n;\n   \
    \     assert(d >= 0);\n        F res{(*this)[0].inv()};\n        for (int m =\
    \ 1; m < d; m *= 2) {\n            F f(this->begin(), this->begin() + min(n, 2*m));\n\
    \            F g(res);\n            f.resize(2*m), internal::butterfly(f);\n \
    \           g.resize(2*m), internal::butterfly(g);\n            REP(i, 2*m) f[i]\
    \ *= g[i];\n            internal::butterfly_inv(f);\n            f.erase(f.begin(),\
    \ f.begin() + m);\n            f.resize(2*m), internal::butterfly(f);\n      \
    \      REP(i, 2*m) f[i] *= g[i];\n            internal::butterfly_inv(f);\n  \
    \          T iz = T(2*m).inv(); iz *= -iz;\n            REP(i, m) f[i] *= iz;\n\
    \            res.insert(res.end(), f.begin(), f.begin() + m);\n        }\n   \
    \     res.resize(d);\n        return res;\n    }\n\n    // fast: FMT-friendly\
    \ modulus only\n    // O(n log n)\n    F &multiply_inplace(const F &g, int d =\
    \ -1) {\n        int n = this->size();\n        if (d == -1) d = n;\n        assert(d\
    \ >= 0);\n        *this = convolution(move(*this), g);\n        this->resize(d);\n\
    \        return *this;\n    }\n    F multiply(const F &g, const int d = -1) const\
    \ { return F(*this).multiply_inplace(g, d); }\n    // O(n log n)\n    F &divide_inplace(const\
    \ F &g, int d = -1) {\n        int n = this->size();\n        if (d == -1) d =\
    \ n;\n        assert(d >= 0);\n        *this = convolution(move(*this), g.inv(d));\n\
    \        this->resize(d);\n        return *this;\n    }\n    F divide(const F\
    \ &g, const int d = -1) const { return F(*this).divide_inplace(g, d); }\n\n  \
    \  // O(n)\n    F &integ_inplace() {\n        int n = this->size();\n        assert(n\
    \ > 0);\n        if (n == 1) return *this = F{0};\n        this->insert(this->begin(),\
    \ 0);\n        this->pop_back();\n        vector<T> inv(n);\n        inv[1] =\
    \ 1;\n        int p = T::mod();\n        for (int i = 2; i < n; ++i) inv[i] =\
    \ - inv[p%i] * (p/i);\n        for (int i = 2; i < n; ++i) (*this)[i] *= inv[i];\n\
    \        return *this;\n    }\n    F integ() const { return F(*this).integ_inplace();\
    \ }\n\n    // O(n)\n    F &deriv_inplace() {\n        int n = this->size();\n\
    \        assert(n > 0);\n        for (int i = 2; i < n; ++i) (*this)[i] *= i;\n\
    \        this->erase(this->begin());\n        this->push_back(0);\n        return\
    \ *this;\n    }\n    F deriv() const { return F(*this).deriv_inplace(); }\n\n\
    \    // O(n log n)\n    F &log_inplace(int d = -1) {\n        int n = this->size();\n\
    \        assert(n > 0 && (*this)[0] == 1);\n        if (d == -1) d = n;\n    \
    \    assert(d >= 0);\n        if (d < n) this->resize(d);\n        F f_inv = this->inv();\n\
    \        this->deriv_inplace();\n        this->multiply_inplace(f_inv);\n    \
    \    this->integ_inplace();\n        return *this;\n    }\n    F log(const int\
    \ d = -1) const { return F(*this).log_inplace(d); }\n\n    // O(n log n)\n   \
    \ // https://arxiv.org/abs/1301.5804 (Figure 1, right)\n    F &exp_inplace(int\
    \ d = -1) {\n        int n = this->size();\n        assert(n > 0 && (*this)[0]\
    \ == 0);\n        if (d == -1) d = n;\n        assert(d >= 0);\n        F g{1},\
    \ g_fft;\n        this->resize(d);\n        (*this)[0] = 1;\n        F h_drv(this->deriv());\n\
    \        for (int m = 1; m < d; m *= 2) {\n            // prepare\n          \
    \  F f_fft(this->begin(), this->begin() + m);\n            f_fft.resize(2*m),\
    \ internal::butterfly(f_fft);\n\n            // Step 2.a'\n            if (m >\
    \ 1) {\n                F _f(m);\n                REP(i, m) _f[i] = f_fft[i] *\
    \ g_fft[i];\n                internal::butterfly_inv(_f);\n                _f.erase(_f.begin(),\
    \ _f.begin() + m/2);\n                _f.resize(m), internal::butterfly(_f);\n\
    \                REP(i, m) _f[i] *= g_fft[i];\n                internal::butterfly_inv(_f);\n\
    \                _f.resize(m/2);\n                _f /= T(-m) * m;\n         \
    \       g.insert(g.end(), _f.begin(), _f.begin() + m/2);\n            }\n\n  \
    \          // Step 2.b'--d'\n            F t(this->begin(), this->begin() + m);\n\
    \            t.deriv_inplace();\n            {\n                // Step 2.b'\n\
    \                F r{h_drv.begin(), h_drv.begin() + m-1};\n                //\
    \ Step 2.c'\n                r.resize(m); internal::butterfly(r);\n          \
    \      REP(i, m) r[i] *= f_fft[i];\n                internal::butterfly_inv(r);\n\
    \                r /= -m;\n                // Step 2.d'\n                t +=\
    \ r;\n                t.insert(t.begin(), t.back()); t.pop_back();\n         \
    \   }\n\n            // Step 2.e'\n            if (2*m < d || m == 1) {\n    \
    \            t.resize(2*m); internal::butterfly(t);\n                g_fft = g;\
    \ g_fft.resize(2*m); internal::butterfly(g_fft);\n                REP(i, 2*m)\
    \ t[i] *= g_fft[i];\n                internal::butterfly_inv(t);\n           \
    \     t.resize(m);\n                t /= 2*m;\n            }\n            else\
    \ { // \u3053\u306E\u5834\u5408\u5206\u3051\u3092\u3057\u3066\u3082\u6570\u30D1\
    \u30FC\u30BB\u30F3\u30C8\u3057\u304B\u901F\u304F\u306A\u3089\u306A\u3044\n   \
    \             F g1(g.begin() + m/2, g.end());\n                F s1(t.begin()\
    \ + m/2, t.end());\n                t.resize(m/2);\n                g1.resize(m),\
    \ internal::butterfly(g1);\n                t.resize(m),  internal::butterfly(t);\n\
    \                s1.resize(m), internal::butterfly(s1);\n                REP(i,\
    \ m) s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];\n                REP(i, m) t[i]\
    \ *= g_fft[i];\n                internal::butterfly_inv(t);\n                internal::butterfly_inv(s1);\n\
    \                REP(i, m/2) t[i+m/2] += s1[i];\n                t /= m;\n   \
    \         }\n\n            // Step 2.f'\n            F v(this->begin() + m, this->begin()\
    \ + min<int>(d, 2*m)); v.resize(m);\n            t.insert(t.begin(), m-1, 0);\
    \ t.push_back(0);\n            t.integ_inplace();\n            REP(i, m) v[i]\
    \ -= t[m+i];\n\n            // Step 2.g'\n            v.resize(2*m); internal::butterfly(v);\n\
    \            REP(i, 2*m) v[i] *= f_fft[i];\n            internal::butterfly_inv(v);\n\
    \            v.resize(m);\n            v /= 2*m;\n\n            // Step 2.h'\n\
    \            REP(i, min(d-m, m)) (*this)[m+i] = v[i];\n        }\n        return\
    \ *this;\n    }\n    F exp(const int d = -1) const { return F(*this).exp_inplace(d);\
    \ }\n\n    // O(n log n)\n    F &pow_inplace(ll k, int d = -1) {\n        int\
    \ n = this->size();\n        if (d == -1) d = n;\n        assert(d >= 0);\n  \
    \      int l = 0;\n        while ((*this)[l] == 0) ++l;\n        if (l > d/k)\
    \ return *this = F(d);\n        T ic = (*this)[l].inv();\n        T pc = (*this)[l].pow(k);\n\
    \        this->erase(this->begin(), this->begin() + l);\n        *this *= ic;\n\
    \        this->log_inplace();\n        *this *= k;\n        this->exp_inplace();\n\
    \        *this *= pc;\n        this->insert(this->begin(), l*k, 0);\n        this->resize(d);\n\
    \        return *this;\n    }\n    F pow(const ll k, const int d = -1) const {\
    \ return F(*this).pow_inplace(k, d); }\n\n    F operator*(const T &g) const {\
    \ return F(*this) *= g; }\n    F operator/(const T &g) const { return F(*this)\
    \ /= g; }\n    F operator+(const F &g) const { return F(*this) += g; }\n    F\
    \ operator-(const F &g) const { return F(*this) -= g; }\n    F operator<<(const\
    \ int d) const { return F(*this) <<= d; }\n    F operator>>(const int d) const\
    \ { return F(*this) >>= d; }\n};\n\nusing fps = FormalPowerSeries<modint998244353>;\n\
    #line 4 \"test/number/fps/log.test.cpp\"\n\nint main()\n{\n    int n; cin >> n;\n\
    \    fps a(n);\n    REP(i, n) {\n        int x; cin >> x;\n        a[i] = x;\n\
    \    }\n    for (auto x : a.log_inplace()) {\n        cout << x.val() << endl;\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#include \"../../../lib/number/fps.cpp\"\n\nint main()\n{\n    int n; cin\
    \ >> n;\n    fps a(n);\n    REP(i, n) {\n        int x; cin >> x;\n        a[i]\
    \ = x;\n    }\n    for (auto x : a.log_inplace()) {\n        cout << x.val() <<\
    \ endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/number/fps.cpp
  - lib/template.cpp
  - ac-library/atcoder/convolution.hpp
  - ac-library/atcoder/internal_bit.hpp
  - ac-library/atcoder/modint.hpp
  - ac-library/atcoder/internal_math.hpp
  - ac-library/atcoder/internal_type_traits.hpp
  - ac-library/atcoder/dsu.hpp
  - ac-library/atcoder/fenwicktree.hpp
  - ac-library/atcoder/lazysegtree.hpp
  - ac-library/atcoder/math.hpp
  - ac-library/atcoder/maxflow.hpp
  - ac-library/atcoder/internal_queue.hpp
  - ac-library/atcoder/mincostflow.hpp
  - ac-library/atcoder/internal_csr.hpp
  - ac-library/atcoder/scc.hpp
  - ac-library/atcoder/internal_scc.hpp
  - ac-library/atcoder/segtree.hpp
  - ac-library/atcoder/string.hpp
  - ac-library/atcoder/twosat.hpp
  isVerificationFile: true
  path: test/number/fps/log.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/fps/log.test.cpp
layout: document
redirect_from:
- /verify/test/number/fps/log.test.cpp
- /verify/test/number/fps/log.test.cpp.html
title: test/number/fps/log.test.cpp
---
