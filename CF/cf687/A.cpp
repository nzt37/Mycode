#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int p = abs(a-c) + abs(b-d);
    int q = abs(1-c) + abs(1-d);
    int x = abs(1-c) + abs(b-d);
    int y = abs(a-c) + abs(1-d);
    int maxx = max(p,q);
    cout << max(x,max(maxx,y)) << endl;
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