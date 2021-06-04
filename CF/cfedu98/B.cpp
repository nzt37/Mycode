#include <bits/stdc++.h>

using namespace std;
#define int long long
int a;
void solve()
{
    int n;
    cin >> n;
    int ans = 0,maxx = 0;
    int minn = 1e18;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        maxx = max(maxx,a);
        ans += a;
    }
    if(maxx*(n-1) >= ans) {
        cout << maxx*(n-1) - ans << endl;
    }
    else {
        //cout << " df s"<< endl;
        if(ans % (n-1) == 0) {
            cout << 0 << endl;
        }
        else
        cout << (n-1-(ans%(n-1))) << endl;
    }
}
signed main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}