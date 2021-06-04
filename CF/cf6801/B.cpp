#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve()
{

    int a,b,c,d;
    int ma = -1,maxx = -1;

    cin >> a >> b >> c >> d;
    ma = max(ma,a+b);
    maxx = max(maxx,c+d);

    cout << max(ma,maxx) << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
