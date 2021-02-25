---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/matrix.cpp
    title: lib/number/matrix.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328
  bundledCode: "#line 1 \"test/number/matrix/gauss_jordan.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328\"\n\n#line 1\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/matrix.cpp\"\n\ntemplate<typename\
    \ T>\nstruct Matrix {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n    Matrix(int\
    \ m, int n) : A(m, vector<T>(n)) {}\n\n    Matrix(int n) : A(n, vector<T>(n))\
    \ {};\n\n    int height() const {\n        return A.size();\n    }\n\n    int\
    \ width() const {\n        return A[0].size();\n    }\n\n    inline const vector<T>&\
    \ operator[](int k) const {\n        return A.at(k);\n    }\n\n    inline vector<T>&\
    \ operator[](int k) {\n        return A.at(k);\n    }\n\n    static Matrix I(size_t\
    \ n) {\n        Matrix ret(n);\n        for (int i = 0; i < n; ++i) ret[i][i]\
    \ = 1;\n        return ret;\n    }\n\n    Matrix operator-() const {\n       \
    \ size_t m = height(), n = width();\n        Matrix ret = *this;\n        for\
    \ (int i = 0; i < m; ++i)\n            for (int j = 0; j < n; ++j)\n         \
    \       ret[i][j] = -ret[i][j];\n        return ret;\n    }\n\n    Matrix& operator+=(const\
    \ Matrix& B) {\n        size_t m = height(), n = width();\n        assert(m ==\
    \ B.height() and n == B.width());\n        for (int i = 0; i < m; ++i)\n     \
    \       for (int j = 0; j < n; ++j)\n                A[i][j] += B[i][j];\n   \
    \     return *this;\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n    \
    \    return *this += -B;\n    }\n\n    Matrix& operator*=(const Matrix& B) {\n\
    \        size_t m = height(), n = B.width(), p = width();\n        assert(p ==\
    \ B.height());\n        Matrix C(m, n);\n        for (int i = 0; i < m; ++i)\n\
    \            for (int j = 0; j < n; ++j)\n                for (int k = 0; k <\
    \ p; ++k)\n                    C[i][j] += A[i][k] * B[k][j];\n        A.swap(C.A);\n\
    \        return *this;\n    }\n\n    Matrix pow(ll k) {\n        assert(height()\
    \ == width());\n        Matrix ret = Matrix::I(height()), tmp = *this;\n     \
    \   while (k) {\n            if (k & 1) ret *= tmp;\n            tmp *= tmp; k\
    \ >>= 1;\n        }\n        return ret;\n    }\n\n    const Matrix operator+(const\
    \ Matrix& B) const {\n        return (Matrix(*this) += B);\n    }\n\n    const\
    \ Matrix operator-(const Matrix& B) const {\n        return (Matrix(*this) -=\
    \ B);\n    }\n\n    const Matrix operator*(const Matrix& B) const {\n        return\
    \ (Matrix(*this) *= B);\n    }\n\n    int GaussJordanElimination(function<double(T)>\
    \ Abs, double eps, bool extended = false) {\n        int m = height(), n = width();\n\
    \        int rank = 0;\n        for (int col = 0; col < n; ++col) {\n        \
    \    if (extended and col == n-1) break;\n            int pivot = -1;\n      \
    \      for (int row = rank; row < height(); ++row) {\n                if (Abs(A[row][col])\
    \ < eps) continue;\n                if (pivot == -1 or Abs(A[row][col]) > Abs(A[pivot][col]))\
    \ {\n                    pivot = row;\n                }\n            }\n    \
    \        if (pivot == -1) continue;\n            swap(A[rank], A[pivot]);\n  \
    \          T topLeft = A[rank][col];\n            for (int c = col; c < width();\
    \ ++c) {\n                A[rank][c] /= topLeft;\n            }\n            for\
    \ (int row = 0; row < m; ++row) {\n                if (row == rank or Abs(A[row][col])\
    \ < eps) continue;\n                T ratio = A[row][col];\n                for\
    \ (int c = col; c < width(); ++c)\n                    A[row][c] -= ratio * A[rank][c];\n\
    \            }\n            ++rank;\n        }\n        return rank;\n    }\n\n\
    \    friend istream& operator>>(istream& is, Matrix& mat) {\n        is >> mat.A;\n\
    \        return (is);\n    }\n\n    friend ostream& operator<<(ostream& os, Matrix&\
    \ mat) {\n        size_t n = mat.height(), m = mat.width();\n        for (int\
    \ i = 0; i < n; ++i) {\n            os << (i == 0 ? \"[\" : \" \");\n        \
    \    for (int j = 0; j < m; ++j) {\n                os << mat[i][j] << (j == m-1\
    \ ? \"]\" : \",\");\n            }\n            os << (i == n-1 ? \"]\\n\" : \"\
    ,\\n\");\n        }\n        return (os);\n    }\n};\n\n\ntemplate<class T>\n\
    vector<T> linear_equation(Matrix<T> A, vector<T> b, function<double(T)> Abs, double\
    \ eps) {\n    // extended\n    int m = A.height(), n = A.width();\n    Matrix<T>\
    \ M(m, n + 1);\n    for (int i = 0; i < m; ++i) {\n        for (int j = 0; j <\
    \ n; ++j) M[i][j] = A[i][j];\n        M[i][n] = b[i];\n    }\n    int rank = M.GaussJordanElimination(Abs,\
    \ eps, true);\n\n    // check if it has no solution\n    vector<T> res;\n    for\
    \ (int row = rank; row < m; ++row) if (Abs(M[row][n]) > eps) return res;\n\n \
    \   // answer\n    res.assign(n, 0);\n    int col = 0;\n    for (int row = 0;\
    \ row < rank; ++row) {\n        while (Abs(M[row][col]) < eps) ++col;\n      \
    \  res[col] = M[row][n];\n    }\n    return res;\n}\n#line 4 \"test/number/matrix/gauss_jordan.test.cpp\"\
    \n\nint main() {\n    while (true) {\n        int d; cin >> d;\n        if (d\
    \ == 0) break;\n\n        vector<double> f(d+3);\n        REP(i, d+3) cin >> f[i];\n\
    \n        REP(i, d+3) {\n            int cnt = 0;\n            Matrix<double>\
    \ A(d+2, d+1);\n            vector<double> b(d+2);\n            REP(j, d+3) {\n\
    \                if (j == i) continue;\n                double p = 1.0;\n    \
    \            REP(k, d+1) {\n                    A[cnt][k] = p;\n             \
    \       p *= j;\n                }\n                b[cnt] = f[j];\n         \
    \       ++cnt;\n            }\n            auto res = linear_equation<double>(A,\
    \ b, [](double x){ return abs(x); }, 1e-5);\n            if (!res.empty()) {\n\
    \                cout << i << endl;\n                break;\n            }\n \
    \       }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328\"\
    \n\n#include \"../../../lib/number/matrix.cpp\"\n\nint main() {\n    while (true)\
    \ {\n        int d; cin >> d;\n        if (d == 0) break;\n\n        vector<double>\
    \ f(d+3);\n        REP(i, d+3) cin >> f[i];\n\n        REP(i, d+3) {\n       \
    \     int cnt = 0;\n            Matrix<double> A(d+2, d+1);\n            vector<double>\
    \ b(d+2);\n            REP(j, d+3) {\n                if (j == i) continue;\n\
    \                double p = 1.0;\n                REP(k, d+1) {\n            \
    \        A[cnt][k] = p;\n                    p *= j;\n                }\n    \
    \            b[cnt] = f[j];\n                ++cnt;\n            }\n         \
    \   auto res = linear_equation<double>(A, b, [](double x){ return abs(x); }, 1e-5);\n\
    \            if (!res.empty()) {\n                cout << i << endl;\n       \
    \         break;\n            }\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/number/matrix.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/matrix/gauss_jordan.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/matrix/gauss_jordan.test.cpp
layout: document
redirect_from:
- /verify/test/number/matrix/gauss_jordan.test.cpp
- /verify/test/number/matrix/gauss_jordan.test.cpp.html
title: test/number/matrix/gauss_jordan.test.cpp
---
