#include <bits/stdc++.h>

using namespace std;

template<class T>
class matrix {

    int rows, cols;
    T** mat;

    //
    // Helper private funcions
    //

    // Allocates matrix memory resourses
    void init() {
        mat = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new T[cols];
        }
    }

    // Releases matrix memory resourses.
    void clear() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // ==================================================

public:

    //
    // Helper Public Funcions
    //

    // Fills all the cells of the matrix by the given value.
    void fill(const T& v) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                mat[i][j] = v;
    }

    // Copies the values of the given matrix.
    void copy(const matrix& cpy) {
        if (rows != cpy.rows || cols != cpy.cols) {
            throw exception("ERROR :: matrices dimensions mis-match");
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                mat[i][j] = cpy.mat[i][j];
    }

    // ==================================================

    //
    // Static Public Helper Funcions
    //

    // Returns integer identity matrix of size (n x n).
    static matrix<T> eye(int n) {
        matrix res(n, n);

        for (int i = 0; i < n; ++i) {
            res.mat[i][i] = 1;
        }

        return res;
    }

    // ==================================================

    //
    // Constructors, Destructor, and Assignment Operator
    //

    // Constructs a matrix of size (n x m) initialized by value v.
    matrix(int n = 1, int m = 1, const T& v = 0) {
        if (n < 1 || m < 1) {
            throw exception("ERROR :: invalid matrix dimensions");
        }

        rows = n;
        cols = m;
        init();
        fill(v);
    }

    // Constructs a matrix as a clone of the given matrix.
    matrix(const matrix& cpy) {
        rows = cpy.rows;
        cols = cpy.cols;
        init();
        copy(cpy);
    }

    // Destructs this matrix and free resourses.
    ~matrix() {
        clear();
    }

    // Assigns this matrix to the given matrix.
    matrix& operator=(const matrix& rhs) {
        if (this != &rhs) {
            clear();
            rows = rhs.rows;
            cols = rhs.cols;
            init();
            copy(rhs);
        }

        return *this;
    }

    // ==================================================

    //
    // Matrices Operators
    //

    // Prints this matrix
    template<class U>
    friend ostream& operator<<(ostream& out, const matrix<U>& m);

    // Returns cell (i, j) in this matrix.
    T& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw exception("ERROR :: out of range exception");
        }

        return mat[i][j];
    }

    // Adds the given matrix to this matrix.
    matrix operator+(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw exception("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, cols);

        for (int i = 0; i < res.rows; ++i)
            for (int j = 0; j < res.cols; ++j)
                res.mat[i][j] = mat[i][j] + rhs.mat[i][j];

        return res;
    }

    // Subtracts the given matrix from this matrix.
    matrix operator-(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw exception("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, cols);

        for (int i = 0; i < res.rows; ++i)
            for (int j = 0; j < res.cols; ++j)
                res.mat[i][j] = rhs.mat[i][j] - mat[i][j];

        return res;
    }

    // Multiplies this matrix by the given matrix.
    matrix operator*(const matrix& rhs) const {
        if (cols != rhs.rows) {
            throw exception("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, rhs.cols);

        for (int i = 0; i < res.rows; ++i)
            for (int j = 0; j < res.cols; ++j)
                for (int k = 0; k < rhs.rows; ++k)
                    res.mat[i][j] += mat[i][k] * rhs.mat[k][j];

        return res;
    }

    // Raises this matrix to the power of the given number.
    matrix operator^(int exp) const {
        if (rows != cols) {
            throw exception("ERROR :: matrix dimensions mis-match");
        }

        if (exp < 0) {
            throw exception("ERROR :: invalid matrix exponent");
        }

        matrix base = *this;
        matrix res = eye(rows);

        while (exp > 0) {
            if (exp & 1) res = (res * base);
            exp >>= 1;
            base = (base * base);
        }

        return res;
    }
};

template<class T>
ostream& operator<<(ostream& out, const matrix<T>& m) {
    int w = 6;

    for (int i = 0; i < m.rows; ++i) {
        out << "[ ";
        for (int j = 0; j < m.cols; ++j) {
            out << setw(w) << m.mat[i][j] << ' ';
        }
        out << setw(w) << "]" << endl;
    }

    return out;
}