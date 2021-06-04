#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+6;
int f[maxn],sum[maxn];
char s[maxn];
map<int, int > mp;
void solve()
{
    int n;
    cin >> n;
    scanf("%s",s+1);
    long long  ans = 0;
    mp.clear();
    for(int i = 1; i <= n; i++) {
        f[i] = s[i] - '0' - 1;
        sum[i] = sum[i-1] + f[i];
    }
    for(int i = 1; i <= n; i++) {
        if(sum[i] == 0) ans++;
        ans += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ans << endl;;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
