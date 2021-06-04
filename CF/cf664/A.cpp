#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int a,b,c,d;
void solve()
{
    cin >> a >> b >> c >> d;
    int cnt = 0;
    cnt += (a&1) + (b&1) + (c&1) + (d&1);
    int m = min(a,min(b,c));
    if(m == 0) {
        if(cnt > 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    else {
        if(cnt == 2) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
