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
