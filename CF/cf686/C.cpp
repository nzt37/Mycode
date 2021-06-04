#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 6;
int vis[maxn],a[maxn],v[maxn];
void solve()
{
   int n,maxx = 0;
   cin >> n;
   memset(vis,0,sizeof(vis));
   int minn = INT_MAX;
   for(int i = 1; i <= n; i++) {
       cin >> a[i];
       v[i] = 1;
       vis[a[i]]++;
       if(a[i] == a[i-1]) {
           vis[a[i]]--;
       }
       if(i == 1) {
           vis[a[i]]--;
       }
       if(i == n) {
           vis[a[i]]--;
       }
       maxx = max(maxx,a[i]);    
   }
   //cout << vis[5] << endl;
   for(int i = 1; i <= n; i++) {
       minn = min(minn,vis[a[i]]);
   }
    cout << minn+1 << endl;
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