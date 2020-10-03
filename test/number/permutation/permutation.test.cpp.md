---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/permutation.cpp
    title: lib/number/permutation.cpp
  - icon: ':heavy_check_mark:'
    path: lib/parse/parser.cpp
    title: lib/parse/parser.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731
  bundledCode: "#line 1 \"test/number/permutation/permutation.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731\"\n\n\
    #line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
    \ = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing vll\
    \ = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/permutation.cpp\"\n\nstruct Permutation\
    \ {\n    vector<int> perm;\n    Permutation() {}\n    Permutation(int sz) : perm(sz)\
    \ {\n        iota(perm.begin(), perm.end(), 0);\n    }\n    Permutation(initializer_list<int>\
    \ init) : perm(init.begin(), init.end()) {}\n    size_t size() const {\n     \
    \   return (perm.size());\n    }\n    inline int operator [](int k) const {\n\
    \        return (perm.at(k));\n    }\n    inline int& operator [](int k) {\n \
    \       return (perm.at(k));\n    }\n    Permutation& operator*=(const Permutation&\
    \ rhs) {\n        assert(size() == rhs.size());\n        Permutation tmp(size());\n\
    \        for (int i = 0; i < size(); ++i) {\n            tmp[i] = perm[rhs[i]];\n\
    \        }\n        perm.swap(tmp.perm);\n        return (*this);\n    }\n   \
    \ const Permutation operator*(const Permutation& rhs) const {\n        return\
    \ (Permutation(*this) *= rhs);\n    }\n    Permutation pow(int64_t k) {\n    \
    \    Permutation ret(size()), tmp = *this;\n        while (k) {\n            if\
    \ (k & 1) ret *= tmp;\n            tmp *= tmp; k >>= 1;\n        }\n        return\
    \ (ret);\n    }\n};\n#line 2 \"lib/parse/parser.cpp\"\n\nusing State = string::const_iterator;\n\
    class ParseError {};\n#line 5 \"test/number/permutation/permutation.test.cpp\"\
    \n\nint N, L;\nstring S;\n\nint number(State& begin) {\n    int ret = 0;\n   \
    \ while ('0' <= *begin and *begin <= '9') {\n        ret *= 10;\n        ret +=\
    \ *begin - '0';\n        ++begin;\n    }\n    return ret;\n}\n\n\nPermutation\
    \ operation(State& begin) {\n    char ch = *begin;\n    int num = number(++begin)\
    \ - 1;\n    Permutation ord(N*N);\n    if (ch == 'R') {\n        int buff = ord[N-1\
    \ + num*N];\n        for (int i = N-1; i > 0; --i) {\n            ord[i + num*N]\
    \ = ord[i-1 + num*N];\n        }\n        ord[num*N] = buff;\n    }\n    if (ch\
    \ == 'L') {\n        int buff = ord[0 + num*N];\n        for (int i = 0; i < N-1;\
    \ ++i) {\n            ord[i + num*N] = ord[i+1 + num*N];\n        }\n        ord[N-1\
    \ + num*N] = buff;\n    }\n    if (ch == 'D') {\n        int buff = ord[num +\
    \ (N-1)*N];\n        for (int i = N-1; i > 0; --i) {\n            ord[num + i*N]\
    \ = ord[num + (i-1)*N];\n        }\n        ord[num] = buff;\n    }\n    if (ch\
    \ == 'U') {\n        int buff = ord[num];\n        for (int i = 0; i < N-1; ++i)\
    \ {\n            ord[num + i*N] = ord[num + (i+1)*N];\n        }\n        ord[num\
    \ + (N-1)*N] = buff;\n    }\n    return ord;\n}\n\nPermutation sequence(State&\
    \ begin);\n\nPermutation repetition(State& begin) {\n    assert(*begin == '(');\n\
    \    Permutation ret = sequence(++begin);\n    assert(*begin == ')');\n    int\
    \ num = number(++begin);\n    return ret.pow(num);\n}\n\nPermutation rep_or_op(State&\
    \ begin) {\n    if (*begin == '(') {\n        return repetition(begin);\n    }\
    \ else {\n        return operation(begin);\n    }\n}\n\nPermutation sequence(State&\
    \ begin) {\n    Permutation ret = rep_or_op(begin);\n    while (*begin != ')'\
    \ and *begin != '\\0') {\n        ret = ret * rep_or_op(begin);\n    }\n    return\
    \ ret;\n}\n\n\nint main()\n{\n    cin >> N >> L >> S;\n    State begin = S.begin();\n\
    \n    Permutation perm = sequence(begin);\n    for (int i = 0; i < N; ++i) {\n\
    \        for (int j = 0; j < N; ++j) {\n            if (j) cout << \" \";\n  \
    \          cout << perm[i*N + j] + 1;\n        }\n        cout << endl;\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731\"\
    \n\n#include \"../../../lib/number/permutation.cpp\"\n#include \"../../../lib/parse/parser.cpp\"\
    \n\nint N, L;\nstring S;\n\nint number(State& begin) {\n    int ret = 0;\n   \
    \ while ('0' <= *begin and *begin <= '9') {\n        ret *= 10;\n        ret +=\
    \ *begin - '0';\n        ++begin;\n    }\n    return ret;\n}\n\n\nPermutation\
    \ operation(State& begin) {\n    char ch = *begin;\n    int num = number(++begin)\
    \ - 1;\n    Permutation ord(N*N);\n    if (ch == 'R') {\n        int buff = ord[N-1\
    \ + num*N];\n        for (int i = N-1; i > 0; --i) {\n            ord[i + num*N]\
    \ = ord[i-1 + num*N];\n        }\n        ord[num*N] = buff;\n    }\n    if (ch\
    \ == 'L') {\n        int buff = ord[0 + num*N];\n        for (int i = 0; i < N-1;\
    \ ++i) {\n            ord[i + num*N] = ord[i+1 + num*N];\n        }\n        ord[N-1\
    \ + num*N] = buff;\n    }\n    if (ch == 'D') {\n        int buff = ord[num +\
    \ (N-1)*N];\n        for (int i = N-1; i > 0; --i) {\n            ord[num + i*N]\
    \ = ord[num + (i-1)*N];\n        }\n        ord[num] = buff;\n    }\n    if (ch\
    \ == 'U') {\n        int buff = ord[num];\n        for (int i = 0; i < N-1; ++i)\
    \ {\n            ord[num + i*N] = ord[num + (i+1)*N];\n        }\n        ord[num\
    \ + (N-1)*N] = buff;\n    }\n    return ord;\n}\n\nPermutation sequence(State&\
    \ begin);\n\nPermutation repetition(State& begin) {\n    assert(*begin == '(');\n\
    \    Permutation ret = sequence(++begin);\n    assert(*begin == ')');\n    int\
    \ num = number(++begin);\n    return ret.pow(num);\n}\n\nPermutation rep_or_op(State&\
    \ begin) {\n    if (*begin == '(') {\n        return repetition(begin);\n    }\
    \ else {\n        return operation(begin);\n    }\n}\n\nPermutation sequence(State&\
    \ begin) {\n    Permutation ret = rep_or_op(begin);\n    while (*begin != ')'\
    \ and *begin != '\\0') {\n        ret = ret * rep_or_op(begin);\n    }\n    return\
    \ ret;\n}\n\n\nint main()\n{\n    cin >> N >> L >> S;\n    State begin = S.begin();\n\
    \n    Permutation perm = sequence(begin);\n    for (int i = 0; i < N; ++i) {\n\
    \        for (int j = 0; j < N; ++j) {\n            if (j) cout << \" \";\n  \
    \          cout << perm[i*N + j] + 1;\n        }\n        cout << endl;\n    }\n\
    \n    return 0;\n}\n"
  dependsOn:
  - lib/number/permutation.cpp
  - lib/template.cpp
  - lib/parse/parser.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/permutation/permutation.test.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/permutation/permutation.test.cpp
layout: document
redirect_from:
- /verify/test/number/permutation/permutation.test.cpp
- /verify/test/number/permutation/permutation.test.cpp.html
title: test/number/permutation/permutation.test.cpp
---
