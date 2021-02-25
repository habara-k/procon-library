---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/bell.cpp
    title: lib/number/bell.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/combination.cpp
    title: lib/number/combination.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/modint.cpp
    title: lib/number/modint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/stirling.cpp
    title: lib/number/stirling.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
  bundledCode: "#line 1 \"test/number/bell/bell.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/modint.cpp\"\n\ntemplate<int mod>\n\
    class modint {\n    int x;\n\npublic:\n    modint(ll x = 0) : x(x < 0 ? (mod -\
    \ (-x) % mod) % mod : x % mod) {}\n\n    int val() const { return x; }\n    const\
    \ modint operator-() const { return x ? mod - x : 0; }\n    const modint inv()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b) {\n\
    \            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        assert(a == 1);\n        assert(b == 0);\n\
    \        return u;\n    }\n\n    modint& operator+=(const modint& rhs) {\n   \
    \     if ((x += rhs.x) >= mod) x -= mod;\n        return *this;\n    }\n    modint&\
    \ operator-=(const modint& rhs) {\n        return *this += -rhs;\n    }\n    modint&\
    \ operator*=(const modint& rhs) {\n        x = ((ll)x * rhs.x) % mod;\n      \
    \  return *this;\n    }\n    modint& operator/=(const modint& rhs) {\n       \
    \ return *this *= rhs.inv();\n    }\n\n    friend const modint operator+(modint\
    \ lhs, const modint& rhs) {\n        return lhs += rhs;\n    }\n    friend const\
    \ modint operator-(modint lhs, const modint& rhs) {\n        return lhs -= rhs;\n\
    \    }\n    friend const modint operator*(modint lhs, const modint& rhs) {\n \
    \       return lhs *= rhs;\n    }\n    friend const modint operator/(modint lhs,\
    \ const modint& rhs) {\n        return lhs /= rhs;\n    }\n\n    const modint\
    \ pow(ll n) const {\n        modint ret = 1, tmp = *this;\n        while (n) {\n\
    \            if (n & 1) ret *= tmp;\n            tmp *= tmp; n >>= 1;\n      \
    \  }\n        return ret;\n    }\n\n    friend bool operator==(const modint& lhs,\
    \ const modint& rhs) {\n        return lhs.x == rhs.x;\n    }\n    friend bool\
    \ operator!=(const modint& lhs, const modint& rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n\n    friend ostream& operator<<(ostream& os, const modint& a)\
    \ {\n        return os << a.x;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        ll tmp; is >> tmp; a = tmp;\n        return is;\n\
    \    }\n};\n\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1000000007>;\n\n#line 1 \"lib/number/combination.cpp\"\n\n\n#line 4\
    \ \"lib/number/combination.cpp\"\n\ntemplate<typename Field>\nstruct Combination\
    \ {\n    int _n = 1;\n    vector<Field> _fact{1}, _rfact{1}, _inv{0};\n\n    void\
    \ extend(int n) {\n        _fact.resize(n);\n        _rfact.resize(n);\n     \
    \   _inv.resize(n);\n        for (int i = _n; i < n; ++i) _fact[i] = _fact[i -\
    \ 1] * i;\n        _rfact[n - 1] = 1 / _fact[n - 1];\n        for (int i = n -\
    \ 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;\n        for (int i = _n; i <\
    \ n; ++i) _inv[i] = _rfact[i] * _fact[i - 1];\n        _n = n;\n    }\n\n    Field\
    \ fact(int k) {\n        if (_n <= k) extend(k + 1);\n        return _fact.at(k);\n\
    \    }\n\n    Field rfact(int k) {\n        if (_n <= k) extend(k + 1);\n    \
    \    return _rfact.at(k);\n    }\n\n    Field inv(int k) {\n        assert(k !=\
    \ 0);\n        if (_n <= k) extend(k + 1);\n        return _inv.at(k);\n    }\n\
    \n    Field P(int n, int r) {\n        if (r < 0 or n < r) return 0;\n       \
    \ return fact(n) * rfact(n - r);\n    }\n\n    Field C(int n, int r) {\n     \
    \   if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n\
    \ - r);\n    }\n\n    Field H(int n, int r) {\n        return (n == 0 and r ==\
    \ 0) ? 1 : C(n + r - 1, r);\n    }\n};\n\n#line 3 \"lib/number/stirling.cpp\"\n\
    \n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\n// Stirling(n, k) := \u533A\u5225\
    \u3067\u304D\u308Bn \u500B\u306E\u30DC\u30FC\u30EB\u3092\n//                 \
    \  \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\u306B\u5165\u308C\u308B\
    \u5834\u5408\u306E\u6570\n//                   (\u305F\u3060\u3057\u7A7A\u7BB1\
    \u306FNG)\ntemplate<typename Field>\nField Stirling(int64_t n, int k) {\n    Combination<Field>\
    \ comb;\n\n    Field ret = 0;\n    for (int i = 0; i <= k; ++i) {\n        ret\
    \ += comb.C(k, i) * Field{k-i}.pow(n) * (i & 1 ? -1 : 1);\n    }\n    return ret\
    \ /= comb.fact(k);\n}\n#line 3 \"lib/number/bell.cpp\"\n\n// Bell \u6570\n// Bell(n,\
    \ k) := \u533A\u5225\u3067\u304D\u308Bn \u500B\u306E\u30DC\u30FC\u30EB\u3092,\n\
    //               \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\u306B\
    \u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename Field>\nField Bell(ll\
    \ n, int k) {\n    Field ret = 0;\n    for (int i = 0; i <= k; ++i) {\n      \
    \  ret += Stirling<Field>(n, i);\n    }\n    return ret;\n}\n#line 5 \"test/number/bell/bell.test.cpp\"\
    \n\nint main() {\n    ll n, k; cin >> n >> k;\n\n    using Int = modint1000000007;\n\
    \n    cout << Bell<Int>(n, k) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n\n#include \"../../../lib/number/modint.cpp\"\n#include \"../../../lib/number/bell.cpp\"\
    \n\nint main() {\n    ll n, k; cin >> n >> k;\n\n    using Int = modint1000000007;\n\
    \n    cout << Bell<Int>(n, k) << endl;\n}\n"
  dependsOn:
  - lib/number/modint.cpp
  - lib/template.cpp
  - lib/number/bell.cpp
  - lib/number/stirling.cpp
  - lib/number/combination.cpp
  isVerificationFile: true
  path: test/number/bell/bell.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/bell/bell.test.cpp
layout: document
redirect_from:
- /verify/test/number/bell/bell.test.cpp
- /verify/test/number/bell/bell.test.cpp.html
title: test/number/bell/bell.test.cpp
---
