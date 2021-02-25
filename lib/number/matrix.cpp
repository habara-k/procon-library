#include "../template.cpp"

template<typename T>
struct Matrix {
    vector<vector<T>> A;

    Matrix() {}

    Matrix(int m, int n) : A(m, vector<T>(n)) {}

    Matrix(int n) : A(n, vector<T>(n)) {};

    int height() const {
        return A.size();
    }

    int width() const {
        return A[0].size();
    }

    inline const vector<T>& operator[](int k) const {
        return A.at(k);
    }

    inline vector<T>& operator[](int k) {
        return A.at(k);
    }

    static Matrix I(size_t n) {
        Matrix ret(n);
        for (int i = 0; i < n; ++i) ret[i][i] = 1;
        return ret;
    }

    Matrix operator-() const {
        size_t m = height(), n = width();
        Matrix ret = *this;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ret[i][j] = -ret[i][j];
        return ret;
    }

    Matrix& operator+=(const Matrix& B) {
        size_t m = height(), n = width();
        assert(m == B.height() and n == B.width());
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] += B[i][j];
        return *this;
    }

    Matrix& operator-=(const Matrix& B) {
        return *this += -B;
    }

    Matrix& operator*=(const Matrix& B) {
        size_t m = height(), n = B.width(), p = width();
        assert(p == B.height());
        Matrix C(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < p; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        A.swap(C.A);
        return *this;
    }

    Matrix pow(ll k) {
        assert(height() == width());
        Matrix ret = Matrix::I(height()), tmp = *this;
        while (k) {
            if (k & 1) ret *= tmp;
            tmp *= tmp; k >>= 1;
        }
        return ret;
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

    int GaussJordanElimination(function<double(T)> Abs, double eps, bool extended = false) {
        int m = height(), n = width();
        int rank = 0;
        for (int col = 0; col < n; ++col) {
            if (extended and col == n-1) break;
            int pivot = -1;
            for (int row = rank; row < height(); ++row) {
                if (Abs(A[row][col]) < eps) continue;
                if (pivot == -1 or Abs(A[row][col]) > Abs(A[pivot][col])) {
                    pivot = row;
                }
            }
            if (pivot == -1) continue;
            swap(A[rank], A[pivot]);
            T topLeft = A[rank][col];
            for (int c = col; c < width(); ++c) {
                A[rank][c] /= topLeft;
            }
            for (int row = 0; row < m; ++row) {
                if (row == rank or Abs(A[row][col]) < eps) continue;
                T ratio = A[row][col];
                for (int c = col; c < width(); ++c)
                    A[row][c] -= ratio * A[rank][c];
            }
            ++rank;
        }
        return rank;
    }

    friend istream& operator>>(istream& is, Matrix& mat) {
        is >> mat.A;
        return (is);
    }

    friend ostream& operator<<(ostream& os, Matrix& mat) {
        size_t n = mat.height(), m = mat.width();
        for (int i = 0; i < n; ++i) {
            os << (i == 0 ? "[" : " ");
            for (int j = 0; j < m; ++j) {
                os << mat[i][j] << (j == m-1 ? "]" : ",");
            }
            os << (i == n-1 ? "]\n" : ",\n");
        }
        return (os);
    }
};


template<class T>
vector<T> linear_equation(Matrix<T> A, vector<T> b, function<double(T)> Abs, double eps) {
    // extended
    int m = A.height(), n = A.width();
    Matrix<T> M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = M.GaussJordanElimination(Abs, eps, true);

    // check if it has no solution
    vector<T> res;
    for (int row = rank; row < m; ++row) if (Abs(M[row][n]) > eps) return res;

    // answer
    res.assign(n, 0);
    int col = 0;
    for (int row = 0; row < rank; ++row) {
        while (Abs(M[row][col]) < eps) ++col;
        res[col] = M[row][n];
    }
    return res;
}
