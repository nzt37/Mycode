#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 6;
int a[maxn];
int n,x;
bool check()
{
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[i-1]) {
            return false;
        }
    }
    return true;
}
void solve()
{
    
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0,flag = 0;
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[i-1]) {
            flag = 1;
        }
    }
    if(!flag) {
        cout << 0 << endl;
        return;
    }
   for(int i = 1; i <= n; i++) {
       if(a[i] > x) {
           swap(a[i],x);
           cnt++;
       }
       if(check()) {
           cout << cnt << endl;
           return;
       }
   }
   for(int i = 2; i <= n; i++) {
       if(a[i] < a[i-1]) {
           cout << -1 << endl;
           return;
       }
   }

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