#include <bits/stdc++.h>
using namespace std;

int n,m;
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
            if(abs(x) <= r - l) {
                cout << a << " " << x + r << " " << r << endl;
                return;
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}