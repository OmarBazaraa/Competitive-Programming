#include <bits/stdc++.h>

using namespace std;

const int M = 5, MOD = 1e9 + 7;

/**
 * Minified matrix class for competitive programming.
 * The time complexity of the matrix power is O((M^3).log(n)),
 * where "M" is the size of the matrix, and "n" is the exponent.
 */
class matrix {
    int rows, cols;
    int mat[M][M] = {};

public:

    /**
     * Constructs an identity matrix of a certain size.
     *
     * @param n the size of the identity matrix.
     *
     * @return the constructed identity matrix of size (n x n).
     */
    static matrix eye(int n) {
        matrix res(n, n);
        for (int i = 0; i < n; ++i) {
            res.mat[i][i] = 1;
        }
        return res;
    }

    /**
     * Constructs a new matrix.
     *
     * @param n    the number of rows in the matrix.
     * @param m    the number of columns in the matrix.
     * @param data the data to fill the matrix with.
     */
    matrix(int n = 1, int m = 1, const vector<int>& data = {}) {
        rows = n;
        cols = m;
        set(data);
    }

    /**
     * Fills the matrix with the given data.
     *
     * @param data the data to fill the matrix with.
     */
    void set(const vector<int>& data) {
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (k >= data.size()) {
                    return;
                }
                mat[i][j] = data[k++];
            }
        }
    }

    /**
     * @return a reference of the cell (i, j) in this matrix.
     */
    int& operator()(int i, int j) {
        return mat[i][j];
    }

    /**
     * Multiplies this matrix by the given one.
     *
     * @param rhs the matrix on the right hand side.
     *
     * @return the resultant matrix after multiplication.
     */
    matrix operator*(const matrix& rhs) const {
        matrix res(rows, rhs.cols);

        for (int i = 0; i < res.rows; ++i)
            for (int j = 0; j < res.cols; ++j)
                for (int k = 0; k < rhs.rows; ++k)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * 1LL * rhs.mat[k][j]) % MOD;

        return res;
    }

    /**
     * Raises this matrix to the power of a certain number.
     *
     * @param exp the exponent to raise the matrix with.
     *
     * @return the resultant matrix after exponentiation.
     */
    matrix operator^(long long exp) const {
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

/**
 * Sample driver program.
 *
 * This is an example of calculating Fibonacci(n) mod (10^9 + 7) for very
 * large values of "n" (i.e. 1 <= n <= 10^18).
 */
int main() {
    long long n;
    cin >> n;

    matrix A(2, 2, {
        0, 1,
        1, 1
    });

    matrix b(2, 1, {
        0,
        1
    });

    matrix r = (A ^ (n - 1)) * b;

    cout << r(1, 0) << endl;

    return 0;
}