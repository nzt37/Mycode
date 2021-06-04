#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 6; 
int a[maxn],b[maxn];
struct node{
    int val,num;
}c[maxn];
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for(int i = 1; i <= 100; i++) {
        int now = 1;
        int res = 0;
        while(now <= n) {
            while( now <= n && a[now] == i ) now++;
            if(now > n) {
                break;
            }
            res++;
            now += m;
        }
        ans = min(res,ans);
   }
   cout << ans << endl;
    
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