#include <bits/stdc++.h>
 
using namespace std;

const int K = 13;
const int MOD = 998244353;

int n, k, x;

int cnt[K][K][K];
int dp[K][2 * K][K][K];

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

int sub(int x, int y)
{
    return add(x, -y);
}   

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x);
        y /= 2;
        x = mul(x, x);
    }   
    return z;
}

void precalc()
{
    cnt[2][1][1] = 1;
    cnt[3][1][2] = 2;
    cnt[3][2][3] = 1;
    cnt[4][1][3] = 3;
    cnt[4][1][4] = 1;
    cnt[4][2][3] = 1;
    cnt[4][2][4] = 4;
    cnt[4][2][5] = 3;
    cnt[4][3][6] = 1;
    cnt[5][1][4] = 4;
    cnt[5][1][5] = 2;
    cnt[5][1][6] = 2;
    cnt[5][2][4] = 4;
    cnt[5][2][5] = 12;
    cnt[5][2][6] = 12;
    cnt[5][2][7] = 9;
    cnt[5][2][8] = 3;
    cnt[5][3][5] = 2;
    cnt[5][3][6] = 4;
    cnt[5][3][7] = 6;
    cnt[5][3][8] = 6;
    cnt[5][3][9] = 4;
    cnt[5][4][10] = 1;
    cnt[6][1][5] = 5;
    cnt[6][1][6] = 3;
    cnt[6][1][7] = 4;
    cnt[6][1][8] = 3;
    cnt[6][1][9] = 1;
    cnt[6][2][5] = 10;
    cnt[6][2][6] = 28;
    cnt[6][2][7] = 35;
    cnt[6][2][8] = 35;
    cnt[6][2][9] = 30;
    cnt[6][2][10] = 17;
    cnt[6][2][11] = 8;
    cnt[6][3][5] = 1;
    cnt[6][3][6] = 13;
    cnt[6][3][7] = 29;
    cnt[6][3][8] = 41;
    cnt[6][3][9] = 44;
    cnt[6][3][10] = 45;
    cnt[6][3][11] = 30;
    cnt[6][4][7] = 1;
    cnt[6][4][8] = 4;
    cnt[6][4][9] = 7;
    cnt[6][4][10] = 7;
    cnt[6][4][11] = 11;
    cnt[7][1][6] = 6;
    cnt[7][1][7] = 4;
    cnt[7][1][8] = 6;
    cnt[7][1][9] = 6;
    cnt[7][1][10] = 6;
    cnt[7][1][11] = 2;
    cnt[7][2][6] = 20;
    cnt[7][2][7] = 55;
    cnt[7][2][8] = 80;
    cnt[7][2][9] = 95;
    cnt[7][2][10] = 101;
    cnt[7][2][11] = 94;
    cnt[7][3][6] = 6;
    cnt[7][3][7] = 50;
    cnt[7][3][8] = 118;
    cnt[7][3][9] = 186;
    cnt[7][3][10] = 230;
    cnt[7][3][11] = 260;
    cnt[7][4][7] = 3;
    cnt[7][4][8] = 18;
    cnt[7][4][9] = 48;
    cnt[7][4][10] = 85;
    cnt[7][4][11] = 113;
    cnt[7][5][10] = 2;
    cnt[7][5][11] = 4;
    cnt[8][1][7] = 7;
    cnt[8][1][8] = 5;
    cnt[8][1][9] = 8;
    cnt[8][1][10] = 9;
    cnt[8][1][11] = 11;
    cnt[8][2][7] = 35;
    cnt[8][2][8] = 96;
    cnt[8][2][9] = 155;
    cnt[8][2][10] = 207;
    cnt[8][2][11] = 250;
    cnt[8][3][7] = 21;
    cnt[8][3][8] = 145;
    cnt[8][3][9] = 358;
    cnt[8][3][10] = 616;
    cnt[8][3][11] = 859;
    cnt[8][4][7] = 1;
    cnt[8][4][8] = 26;
    cnt[8][4][9] = 124;
    cnt[8][4][10] = 313;
    cnt[8][4][11] = 567;
    cnt[8][5][9] = 3;
    cnt[8][5][10] = 16;
    cnt[8][5][11] = 53;
    cnt[9][1][8] = 8;
    cnt[9][1][9] = 6;
    cnt[9][1][10] = 10;
    cnt[9][1][11] = 12;
    cnt[9][2][8] = 56;
    cnt[9][2][9] = 154;
    cnt[9][2][10] = 268;
    cnt[9][2][11] = 389;
    cnt[9][3][8] = 56;
    cnt[9][3][9] = 350;
    cnt[9][3][10] = 898;
    cnt[9][3][11] = 1654;
    cnt[9][4][8] = 8;
    cnt[9][4][9] = 126;
    cnt[9][4][10] = 552;
    cnt[9][4][11] = 1404;
    cnt[9][5][9] = 4;
    cnt[9][5][10] = 48;
    cnt[9][5][11] = 204;
    cnt[9][6][11] = 1;
    cnt[10][1][9] = 9;
    cnt[10][1][10] = 7;
    cnt[10][1][11] = 12;
    cnt[10][2][9] = 84;
    cnt[10][2][10] = 232;
    cnt[10][2][11] = 427;
    cnt[10][3][9] = 126;
    cnt[10][3][10] = 742;
    cnt[10][3][11] = 1967;
    cnt[10][4][9] = 36;
    cnt[10][4][10] = 448;
    cnt[10][4][11] = 1887;
    cnt[10][5][9] = 1;
    cnt[10][5][10] = 43;
    cnt[10][5][11] = 357;
    cnt[10][6][11] = 6;
    cnt[11][1][10] = 10;
    cnt[11][1][11] = 8;
    cnt[11][2][10] = 120;
    cnt[11][2][11] = 333;
    cnt[11][3][10] = 252;
    cnt[11][3][11] = 1428;
    cnt[11][4][10] = 120;
    cnt[11][4][11] = 1302;
    cnt[11][5][10] = 10;
    cnt[11][5][11] = 252;
    cnt[11][6][11] = 5;
    cnt[12][1][11] = 11;
    cnt[12][2][11] = 165;
    cnt[12][3][11] = 462;
    cnt[12][4][11] = 330;
    cnt[12][5][11] = 55;
    cnt[12][6][11] = 1;    
}

