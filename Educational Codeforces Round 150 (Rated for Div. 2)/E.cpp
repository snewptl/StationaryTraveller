#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
set<pair<int, pii> > s;
int n, a[maxn];
ll m;
int pre[maxn], nxt[maxn];
ll seg[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = n - a[i];
        cin >> m;
        s.clear();
        for (int i = 1; i <= n; ++i) seg[i] = 0;
        int lst = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i] != a[i - 1]) {
                s.insert(make_pair(a[i - 1], make_pair(lst, i - 1)));
                pre[i - 1] = lst;
                nxt[lst] = i - 1;
                lst = i;
            }
        }
        pre[n] = lst;
        nxt[lst] = n;
        s.insert(make_pair(a[n], make_pair(lst, n)));
        ll ans = 0;
        a[0] = a[n + 1] = -1;
        // for (auto it: s) cout << "§ " << it.first << '\n';
        while (!s.empty()) {
            auto it = s.end();
            it--;
            if (it->second.first == 1 && it->second.second == n) {
                seg[n] += it->first;
                break;
            }
            int candi_left = it->second.first - 1, candi_right = it->second.second + 1;
            seg[it->second.second - it->second.first + 1] += it->first - max(a[candi_left], a[candi_right]);
            if (a[candi_left] >= a[candi_right]) {
                s.erase(make_pair(a[candi_left], make_pair(pre[candi_left], candi_left)));
                pre[it->second.second] = pre[candi_left];
                nxt[pre[it->second.second]] = it->second.second; 
                s.insert(make_pair(a[candi_left], make_pair(pre[candi_left], it->second.second)));
                a[it->second.second] = a[candi_left];
            }
            else {
                s.erase(make_pair(a[candi_right], make_pair(candi_right, nxt[candi_right])));
                nxt[it->second.first] = nxt[candi_right];
                pre[nxt[it->second.first]] = it->second.first;
                s.insert(make_pair(a[candi_right], make_pair(pre[nxt[candi_right]], nxt[candi_right])));
                a[it->second.first] = a[candi_right];
            }
            s.erase(it);
        }
        for (int i = n; i >= 1; --i) {
            if (!seg[i]) continue;
            if (1ll * seg[i] * i <= m) {
                m -= 1ll * seg[i] * i;
                ans += 1ll * seg[i] * (i - 1);
            }
            else {
                ans += 1ll * (m / i) * (i - 1);
                m -= 1ll * (m / i) * i;
                if (m) ans += m - 1;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}