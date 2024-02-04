#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e3 + 5;
const int inf = 1e9 + 5;
const double eps = 1e-10;
int n, dp[maxn][maxn][2];
pii seg[maxn];
void init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
}
void print() {
    for (int i = n / 2; i >= 1; --i) {
        if (dp[n][i][1] != inf) {
            cout << n - i * 2 << '\n';
            return;
        }
    }
    cout << n << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) {
            int l, r;
            cin >> l >> r;
            seg[i] = make_pair(l, r);
        }
        sort(seg + 1, seg + n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i][0][1] = -1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n / 2; ++j) {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
                if (dp[i - 1][j][0] != inf && seg[i].first <= dp[i - 1][j][0]) {
                    dp[i][j][1] =
                        min(dp[i][j][1], max(dp[i - 1][j][0], seg[i].second));
                }
                if (j && dp[i - 1][j - 1][1] != inf &&
                    seg[i].first > dp[i - 1][j - 1][1]) {
                    dp[i][j][0] = min(dp[i][j][0], seg[i].second);
                }
                // cout << i << " " << j << " " << dp[i][j][1] << '\n';
            }
        }
        print();
    }

    return 0;
}