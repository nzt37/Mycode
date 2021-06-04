#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int a[maxn],s[maxn];
int n,m;
set<int > p;
void work(int l ,int r)
{
    if(l > r) return;
    p.insert(s[r] - s[l-1]);
    int res = (a[l] + a[r]) / 2;
    if(res >= a[r] || res < a[l]) return;
    int t = upper_bound(a+l,a+r,res) - a;
    work(l,t-1);
    work(t,r);
}
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    memset(s,0,sizeof(s));
    for(int i = 1; i <= n; i++) {
         s[i] = s[i-1] + a[i];
    }
    p.clear();
    work(1,n);
    while(m--) {
        int k;
        cin >> k;
        // work(1,n);
        if(p.count(k)) {
            puts("Yes");
        }
        else puts("No");

    }
}
signed main(){
    int T;
    cin >> T;
    while(T--)  {
        solve();
    }
    return 0;
}