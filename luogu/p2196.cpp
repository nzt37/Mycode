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
int vis[23][23];
int f[maxn],pre[maxn];
void print(int t) {
	if(t == 0) return;
	cout << t << " ";
	print(pre[t]);
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for(int i = 1; i < n; i++) {
		for(int j = i+1; j <= n; j++) {
			cin >> vis[i][j];
		}
	}
	f[n] = a[n];
	for(int i = n-1; i >= 1; i--) {
		for(int j = i+1; j <= n ; j++) {
			if(vis[i][j] && f[j] > f[i]) {
				f[i] = max(f[i],f[j]);
				pre[i] = j;
			}
		}
		f[i] += a[i];
	} 
	int ans = -1;
	int t = -1;
	for(int i = 1; i <= n; i++) {
		if(f[i] > ans) {
			ans = f[i];
			t = i;
		}
		// ans = max(ans,f[i]);
	}
	print(t);
	cout << "\n";
	cout << ans << "\n";
	return 0;
	
}