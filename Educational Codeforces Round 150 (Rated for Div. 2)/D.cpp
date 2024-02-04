#include <iostream>
#include <vector>
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
int n;
pii seg[maxn];
vector<pii> vec;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int l, r;
            cin >> l >> r;
            seg[i] = make_pair(l, r);
        }
        sort(seg + 1, seg + n + 1);
        vec.clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (seg[i].second < seg[j].first) continue;
                vec.push_back(make_pair(seg[i].first, max(seg[j].second, seg[i].second)));
            }
        }
        sort(vec.begin(), vec.end());
        int lst = -1, ans = 0;
        for (auto it: vec) {
            if (it.first > lst)
                lst = it.second, ans++;
            else lst = min(lst, it.second);
        }
        cout << n - ans * 2 << '\n';
    }
    return 0;
}