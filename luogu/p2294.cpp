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
int v[maxn],f[maxn];
int flag = 1;
inline int find(int x) {
	if(f[x] == x) return x;
	int t = find(f[x]);
	v[x] += v[f[x]];
	return f[x] = t;
} 
void merge(int x,int y,int w) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fy] = fx;
		// v[x] = -v;
		v[fy] = v[x]-v[y] + w;
	}
	else {
		if(v[y] - v[x] != w) {
			flag = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		flag = 1;
		for(int i = 0; i <= n; i++) f[i] = i,v[i] = 0;
		for(int i = 1; i <= m; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			merge(x-1,y,z);
		}
		cout << (flag == 1 ? "true" : "false") << "\n";
	}	
	return 0;
}