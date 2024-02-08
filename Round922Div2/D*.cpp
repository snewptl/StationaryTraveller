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
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int n, a[maxn];
ll check(ll x) {
    std::set<pii> s;
    s.insert({0, 0});
    for (int i = 1; i <= n; ++i) {
        s.insert({})
    }
}
ll dichotomy() {
    ll l = 0, r = 1e18, res = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            res = std::min(res, mid);
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::cout << dichotomy() << '\n';
        
    }

    return 0;
}
