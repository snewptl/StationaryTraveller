#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 999999893;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int N;
ll quickPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
int main() {
    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        ll inv = (1 - quickPow(2, N - 1) + mod) % mod;
        inv = quickPow(inv, mod - 2);
        if (N % 2) {
            std::cout << (quickPow(2, N / 2) + 1) % mod * inv % mod << '\n';
        } else {
            std::cout << (mod - (quickPow(2, N / 2)) + 1) % mod * inv % mod
                      << '\n';
        }
    }

    return 0;
}
