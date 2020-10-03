---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/parse/expression.cpp
    title: lib/parse/expression.cpp
  - icon: ':heavy_check_mark:'
    path: lib/parse/parser.cpp
    title: lib/parse/parser.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109
  bundledCode: "#line 1 \"test/parse/expression/expression.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109\"\n\n#line 1\
    \ \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    // type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/parse/parser.cpp\"\n\nusing State = string::const_iterator;\n\
    class ParseError {};\n#line 2 \"lib/parse/expression.cpp\"\n\nint number(State&\
    \ begin) {\n    int ret = 0;\n    while ('0' <= *begin and *begin <= '9') {\n\
    \        ret *= 10;\n        ret += *begin - '0';\n        ++begin;\n    }\n \
    \   return ret;\n}\n\nint expression(State& begin);\n\nint factor(State& begin)\
    \ {\n    if (*begin == '(') {\n        ++begin;\n        int ret = expression(begin);\n\
    \        if (*begin != ')') {\n            throw ParseError();\n        }\n  \
    \      ++begin;\n        return ret;\n    } else {\n        return number(begin);\n\
    \    }\n}\n\nint term(State& begin) {\n    int prod = factor(begin);\n    while\
    \ (true) {\n        if (*begin == '*') {\n            ++begin;\n            prod\
    \ *= factor(begin);\n        }\n        else if (*begin == '/') {\n          \
    \  ++begin;\n            prod /= factor(begin);\n        }\n        else {\n \
    \           return prod;\n        }\n    }\n}\n\nint expression(State& begin)\
    \ {\n    int sum = term(begin);\n    while (true) {\n        if (*begin == '+')\
    \ {\n            ++begin;\n            sum += term(begin);\n        } else if\
    \ (*begin == '-') {\n            ++begin;\n            sum -= term(begin);\n \
    \       } else {\n            return sum;\n        }\n    }\n}\n#line 4 \"test/parse/expression/expression.test.cpp\"\
    \n\nint main()\n{\n    int n; cin >> n;\n    while (n--) {\n        string s;\
    \ cin >> s;\n        State begin = s.begin();\n        cout << expression(begin)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109\"\
    \n\n#include \"../../../lib/parse/expression.cpp\"\n\nint main()\n{\n    int n;\
    \ cin >> n;\n    while (n--) {\n        string s; cin >> s;\n        State begin\
    \ = s.begin();\n        cout << expression(begin) << endl;\n    }\n}\n"
  dependsOn:
  - lib/parse/expression.cpp
  - lib/parse/parser.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/parse/expression/expression.test.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/parse/expression/expression.test.cpp
layout: document
redirect_from:
- /verify/test/parse/expression/expression.test.cpp
- /verify/test/parse/expression/expression.test.cpp.html
title: test/parse/expression/expression.test.cpp
---
