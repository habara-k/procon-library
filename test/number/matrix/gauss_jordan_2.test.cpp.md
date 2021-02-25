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
    ERROR: 1e-8
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
  bundledCode: "#line 1 \"test/number/matrix/gauss_jordan_2.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\n#define ERROR\
    \ \"1e-8\"\n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x)\
    \ begin(x),end(x)\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios\
    \ {\n    fast_ios() {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll\
    \ = long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) {\
    \ a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T\
    \ &a, T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\n\
    template<class T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
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
    \  res[col] = M[row][n];\n    }\n    return res;\n}\n#line 5 \"test/number/matrix/gauss_jordan_2.test.cpp\"\
    \n\nint main() {\n    cout << fixed << setprecision(10);\n    while (true) {\n\
    \        int n, s, t; cin >> n >> s >> t;\n        --s, --t;\n        if (n ==\
    \ 0) break;\n        vector<int> q(n); REP(i, n) cin >> q[i];\n        vector<vector<int>>\
    \ a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j];\n\n        vector<int>\
    \ dist(n, INF), cand(n, 1);\n        dist[t] = 0;\n\n        REP(i, n) {\n   \
    \         int mi = -1, min_dist = INF;\n            REP(u, n) {\n            \
    \    if (cand[u]) {\n                    if (chmin(min_dist, dist[u])) mi = u;\n\
    \                }\n            }\n            cand[mi] = 0;\n            REP(v,\
    \ n) {\n                if (a[mi][v] == 0) continue;\n                chmin(dist[v],\
    \ dist[mi] + a[mi][v]);\n            }\n        }\n\n        if (dist[s] == INF)\
    \ {\n            cout << \"impossible\" << endl;\n            continue;\n    \
    \    }\n\n\n        Matrix<double> A(n);\n        vector<double> b(n);\n     \
    \   REP(u, n) {\n            if (u == t) {\n                A[u][u] = 1;\n   \
    \             continue;\n            }\n            vector<int> neighbors;\n \
    \           REP(v, n) {\n                if (a[u][v] == 0) continue;\n       \
    \         if (q[u] == 1 and dist[u] != dist[v] + a[u][v]) continue;\n        \
    \        neighbors.emplace_back(v);\n            }\n            for (int v : neighbors)\
    \ {\n                A[u][v] -= 1;\n                b[u] += a[u][v];\n       \
    \     }\n            A[u][u] += neighbors.size();\n        }\n\n        auto res\
    \ = linear_equation<double>(A, b, [](double x){ return abs(x); }, 1e-9);\n   \
    \     cout << res[s] << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\
    \n#define ERROR \"1e-8\"\n\n#include \"../../../lib/number/matrix.cpp\"\n\nint\
    \ main() {\n    cout << fixed << setprecision(10);\n    while (true) {\n     \
    \   int n, s, t; cin >> n >> s >> t;\n        --s, --t;\n        if (n == 0) break;\n\
    \        vector<int> q(n); REP(i, n) cin >> q[i];\n        vector<vector<int>>\
    \ a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j];\n\n        vector<int>\
    \ dist(n, INF), cand(n, 1);\n        dist[t] = 0;\n\n        REP(i, n) {\n   \
    \         int mi = -1, min_dist = INF;\n            REP(u, n) {\n            \
    \    if (cand[u]) {\n                    if (chmin(min_dist, dist[u])) mi = u;\n\
    \                }\n            }\n            cand[mi] = 0;\n            REP(v,\
    \ n) {\n                if (a[mi][v] == 0) continue;\n                chmin(dist[v],\
    \ dist[mi] + a[mi][v]);\n            }\n        }\n\n        if (dist[s] == INF)\
    \ {\n            cout << \"impossible\" << endl;\n            continue;\n    \
    \    }\n\n\n        Matrix<double> A(n);\n        vector<double> b(n);\n     \
    \   REP(u, n) {\n            if (u == t) {\n                A[u][u] = 1;\n   \
    \             continue;\n            }\n            vector<int> neighbors;\n \
    \           REP(v, n) {\n                if (a[u][v] == 0) continue;\n       \
    \         if (q[u] == 1 and dist[u] != dist[v] + a[u][v]) continue;\n        \
    \        neighbors.emplace_back(v);\n            }\n            for (int v : neighbors)\
    \ {\n                A[u][v] -= 1;\n                b[u] += a[u][v];\n       \
    \     }\n            A[u][u] += neighbors.size();\n        }\n\n        auto res\
    \ = linear_equation<double>(A, b, [](double x){ return abs(x); }, 1e-9);\n   \
    \     cout << res[s] << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/number/matrix.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/matrix/gauss_jordan_2.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/matrix/gauss_jordan_2.test.cpp
layout: document
redirect_from:
- /verify/test/number/matrix/gauss_jordan_2.test.cpp
- /verify/test/number/matrix/gauss_jordan_2.test.cpp.html
title: test/number/matrix/gauss_jordan_2.test.cpp
---
