#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
#define int long long
int a[maxn],b[maxn],sum;
int n,m;
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum = 0;
    for(int i = 1; i < n; i++) {
        sum += abs(a[i+1] - a[i]);
    }
    int ans = max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
    for(int i = 2; i < n; i++) {
        ans = max(ans,abs(a[i]-a[i-1])+abs(a[i+1]-a[i])-abs(a[i+1]-a[i-1]));
    }
    cout << sum - ans << endl;
}
signed main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
