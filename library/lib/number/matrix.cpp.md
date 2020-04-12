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
    - Last commit date: 2020-04-12 12:38:19+09:00




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

    inline const vector<T> &operator[](int k) const {
        return (A.at(k));
    }

    inline vector<T> &operator[](int k) {
        return (A.at(k));
    }

    static Matrix I(size_t n) {
        Matrix B(n);
        for (int i = 0; i < n; i++) B[i][i] = 1;
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
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
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
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] += A[i][k] * B[k][j];
        A.swap(C.A);
        return (*this);
    }

    Matrix pow(int64_t k) {
        Matrix B = Matrix::I(height()), tmp = *this;
        while (k > 0) {
            if (k & 1) B *= tmp;
            tmp *= tmp;
            k >>= 1LL;
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
        for(int i = 0; i < n; i++) {
            os << (i == 0 ? "[" : " ");
            for(int j = 0; j < m; j++) {
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

// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a, make_vector<T>(b, ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) is >> e;
    return is;
}

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge() {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

using LL = int64_t;

#define fs first
#define sc second

const int64_t MOD = 1e9+7;

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

    inline const vector<T> &operator[](int k) const {
        return (A.at(k));
    }

    inline vector<T> &operator[](int k) {
        return (A.at(k));
    }

    static Matrix I(size_t n) {
        Matrix B(n);
        for (int i = 0; i < n; i++) B[i][i] = 1;
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
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
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
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] += A[i][k] * B[k][j];
        A.swap(C.A);
        return (*this);
    }

    Matrix pow(int64_t k) {
        Matrix B = Matrix::I(height()), tmp = *this;
        while (k > 0) {
            if (k & 1) B *= tmp;
            tmp *= tmp;
            k >>= 1LL;
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
        for(int i = 0; i < n; i++) {
            os << (i == 0 ? "[" : " ");
            for(int j = 0; j < m; j++) {
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

