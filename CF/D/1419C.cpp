#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e3 + 6;
int a[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int flag1 = 0,flag2 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == m) {
            flag1 = 1;
        }
        else{
            flag2 = 1;
        }
        ans += a[i];
    }
    int p = n * m;
    if(!flag2) {
        cout << 0 << endl;
        return;
    }
    if( (ans == p)|| flag1) {
        cout << 1 << endl;
        return;
    }
    else {
        cout << 2 << endl;
        return;
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
