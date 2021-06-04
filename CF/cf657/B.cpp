#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l,r,m;
    cin >> l >> r >> m;
    for(int a = l; a <= r; a++) {
        int x = m % a;
        int n = m / a;
        if(n >= 1 && x <= (r-l)) {
            cout << a << " " << x + l << " " << l << endl;
            return;
        }  
        else {
            x = x - a;
            if(x >= l-r) {
                cout << a << " " << x + r << " " << r << endl;
                return;
            }
        }
    }
}
signed main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}