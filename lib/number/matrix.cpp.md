---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/matrix.cpp\"\n\ntemplate<typename T>\n\
    struct Matrix {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n    Matrix(size_t\
    \ n, size_t m) : A(n, vector<T>(m)) {}\n\n    Matrix(size_t n) : A(n, vector<T>(n))\
    \ {};\n\n    size_t height() const {\n        return (A.size());\n    }\n\n  \
    \  size_t width() const {\n        return (A[0].size());\n    }\n\n    inline\
    \ const vector<T>& operator[](int k) const {\n        return (A.at(k));\n    }\n\
    \n    inline vector<T>& operator[](int k) {\n        return (A.at(k));\n    }\n\
    \n    static Matrix I(size_t n) {\n        Matrix B(n);\n        for (int i =\
    \ 0; i < n; ++i) B[i][i] = 1;\n        return (B);\n    }\n\n    Matrix operator-()\
    \ const {\n        size_t n = height(), m = width();\n        Matrix B = *this;\n\
    \        for (int i = 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n\
    \                B[i][j] = -B[i][j];\n        return (B);\n    }\n\n    Matrix&\
    \ operator+=(const Matrix& B) {\n        size_t n = height(), m = width();\n \
    \       assert(n == B.height() and m == B.width());\n        for (int i = 0; i\
    \ < n; ++i)\n            for (int j = 0; j < m; ++j)\n                A[i][j]\
    \ += B[i][j];\n        return (*this);\n    }\n\n    Matrix& operator-=(const\
    \ Matrix& B) {\n        return (*this += -B);\n    }\n\n    Matrix& operator*=(const\
    \ Matrix& B) {\n        size_t n = height(), m = B.width(), p = width();\n   \
    \     assert(p == B.height());\n        Matrix C(n, m);\n        for (int i =\
    \ 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n                for\
    \ (int k = 0; k < p; ++k)\n                    C[i][j] += A[i][k] * B[k][j];\n\
    \        A.swap(C.A);\n        return (*this);\n    }\n\n    Matrix pow(int64_t\
    \ k) {\n        Matrix B = Matrix::I(height()), tmp = *this;\n        while (k)\
    \ {\n            if (k & 1) B *= tmp;\n            tmp *= tmp; k >>= 1;\n    \
    \    }\n        return (B);\n    }\n\n    const Matrix operator+(const Matrix&\
    \ B) const {\n        return (Matrix(*this) += B);\n    }\n\n    const Matrix\
    \ operator-(const Matrix& B) const {\n        return (Matrix(*this) -= B);\n \
    \   }\n\n    const Matrix operator*(const Matrix& B) const {\n        return (Matrix(*this)\
    \ *= B);\n    }\n\n    int GaussJordanElimination() {\n        int rank = 0;\n\
    \        for (int col = 0; col < width(); ++col) {\n            int pivot = -1;\n\
    \            for (int row = rank; row < height(); ++row) {\n                if\
    \ (A[row][col] != 0) {\n                    pivot = row;\n                   \
    \ break;\n                }\n            }\n            if (pivot == -1) continue;\n\
    \            swap(A[rank], A[pivot]);\n            T topLeft = A[rank][col];\n\
    \            for (int c = col; c < width(); ++c) {\n                A[rank][c]\
    \ /= topLeft;\n            }\n            for (int row = rank+1; row < height();\
    \ ++row) {\n                T ratio = A[row][col];\n                for (int c\
    \ = col; c < width(); ++c)\n                    A[row][c] -= ratio * A[rank][c];\n\
    \            }\n            ++rank;\n        }\n        return (rank);\n    }\n\
    \n    friend istream& operator>>(istream& is, Matrix& B) {\n        is >> B.A;\n\
    \        return (is);\n    }\n\n    friend ostream& operator<<(ostream& os, Matrix&\
    \ B) {\n        size_t n = B.height(), m = B.width();\n        for (int i = 0;\
    \ i < n; ++i) {\n            os << (i == 0 ? \"[\" : \" \");\n            for\
    \ (int j = 0; j < m; ++j) {\n                os << B[i][j] << (j == m-1 ? \"]\"\
    \ : \",\");\n            }\n            os << (i == n-1 ? \"]\\n\" : \",\\n\"\
    );\n        }\n        return (os);\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename T>\nstruct Matrix {\n \
    \   vector<vector<T>> A;\n\n    Matrix() {}\n\n    Matrix(size_t n, size_t m)\
    \ : A(n, vector<T>(m)) {}\n\n    Matrix(size_t n) : A(n, vector<T>(n)) {};\n\n\
    \    size_t height() const {\n        return (A.size());\n    }\n\n    size_t\
    \ width() const {\n        return (A[0].size());\n    }\n\n    inline const vector<T>&\
    \ operator[](int k) const {\n        return (A.at(k));\n    }\n\n    inline vector<T>&\
    \ operator[](int k) {\n        return (A.at(k));\n    }\n\n    static Matrix I(size_t\
    \ n) {\n        Matrix B(n);\n        for (int i = 0; i < n; ++i) B[i][i] = 1;\n\
    \        return (B);\n    }\n\n    Matrix operator-() const {\n        size_t\
    \ n = height(), m = width();\n        Matrix B = *this;\n        for (int i =\
    \ 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n                B[i][j]\
    \ = -B[i][j];\n        return (B);\n    }\n\n    Matrix& operator+=(const Matrix&\
    \ B) {\n        size_t n = height(), m = width();\n        assert(n == B.height()\
    \ and m == B.width());\n        for (int i = 0; i < n; ++i)\n            for (int\
    \ j = 0; j < m; ++j)\n                A[i][j] += B[i][j];\n        return (*this);\n\
    \    }\n\n    Matrix& operator-=(const Matrix& B) {\n        return (*this +=\
    \ -B);\n    }\n\n    Matrix& operator*=(const Matrix& B) {\n        size_t n =\
    \ height(), m = B.width(), p = width();\n        assert(p == B.height());\n  \
    \      Matrix C(n, m);\n        for (int i = 0; i < n; ++i)\n            for (int\
    \ j = 0; j < m; ++j)\n                for (int k = 0; k < p; ++k)\n          \
    \          C[i][j] += A[i][k] * B[k][j];\n        A.swap(C.A);\n        return\
    \ (*this);\n    }\n\n    Matrix pow(int64_t k) {\n        Matrix B = Matrix::I(height()),\
    \ tmp = *this;\n        while (k) {\n            if (k & 1) B *= tmp;\n      \
    \      tmp *= tmp; k >>= 1;\n        }\n        return (B);\n    }\n\n    const\
    \ Matrix operator+(const Matrix& B) const {\n        return (Matrix(*this) +=\
    \ B);\n    }\n\n    const Matrix operator-(const Matrix& B) const {\n        return\
    \ (Matrix(*this) -= B);\n    }\n\n    const Matrix operator*(const Matrix& B)\
    \ const {\n        return (Matrix(*this) *= B);\n    }\n\n    int GaussJordanElimination()\
    \ {\n        int rank = 0;\n        for (int col = 0; col < width(); ++col) {\n\
    \            int pivot = -1;\n            for (int row = rank; row < height();\
    \ ++row) {\n                if (A[row][col] != 0) {\n                    pivot\
    \ = row;\n                    break;\n                }\n            }\n     \
    \       if (pivot == -1) continue;\n            swap(A[rank], A[pivot]);\n   \
    \         T topLeft = A[rank][col];\n            for (int c = col; c < width();\
    \ ++c) {\n                A[rank][c] /= topLeft;\n            }\n            for\
    \ (int row = rank+1; row < height(); ++row) {\n                T ratio = A[row][col];\n\
    \                for (int c = col; c < width(); ++c)\n                    A[row][c]\
    \ -= ratio * A[rank][c];\n            }\n            ++rank;\n        }\n    \
    \    return (rank);\n    }\n\n    friend istream& operator>>(istream& is, Matrix&\
    \ B) {\n        is >> B.A;\n        return (is);\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, Matrix& B) {\n        size_t n = B.height(), m = B.width();\n\
    \        for (int i = 0; i < n; ++i) {\n            os << (i == 0 ? \"[\" : \"\
    \ \");\n            for (int j = 0; j < m; ++j) {\n                os << B[i][j]\
    \ << (j == m-1 ? \"]\" : \",\");\n            }\n            os << (i == n-1 ?\
    \ \"]\\n\" : \",\\n\");\n        }\n        return (os);\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/matrix.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/matrix.cpp
layout: document
redirect_from:
- /library/lib/number/matrix.cpp
- /library/lib/number/matrix.cpp.html
title: lib/number/matrix.cpp
---
