#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
string s;
int ans, mi[5];
void check(int x) {
    for (int i = 0; i < 5; ++i) {
        s[x] = i + 'A';
        char mx = 'A';
        int res = 0;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (s[j] >= mx)
                res += mi[s[j] - 'A'];
            else res -= mi[s[j] - 'A'];
            mx = max(mx, s[j]);
        }
        ans = max(ans, res);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    mi[0] = 1;
    for (int i = 1; i < 5; ++i) mi[i] = mi[i - 1] * 10;
    while (T--) {
        cin >> s;
        ans = -2e9;
        map<int, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (!mp[ch])
                check(i);
            mp[ch] = 1;
            s[i] = ch;
        }
        mp.clear();
        for (int i = s.size() - 1; i >= 0; --i) {
            char ch = s[i];
            if (!mp[ch])
                check(i);
            mp[ch] = 1;
            s[i] = ch;
        }
        cout << ans << '\n';
    }

    return 0;
}