int inv[K];

int C(int n, int k)
{
    if(n < 0 || n < k || k < 0) return 0;
    int res = 1;
    for(int i = n; i > n - k; i--)
        res = mul(res, i);
    for(int i = 1; i <= k; i++)
        res = mul(res, inv[i]);
    return res;
}

void prepare()
{
    for(int i = 1; i < K; i++)
        inv[i] = binpow(i, MOD - 2);
    precalc();
    dp[0][0][0][0] = 1;
    for(int i = 0; i < K; i++)
        for(int j = 0; j < 2 * K; j++)
            for(int a = 0; a < K - 2; a++)
                for(int b = 0; b < K - 2; b++)
                {
                    if(dp[i][j][a][b] == 0) continue;
                    for(int add_cnt = 2; add_cnt < K; add_cnt++)
                        for(int add_desc = 1; add_desc <= K - 2; add_desc++)
                            for(int add_inv = 1; add_inv <= K - 2; add_inv++)
                            {
                                if(j + add_cnt >= 2 * K || a + add_desc > K - 2 || b + add_inv > K - 2) continue;
                                int& nw = dp[i + 1][j + add_cnt][a + add_desc][b + add_inv];
                                nw = add(nw, mul(dp[i][j][a][b], cnt[add_cnt][add_desc][add_inv]));    
                            }
                }       
}

void solve() 
{
    scanf("%d %d %d", &n, &k, &x);
    if(k == 0 && x == 0)
    {
        puts("1");
        return;
    }
    int ans = 0;
    for(int i = 1; i < K; i++)
        for(int j = 1; j < 2 * K; j++)
            if(dp[i][j][x][k] != 0)
            {
                ans = add(ans, mul(dp[i][j][x][k], C(n - j + i, i))); 
				if(dp[i][j][x][k])printf("%d %d %lld\n",i,j,dp[i][j][x][k]);       
            }
    printf("%d\n", ans);
}

int main()
{
    prepare();
	
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();
}