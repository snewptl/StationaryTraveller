#include <iostream>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 3e5 + 5;
const double eps = 1e-10;
int n;
vector<pii> vec;
int section(pii x) {
    if (x.first > 0 && x.second >= 0)
        return 0;
    if (x.first <= 0 && x.second > 0)
        return 1;
    if (x.first < 0 && x.second <= 0)
        return 2;
    return 3;
}
bool cmp(pii pre, pii nxt) {
    if (section(pre) != section(nxt))
        return section(pre) < section(nxt);
    return 1ll * pre.first * nxt.second - 1ll * pre.second * nxt.first > 0;
}
int main() {
    int T = 1;  // cin >> T;
    while (T--) {
        cin >> n;
        pair<db, db> start_point = make_pair(0, 0);
        vec.clear();
        for (int i = 1; i <= n; ++i) {
            int a, b, c, d;
            scanf("%d%d%d%d", a, b, c, d);
            if (a == b && c == d)
                continue;
            vec.push_back(make_pair(b - a, d - c));
            vec.push_back(make_pair(a - b, c - d));
            if (d - c < 0 || (d == c && b < a)) {
                start_point.first += b - a;
                start_point.second += d - c;
            }
        }
        sort(all(vec), cmp);
        db ans = 0;
        for (auto it : vec) {
            start_point.first += it.first;
            start_point.second += it.second;
            ans = max(ans, start_point.first * start_point.first +
                               start_point.second * start_point.second);
        }
        printf("%.10lf\n", ans);
    }

    return 0;
}