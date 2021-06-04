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

const int maxn = 3e6 + 10;
struct node{
	int w,id;
}a[maxn],d[maxn];
int n,m;
int c[maxn],vis[maxn],b[maxn],id[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].w;
		a[i].id = i;
	}
	sort(a+1,a+1+n,[](node a,node b){
		return a.w < b.w;
	});
	for(int i = 2; i <= n; i++) {
		c[i] = (a[i].w - a[i-1].w);
	}
	for(int i = 2; i <= n; i++) {
		if(b[c[i]] == 0) b[c[i]] = i;
		else {
			if(b[c[i]] < i - 1) {
				cout << "YES" << "\n";
				int x1 = b[c[i]] - 1;
				int x2 = b[c[i]];
				cout << a[x1].id << " "<<a[i].id <<" " <<a[x2].id << " " << a[i-1].id << "\n"; 
				return;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j =  1; j <= i - 1; j++) {
			int tmp = a[i].w - a[j].w;
			if(d[tmp].w == 0) {
				d[tmp].w = j;
				d[tmp].id = i;
			}
			else {
				if(d[tmp].id < j) {
					int x1 = d[tmp].w;
					int x2 = d[tmp].id;
					cout << "YES" << "\n";
					cout << a[x1].id << " "<<a[i].id <<" " <<a[x2].id << " " << a[j].id << "\n"; 
					return;
				}
			}
		}
	}
	cout << "NO" << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}
// 1 2 5 6
//   3 4 5
//   1 3 1