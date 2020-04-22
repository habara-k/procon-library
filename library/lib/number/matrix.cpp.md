---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/number/matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename T>
struct Matrix {
    vector<vector<T>> A;

    Matrix() {}

    Matrix(size_t n, size_t m) : A(n, vector<T>(m)) {}

    Matrix(size_t n) : A(n, vector<T>(n)) {};

    size_t height() const {
        return (A.size());
    }

    size_t width() const {
        return (A[0].size());
    }

    inline const vector<T>& operator[](int k) const {
        return (A.at(k));
    }

    inline vector<T>& operator[](int k) {
        return (A.at(k));
    }

    static Matrix I(size_t n) {
        Matrix B(n);
        for (int i = 0; i < n; ++i) B[i][i] = 1;
        return (B);
    }

    Matrix operator-() const {
        size_t n = height(), m = width();
        Matrix B = *this;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                B[i][j] = -B[i][j];
        return (B);
    }

    Matrix& operator+=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() and m == B.width());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                A[i][j] += B[i][j];
        return (*this);
    }

    Matrix& operator-=(const Matrix& B) {
        return (*this += -B);
    }

    Matrix& operator*=(const Matrix& B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        Matrix C(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < p; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        A.swap(C.A);
        return (*this);
    }

    Matrix pow(int64_t k) {
        Matrix B = Matrix::I(height()), tmp = *this;
        while (k) {
            if (k & 1) B *= tmp;
            tmp *= tmp; k >>= 1;
        }
        return (B);
    }

    const Matrix operator+(const Matrix& B) const {
        return (Matrix(*this) += B);
    }

    const Matrix operator-(const Matrix& B) const {
        return (Matrix(*this) -= B);
    }

    const Matrix operator*(const Matrix& B) const {
        return (Matrix(*this) *= B);
    }

    int GaussJordanElimination() {
        int rank = 0;
        for (int col = 0; col < width(); ++col) {
            int pivot = -1;
            for (int row = rank; row < height(); ++row) {
                if (A[row][col] != 0) {
                    pivot = row;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(A[rank], A[pivot]);
            T topLeft = A[rank][col];
            for (int c = col; c < width(); ++c) {
                A[rank][c] /= topLeft;
            }
            for (int row = rank+1; row < height(); ++row) {
                T ratio = A[row][col];
                for (int c = col; c < width(); ++c)
                    A[row][c] -= ratio * A[rank][c];
            }
            ++rank;
        }
        return (rank);
    }

    friend istream& operator>>(istream& is, Matrix& B) {
        is >> B.A;
        return (is);
    }

    friend ostream& operator<<(ostream& os, Matrix& B) {
        size_t n = B.height(), m = B.width();
        for (int i = 0; i < n; ++i) {
            os << (i == 0 ? "[" : " ");
            for (int j = 0; j < m; ++j) {
                os << B[i][j] << (j == m-1 ? "]" : ",");
            }
            os << (i == n-1 ? "]\n" : ",\n");
        }
        return (os);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

// type {{{
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
// }}}


// macro {{{
#define REP(i,n) for (int i=0; i<(n); ++i)
#define RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i,a,n) for (int i=(a); i<(n); ++i)
#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)
// }}}


// debug {{{
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    REP (i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}
// }}}


// chmax, chmin {{{
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}
// }}}


// constants {{{
#define inf(T) (numeric_limits<T>::max() / 2)
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
// }}}


#line 2 "lib/number/matrix.cpp"

template<typename T>
struct Matrix {
    vector<vector<T>> A;

    Matrix() {}

    Matrix(size_t n, size_t m) : A(n, vector<T>(m)) {}

    Matrix(size_t n) : A(n, vector<T>(n)) {};

    size_t height() const {
        return (A.size());
    }

    size_t width() const {
        return (A[0].size());
    }

    inline const vector<T>& operator[](int k) const {
        return (A.at(k));
    }

    inline vector<T>& operator[](int k) {
        return (A.at(k));
    }

    static Matrix I(size_t n) {
        Matrix B(n);
        for (int i = 0; i < n; ++i) B[i][i] = 1;
        return (B);
    }

    Matrix operator-() const {
        size_t n = height(), m = width();
        Matrix B = *this;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                B[i][j] = -B[i][j];
        return (B);
    }

    Matrix& operator+=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() and m == B.width());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                A[i][j] += B[i][j];
        return (*this);
    }

    Matrix& operator-=(const Matrix& B) {
        return (*this += -B);
    }

    Matrix& operator*=(const Matrix& B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        Matrix C(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < p; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        A.swap(C.A);
        return (*this);
    }

    Matrix pow(int64_t k) {
        Matrix B = Matrix::I(height()), tmp = *this;
        while (k) {
            if (k & 1) B *= tmp;
            tmp *= tmp; k >>= 1;
        }
        return (B);
    }

    const Matrix operator+(const Matrix& B) const {
        return (Matrix(*this) += B);
    }

    const Matrix operator-(const Matrix& B) const {
        return (Matrix(*this) -= B);
    }

    const Matrix operator*(const Matrix& B) const {
        return (Matrix(*this) *= B);
    }

    int GaussJordanElimination() {
        int rank = 0;
        for (int col = 0; col < width(); ++col) {
            int pivot = -1;
            for (int row = rank; row < height(); ++row) {
                if (A[row][col] != 0) {
                    pivot = row;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(A[rank], A[pivot]);
            T topLeft = A[rank][col];
            for (int c = col; c < width(); ++c) {
                A[rank][c] /= topLeft;
            }
            for (int row = rank+1; row < height(); ++row) {
                T ratio = A[row][col];
                for (int c = col; c < width(); ++c)
                    A[row][c] -= ratio * A[rank][c];
            }
            ++rank;
        }
        return (rank);
    }

    friend istream& operator>>(istream& is, Matrix& B) {
        is >> B.A;
        return (is);
    }

    friend ostream& operator<<(ostream& os, Matrix& B) {
        size_t n = B.height(), m = B.width();
        for (int i = 0; i < n; ++i) {
            os << (i == 0 ? "[" : " ");
            for (int j = 0; j < m; ++j) {
                os << B[i][j] << (j == m-1 ? "]" : ",");
            }
            os << (i == n-1 ? "]\n" : ",\n");
        }
        return (os);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

