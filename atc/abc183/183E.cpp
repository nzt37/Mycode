#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long 
const int mod =  1e9 + 7;
const int maxn = 2020;
char mp[2020][2020];
int dp[4][2020][2020];
signed main() {
    int h,w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> mp[i][j];
        }
    }
    dp[3][1][1] = 1;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(i == 1 && j == 1) continue;
            if(mp[i][j] == '#') continue;
            dp[0][i][j] = (dp[0][i-1][j] + dp[3][i-1][j])%mod;
            dp[1][i][j] = (dp[1][i][j-1] + dp[3][i][j-1])%mod;
            dp[2][i][j] = (dp[2][i-1][j-1] + dp[3][i-1][j-1])%mod;
            dp[3][i][j] = (dp[0][i][j] + dp[1][i][j] + dp[2][i][j])%mod;
        }
    }
    cout << dp[3][h][w] << endl;
    return 0;
}
