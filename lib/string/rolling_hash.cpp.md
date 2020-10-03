---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash/rolling_hash.test.cpp
    title: test/string/rolling_hash/rolling_hash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
    // }}}\n\n\n// macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define\
    \ RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a);\
    \ i<(n); ++i)\n#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define\
    \ SZ(x) ((int)(x).size())\n#define all(x) begin(x),end(x)\n// }}}\n\n\n// debug\
    \ {{{\n#define dump(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\"\
    \ = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<< endl;\n\ntemplate<typename T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"[\";\n    REP (i,\
    \ SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n    }\n    return\
    \ os << \"]\";\n}\n\ntemplate<typename T, typename U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    return os << \"(\" << p.first << \" \" << p.second\
    \ << \")\";\n}\n// }}}\n\n\n// chmax, chmin {{{\ntemplate<class T>\nbool chmax(T&\
    \ a, const T& b) {\n    if (a < b) { a = b; return true; }\n    return false;\n\
    }\ntemplate<class T>\nbool chmin(T& a, const T& b) {\n    if (b < a) { a = b;\
    \ return true; }\n    return false;\n}\n// }}}\n\n\n// constants {{{\n#define\
    \ inf(T) (numeric_limits<T>::max() / 2)\nconst ll MOD = 1e9+7;\nconst ld EPS =\
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/string/rolling_hash.cpp\"\n\nstruct RollingHash\
    \ {\n    using uint = uint64_t;\n    vector<uint> hash, pow;\n    static const\
    \ uint MASK30 = (1LL<<30)-1,\n                      MASK31 = (1LL<<31)-1,\n  \
    \                    MASK61 = (1LL<<61)-1;\n\n    template<typename S>\n    RollingHash(const\
    \ S& s, uint base) {\n        int n = s.size();\n        hash.assign(n+1, 0);\n\
    \        pow.assign(n+1, 1);\n        for (int i = 0; i < n; ++i) {\n        \
    \    hash[i+1] = _mod(_mul(hash[i], base) + s[i]);\n            pow[i+1] = _mul(pow[i],\
    \ base);\n        }\n    }\n\n    uint get(int l, int r) const {\n        return\
    \ _mod(hash[r] + MASK61 - _mul(hash[l], pow[r - l]));\n    }\n\n    static uint\
    \ _mul(uint a, uint b) {\n        uint au = a >> 31, ad = a & MASK31,\n      \
    \       bu = b >> 31, bd = b & MASK31;\n        uint m = au * bd + ad * bu;\n\
    \        uint mu = m >> 30, md = m & MASK30;\n\n        return _mod(au*bu*2 +\
    \ mu + (md<<31) + ad*bd);\n    }\n\n    static uint _mod(uint x) {\n        uint\
    \ xu = x >> 61, xd = x & MASK61;\n        uint ret = xu + xd;\n        if (ret\
    \ >= MASK61) ret -= MASK61;\n        return ret;\n    }\n\n    static uint gen_base()\
    \ {\n        mt19937 random{random_device{}()};\n        uniform_int_distribution<uint>\
    \ dist(2, MASK61-2);\n        return dist(random);\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct RollingHash {\n    using uint = uint64_t;\n\
    \    vector<uint> hash, pow;\n    static const uint MASK30 = (1LL<<30)-1,\n  \
    \                    MASK31 = (1LL<<31)-1,\n                      MASK61 = (1LL<<61)-1;\n\
    \n    template<typename S>\n    RollingHash(const S& s, uint base) {\n       \
    \ int n = s.size();\n        hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n\
    \        for (int i = 0; i < n; ++i) {\n            hash[i+1] = _mod(_mul(hash[i],\
    \ base) + s[i]);\n            pow[i+1] = _mul(pow[i], base);\n        }\n    }\n\
    \n    uint get(int l, int r) const {\n        return _mod(hash[r] + MASK61 - _mul(hash[l],\
    \ pow[r - l]));\n    }\n\n    static uint _mul(uint a, uint b) {\n        uint\
    \ au = a >> 31, ad = a & MASK31,\n             bu = b >> 31, bd = b & MASK31;\n\
    \        uint m = au * bd + ad * bu;\n        uint mu = m >> 30, md = m & MASK30;\n\
    \n        return _mod(au*bu*2 + mu + (md<<31) + ad*bd);\n    }\n\n    static uint\
    \ _mod(uint x) {\n        uint xu = x >> 61, xd = x & MASK61;\n        uint ret\
    \ = xu + xd;\n        if (ret >= MASK61) ret -= MASK61;\n        return ret;\n\
    \    }\n\n    static uint gen_base() {\n        mt19937 random{random_device{}()};\n\
    \        uniform_int_distribution<uint> dist(2, MASK61-2);\n        return dist(random);\n\
    \    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2020-07-19 03:06:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash/rolling_hash.test.cpp
documentation_of: lib/string/rolling_hash.cpp
layout: document
redirect_from:
- /library/lib/string/rolling_hash.cpp
- /library/lib/string/rolling_hash.cpp.html
title: lib/string/rolling_hash.cpp
---
