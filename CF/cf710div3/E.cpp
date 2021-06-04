#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn],b[maxn],c[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> q,p;
    for(int i = 1; i <= n; i++) {
        q.insert(i);
        p.insert(i);
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1 || a[i] != a[i-1]) {
            b[i] = a[i];
            c[i] = a[i];
            q.erase(a[i]);
            p.erase(a[i]);
        }
        else {
            b[i] = *q.begin();
            c[i] = (*(--p.upper_bound(a[i])));
            q.erase(b[i]);
            p.erase(c[i]);

        }
    }
   for(int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
    for(int i = 1; i <= n;i ++) {
        cout << c[i] << " \n"[i == n];
    } 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }    
    return 0;
}