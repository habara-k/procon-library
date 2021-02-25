---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/modint.cpp
    title: lib/number/modint.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
  bundledCode: "#line 1 \"test/number/modint/modint.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\n\n#line 1\
    \ \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n#define\
    \ DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios() {\n\
    \        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n      \
    \  cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll = long\
    \ long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a = b;\
    \ return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a, T\
    \ b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
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
    \ = modint<1000000007>;\n\n#line 4 \"test/number/modint/modint.test.cpp\"\n\n\
    int main() {\n    ll n, k;\n    cin >> n >> k;\n\n    if (n > k) {\n        cout\
    \ << 0 << endl;\n        return 0;\n    }\n\n    using Int = modint1000000007;\n\
    \    Int ans = 1;\n    for (ll i = 0; i < n; ++i) {\n        ans *= (k - i);\n\
    \    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
    \n\n#include \"../../../lib/number/modint.cpp\"\n\nint main() {\n    ll n, k;\n\
    \    cin >> n >> k;\n\n    if (n > k) {\n        cout << 0 << endl;\n        return\
    \ 0;\n    }\n\n    using Int = modint1000000007;\n    Int ans = 1;\n    for (ll\
    \ i = 0; i < n; ++i) {\n        ans *= (k - i);\n    }\n    cout << ans << endl;\n\
    }\n"
  dependsOn:
  - lib/number/modint.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/modint/modint.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/modint/modint.test.cpp
layout: document
redirect_from:
- /verify/test/number/modint/modint.test.cpp
- /verify/test/number/modint/modint.test.cpp.html
title: test/number/modint/modint.test.cpp
---
