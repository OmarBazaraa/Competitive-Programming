#include <bits/stdc++.h>

using namespace std;

/**
 * Matrix class.
 */
template<class T>
class matrix {

    int rows, cols;
    T** mat;

    // ==================================================
    //
    // Helper private functions
    //

    /**
     * Allocates matrix memory resources.
     */
    void init() {
        mat = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    /**
     * Releases matrix memory resources.
     */
    void clear() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    /**
     * Copies the values of the given matrix.
     *
     * @param cpy the matrix to copy its values.
     */
    void copy(const matrix& cpy) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = cpy.mat[i][j];
            }
        }
    }

public:

    // ==================================================
    //
    // Static Public Helper Functions
    //

    /**
     * Constructs an identity matrix of a certain size.
     *
     * @param n the size of the identity matrix.
     *
     * @return the constructed identity matrix of size (n x n).
     */
    static matrix<T> eye(int n) {
        matrix res(n, n);

        for (int i = 0; i < n; ++i) {
            res.mat[i][i] = 1;
        }

        return res;
    }

    // ==================================================

    //
    // Matrix Construction/Destruction Functions
    //

    /**
     * Constructs a new matrix.
     *
     * @param n    the number of rows in the matrix.
     * @param m    the number of columns in the matrix.
     * @param data the data to fill the matrix with.
     */
    matrix(int n = 1, int m = 1, const vector<int>& data = {}) {
        if (n < 1 || m < 1) {
            throw runtime_error("ERROR :: invalid matrix dimensions");
        }

        rows = n;
        cols = m;
        init();
        set(data);
    }

    /**
     * Constructs a new matrix as a clone of the given matrix.
     *
     * @param cpy the matrix to clone.
     */
    matrix(const matrix& cpy) {
        rows = cpy.rows;
        cols = cpy.cols;
        init();
        copy(cpy);
    }

    /**
     * Destructs this matrix and frees its resources.
     */
    ~matrix() {
        clear();
    }

    /**
     * Clones the given matrix.
     *
     * @param rhs the matrix to clone.
     */
    matrix& operator=(const matrix& rhs) {
        if (this == &rhs) {
            return *this;
        }

        if (rows != rhs.rows || cols != rhs.cols) {
            clear();
            rows = rhs.rows;
            cols = rhs.cols;
            init();
        }

        copy(rhs);
        return *this;
    }

    /**
     * Fills the matrix with the given data.
     *
     * @param data the data to fill the matrix with.
     *
     * @return a reference to this matrix.
     */
    matrix& set(const vector<int>& data) {
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (k >= data.size()) {
                    return *this;
                }
                mat[i][j] = data[k++];
            }
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

    /**
     * @return a reference of the cell (i, j) in this matrix.
     */
    T& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw runtime_error("ERROR :: out of range exception");
        }

        return mat[i][j];
    }

    /**
     * @return a constant reference of the cell (i, j) in this matrix.
     */
    const T& operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw runtime_error("ERROR :: out of range exception");
        }

        return mat[i][j];
    }

    /**
     * Adds the given matrix to this one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return the resultant matrix after addition.
     */
    matrix operator+(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res.mat[i][j] = mat[i][j] + rhs.mat[i][j];
            }
        }

        return res;
    }

    /**
     * Adds the given matrix to this one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return a reference to this matrix after addition.
     */
    matrix& operator+=(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] += rhs.mat[i][j];
            }
        }

        return *this;
    }

    /**
     * Subtracts the given matrix from this one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return the resultant matrix after subtraction.
     */
    matrix operator-(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res.mat[i][j] = rhs.mat[i][j] - mat[i][j];
            }
        }

        return res;
    }

    /**
     * Subtracts the given matrix from this one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return a reference to this matrix after subtraction.
     */
    matrix& operator-=(const matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] -= rhs.mat[i][j];
            }
        }

        return *this;
    }

    /**
     * Multiplies this matrix by the given one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return the resultant matrix after multiplication.
     */
    matrix operator*(const matrix& rhs) const {
        if (cols != rhs.rows) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, rhs.cols);

        for (int i = 0; i < res.rows; ++i) {
            for (int j = 0; j < res.cols; ++j) {
                for (int k = 0; k < rhs.rows; ++k) {
                    res.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }

        return res;
    }

    /**
     * Multiplies this matrix by the given one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return a reference to this matrix after multiplication.
     */
    matrix& operator*=(const matrix& rhs) const {
        if (cols != rhs.rows) {
            throw runtime_error("ERROR :: matrices dimensions mis-match");
        }

        matrix res(rows, rhs.cols);

        for (int i = 0; i < res.rows; ++i) {
            for (int j = 0; j < res.cols; ++j) {
                for (int k = 0; k < rhs.rows; ++k) {
                    res.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }

        return (*this = res);
    }

    /**
     * Apply the modulo operation on each element in this matrix.
     *
     * @param mod the modulus.
     *
     * @return the resultant matrix after the modulo operation.
     */
    matrix operator%(int mod) const {
        if (mod < 0) {
            throw runtime_error("ERROR :: invalid modulus");
        }

        matrix res(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res.mat[i][j] = mat[i][j] % mod;
            }
        }

        return res;
    }

    /**
     * Apply the modulo operation on each element in this matrix.
     *
     * @param mod the modulus.
     *
     * @return a reference to this matrix after the modulo operation.
     */
    matrix& operator%=(int mod) const {
        if (mod < 0) {
            throw runtime_error("ERROR :: invalid modulus");
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] %= mod;
            }
        }

        return *this;
    }

    /**
     * Raises this matrix to the power of a certain number.
     *
     * @param exp the exponent to raise the matrix with.
     *
     * @return the resultant matrix after exponentiation.
     */
    matrix operator^(long long exp) const {
        if (rows != cols) {
            throw runtime_error("ERROR :: invalid matrix dimensions");
        }
        if (exp < 0) {
            throw runtime_error("ERROR :: invalid matrix exponent");
        }

        matrix base = *this;
        matrix res = eye(rows);

        while (exp > 0) {
            if (exp & 1) res *= base;
            exp >>= 1;
            base *= base;
        }

        return res;
    }

    /**
     * Raises this matrix to the power of a certain number modulo "mod".
     *
     * @param exp the exponent to raise the matrix with.
     * @param mod the modulus.
     *
     * @return the resultant matrix after exponentiation.
     */
    matrix pow(long long exp, long long mod) const {
        if (rows != cols) {
            throw runtime_error("ERROR :: invalid matrix dimensions");
        }
        if (exp < 0) {
            throw runtime_error("ERROR :: invalid matrix exponent");
        }
        if (mod < 0) {
            throw runtime_error("ERROR :: invalid modulus");
        }

        matrix base = *this;
        matrix res = eye(rows);

        while (exp > 0) {
            if (exp & 1) res.mul(base, mod);
            exp >>= 1;
            base.mul(base, mod);
        }

        return res;
    }

private:

    /**
     * Multiplies this matrix by the given one modulo "mod".
     *
     * @param rhs the matrix on the right hand side.
     * @param mod the modulus.
     *
     * @return a reference to this matrix after multiplication.
     */
    matrix& mul(const matrix& rhs, long long mod) {
        matrix res(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < rows; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * rhs.mat[k][j]) % mod;
                }
            }
        }

        copy(res);

        return *this;
    }
};

/**
 * Prints the given matrix using the given output stream.
 *
 * @param out the output stream to print the matrix into.
 * @param mat the matrix to print.
 *
 * @return the same output stream to method chaining.
 */
template<class T>
ostream& operator<<(ostream& out, const matrix<T>& mat) {
    int w = 6;

    for (int i = 0; i < mat.rows; ++i) {
        out << "[ ";
        for (int j = 0; j < mat.cols; ++j) {
            out << setw(w) << mat.mat[i][j] << ' ';
        }
        out << setw(w) << "]" << endl;
    }

    return out;
}