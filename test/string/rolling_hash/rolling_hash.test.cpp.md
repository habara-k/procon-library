---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/rolling_hash.cpp
    title: lib/string/rolling_hash.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/string/rolling_hash/rolling_hash.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/string/rolling_hash.cpp\"\n\nstruct RollingHash\
    \ {\n    using u64 = uint64_t;\n    using i128 = __int128_t;\n\n    template<typename\
    \ S>\n    RollingHash(const S &s, u64 base) {\n        int n = s.size();\n   \
    \     hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n        for (int i =\
    \ 0; i < n; ++i) {\n            hash[i+1] = mul(hash[i], base) + s[i];\n     \
    \       if (hash[i+1] >= MOD) hash[i+1] -= MOD;\n            pow[i+1] = mul(pow[i],\
    \ base);\n        }\n    }\n\n    u64 get(int l, int r) const {\n        u64 ret\
    \ = hash[r] + MOD - mul(hash[l], pow[r-l]);\n        return ret >= MOD ? ret -\
    \ MOD : ret;\n    }\n\n    static u64 gen_base() {\n        mt19937 random{random_device{}()};\n\
    \        uniform_int_distribution<u64> dist(2, MOD-2);\n        return dist(random);\n\
    \    }\n\nprivate:\n    vector<u64> hash, pow;\n    static const u64 MOD = (1ul\
    \ << 61) - 1;\n\n    static u64 mul(i128 a, i128 b) {\n        i128 t = a * b;\n\
    \        t = (t >> 61) + (t & MOD);\n        if (t >= MOD) t -= MOD;\n       \
    \ return t;\n    }\n};\n#line 4 \"test/string/rolling_hash/rolling_hash.test.cpp\"\
    \n\nint main() {\n    string T, P;\n    cin >> T >> P;\n    int n = T.size(),\
    \ m = P.size();\n\n    int64_t base = RollingHash::gen_base();\n\n    RollingHash\
    \ rht(T, base);\n    RollingHash rhp(P, base);\n\n    for (int i = 0; i+m <= n;\
    \ ++i) {\n        if (rht.get(i, i+m) == rhp.get(0, m)) {\n            cout <<\
    \ i << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../../../lib/string/rolling_hash.cpp\"\n\nint main() {\n    string\
    \ T, P;\n    cin >> T >> P;\n    int n = T.size(), m = P.size();\n\n    int64_t\
    \ base = RollingHash::gen_base();\n\n    RollingHash rht(T, base);\n    RollingHash\
    \ rhp(P, base);\n\n    for (int i = 0; i+m <= n; ++i) {\n        if (rht.get(i,\
    \ i+m) == rhp.get(0, m)) {\n            cout << i << endl;\n        }\n    }\n\
    }\n"
  dependsOn:
  - lib/string/rolling_hash.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/string/rolling_hash/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/rolling_hash/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash/rolling_hash.test.cpp
- /verify/test/string/rolling_hash/rolling_hash.test.cpp.html
title: test/string/rolling_hash/rolling_hash.test.cpp
---
