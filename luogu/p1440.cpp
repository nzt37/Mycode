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
int a[maxn];
struct node{
    int num,val;
};
int ans[maxn];
int main() {
    cin >> n >> m;   
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    deque<node> q;
    node x;
    // x.num = 1;
    // x.val = a[1];
    ans[0] = 0;
    // q.push_back(x);
    // cout << 0 << "\n";
    for(int i = 1; i < n; i++) {
        x.num = i-1;
        x.val = a[i];
        while(!q.empty() && q.back().val >= a[i]) q.pop_back();
        q.push_back(x); 
        while(!q.empty() && q.front().num < i - m) q.pop_back();
        // cout << q.front().val << "\n";
        ans[i] = q.front().val;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}