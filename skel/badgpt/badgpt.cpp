#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000007;
uint64_t **mat;

// function that multiplies 2 matrices
uint64_t **multiply(uint64_t **a, uint64_t **b) {
    // allocate memory
    uint64_t **res = new uint64_t *[2];
    for (int i = 0; i < 2; i++)
        res[i] = new uint64_t[2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;

            for (int k = 0; k < 2; k++)
                res[i][j] += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
        }

    return res;
}

// function that raises the matrix to power n
uint64_t **power(uint64_t n) {
    // base case
    if (n == 1)
        return mat;

    uint64_t **half = power(n / 2);

    if (n % 2)
        return multiply(multiply(half, half), power(1));
    else
        return multiply(half, half);
}

// function that returns the number of possible initial substrings
uint64_t substring(uint64_t n) {
    if (n == 0)
        return 0;

    uint64_t **res = power(n + 1);
    uint64_t result = res[0][1];

    // free memory
    for (int i = 0; i < 2; i++)
        delete[] res[i];

    delete[] res;

    return result;
}

// function that parses the input and returns the number of
// possible initial strings
uint64_t task() {
    char l;
    uint64_t n, res = 1;

    while (cin >> l >> n)
        if (l == 'n' || l == 'u')  // more than 1 possibilities
            res = ((res % mod) * (substring(n) % mod)) % mod;

    return res;
}

int main() {
    freopen("badgpt.in", "r", stdin);
    freopen("badgpt.out", "w", stdout);

    // allocate memory
    mat = new uint64_t *[2];
    for (int i = 0; i < 2; i++)
        mat[i] = new uint64_t[2];

    // initial matrix
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;

    cout << task();

    // free memory
    for (int i = 0; i < 2; i++)
        delete[] mat[i];

    delete[] mat;

    return 0;
}
