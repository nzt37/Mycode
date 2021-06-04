#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 6;
int n,m;
int a[maxn],cnt[maxn],ans[maxn];
void solve()
{
    cin >> n;
     for(int i = 1; i <= n; i++) ans[i] = cnt[i] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
   if(cnt[1] >= 1) ans[n] = 1;
    ans[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] != 1) {
            ans[1] = 0;
            break;
        }
    }
    int l = 1,r = n;
    for(int i = 1; i <= n-1; i++) {
        if(!cnt[i] || cnt[i] > 1) break;
        if(a[l] == i && cnt[i+1]) {
            ans[n-i] = 1;
            l++;
        }
        else if(a[r] == i && cnt[i+1]) {
            ans[n-i] = 1;
            r--;
        }
        else break;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}