#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int f[22];
signed main() {
    int n;
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = i*f[i-1];
    int m = f[n]/f[n/2]/f[n/2]/2*f[n/2-1]*f[n/2-1];
    printf("%lld\n",m);
    return 0;
}
