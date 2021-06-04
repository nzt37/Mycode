#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1010;
int a[maxn];
map<int,int >mp;
void solve()
{
    int n;
    cin >> n;
    mp.clear();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(mp[a[i]] >= 2) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
