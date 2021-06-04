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
int a[maxn],an[maxn];
void dfs(int l,int r,int pos) {
	if(l > r) return;
	int id = -1,maxx = -1;
	for(int i = l ;i <= r; i++) {
		if(a[i] > maxx) {
			maxx = a[i];
			id = i;
		}
	}
	an[id] = pos;
	dfs(l,id-1,pos+1);
	dfs(id+1,r,pos+1);
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++ ) cin >> a[i];
	dfs(1,n,0);
	for(int i = 1; i <= n; i++) {
		cout << an[i] << " \n"[i==n];
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