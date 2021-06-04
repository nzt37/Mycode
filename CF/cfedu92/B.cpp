#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 6;
int a[maxn];
void solve()
{
    int n,k,z;
    cin >> n >> k >> z;
    k++;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mx = 0,ans = 0,sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += a[i];
        if(i < n) mx = max (mx,a[i]+a[i+1]);
        int t = (k-i)/2;
        ans = max(ans, min(t,z)*mx + sum);
       
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