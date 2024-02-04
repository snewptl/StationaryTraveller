#include<iostream>
#include<vector>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e5+5;
const double eps = 1e-10;
int n,m;
vector<pii> vec;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            vec.push_back(make_pair(x, y));
        }
        sort(all(vec));
        for (int i = 1; i <= n; ++i) {

        }
   }
    return 0;
}
/*
left_point <= cur.left 
min{right_point} 

...

stack legnth increase 
*/