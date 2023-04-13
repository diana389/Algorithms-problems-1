#include <iostream>
using namespace std;

const int mod = 1000000007;

uint64_t substring(uint64_t n)
{
    uint64_t *v = new uint64_t[n + 1];

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;

    for (uint64_t i = 3; i <= n; i++)
        v[i] = (v[i - 1] % mod + v[i - 2] % mod) % mod;

    // cout << "hei " << v[n] << endl;

    uint64_t result = v[n];

    delete[] v;

    return result;
}

uint64_t task()
{
    char l;
    uint64_t n, res = 1;

    while (cin >> l >> n)
    {
        // cout << l << n << endl;

        if (l == 'n' || l == 'u')
            res = ((res % mod) * (substring(n) % mod)) % mod;

        // cout << "res: " << res << endl;
    }

    return res;
}

int main()
{
    freopen("badgpt.in", "r", stdin);
    freopen("badgpt.out", "w", stdout);

    cout << task();

    return 0;
}