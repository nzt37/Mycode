#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+ 6;
char a[maxn];
int f[maxn];
void solve()
{
    int n,p,k,x,y;
    cin >> n >> p >> k;
    scanf("%s",a+1);
    cin >> x >> y; 
    for(int i = 0; i <= n; i++) {
        f[i] = 0;
    }
    for(int i = n; i >= 1; i--) {
        if(i + k > n) {
            f[i] = (a[i] == '0');
        }
        else {
            f[i] = f[i+k] + (a[i] == '0');
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i <= n - p; i++) {
        ans = min(ans,i * y + f[i+p] * x);
    }
    cout << ans << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
