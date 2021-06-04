#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5050;
void solve()
{
    int m,n;
    string s;
    cin >> n >> m;
    cin >> s;
    while(m--) {
        int l,r;
        cin >> l >> r;       
        int a = s.find(s[l-1]);
        int b = s.rfind(s[r-1]);
        if((a != -1 && a < l-1) || (b != -1 && b >= r)) {
           // cout << a << " " << b << endl;
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
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