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

const int maxn = 5e4 + 10;

int n,m;
int f[maxn*3];
inline int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int a = find(x);
	int b = find(y);
	if(a != b) {
		f[a] = b;
	}
}
int main() {
	cin >> n >> m;
	int ans =0 ;
	for(int i = 1; i <= 3*n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int k,x,y;
		cin >> k >> x >> y;
		if((x > n || y > n)) { ans++; continue;}
		if(k == 1) {
			if(find(x+n) == find(y) || find(x + 2*n) == find(y)) {ans++;continue;}
			else {
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		} 
		else {
			// if(x == y?)
			if(find(x) == find(y) || find(x+2*n) == find(y)) {ans++;continue;}
			else {
				merge(x,y+2*n);
				merge(x+n,y);
				merge(x+2*n,y+n);
			}
		}
	}		
	cout << ans << "\n";
	return 0;
}