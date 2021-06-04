#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 6;
int vis[maxn],a[maxn];


void solve()
{
    int n;
    cin >> n;
    int minn = 2000010,num = 0,maxx = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        vis[m]++;
        a[m] = i;
        maxx = max(maxx,m);
    }
    for(int i = 1; i <= maxx; i++) {
        if(vis[i] == 1) {
            cout << a[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}       