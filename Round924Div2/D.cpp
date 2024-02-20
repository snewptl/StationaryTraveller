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
const int maxn = 2e5 + 5;
int n, b, x;
int c[maxn];
ll check(int squad) {
    ll sum = -1ll * (squad - 1) * x;
    for (int i = 1; i <= n; ++i) {
        ll average = c[i] / squad;
        ll oneMore = c[i] % squad;
        sum += b * (1ll * c[i] * c[i] - (squad - oneMore) * average * average -
                    oneMore * (average + 1) * (average + 1)) / 2;
    }
    return sum;
}
void solve() {
    int l = 1, r = 2e5, res = 1;
    while (l <= r) {
        int p1 = (l * 2 + r) / 3;
        int p2 = (l + r * 2) / 3;
        int newRes;
        if (check(p1) < check(p2)) {
            newRes = p1;
            l = p1 + 1;
        } else {
            newRes = p2;
            r = p2 - 1;
        }
        if (check(res) < check(newRes))
            res = newRes;
    }
    std::cout << check(res) << '\n';
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> b >> x;
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
        }
        solve();
    }

    return 0;
}