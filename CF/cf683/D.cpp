#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5050;
int sum[maxn],a[maxn],b[maxn];
char s1[maxn],s2[maxn];
int dp[maxn][maxn];
void solve()
{
    int n,m;
    cin >> n >> m;
    scanf("%s",s1 + 1);
    scanf("%s",s2 + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j],dp[i-1][j] - 1);
            dp[i][j] = max(dp[i][j],dp[i][j-1] - 1);
            if(s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 2);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}
int main() {
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}
