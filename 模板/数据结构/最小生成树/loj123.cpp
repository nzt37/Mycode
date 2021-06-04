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

const int maxn = 2e6 + 10;

int n,m;
int f[maxn];
struct node{
	int u,v,w;
}e[maxn<<1];
ll ans = 0;
int find(int x) {
	return f[x] == x ? x : (f[x] = find(f[x]));
}
void krusal() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if(find(u) != find(v)) {
			cnt++;
			ans += e[i].w;
			f[find(u)] = find(v);
		}
		if(cnt == n-1) break;
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e+1,e+1+m,[](node a,node b){
		return a.w < b.w;
	});
	krusal();
	cout << ans << "\n";
	return 0;
}