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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;
#define int long long
const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
struct node{
	int w,id;
}e[maxn];
int l,r;
int vis[maxn];
void move(int i){
	while(!(a[l] % e[i].w) && l >= 1){
		l --;
		if(vis[l + 1] == 1)break;
	}
	while(!(a[r] % e[i].w) && r <= n){
		r ++;
		if(vis[r - 1] == 1)break;
	}
}
void solve() {
	cin >> n >> m;
	// int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] ;
		e[i].w = a[i];
		e[i].id = i;
		vis[i] = 0;
	}
	sort(e+1,e+1+n,[](node a,node b){
		return a.w < b.w;
	});
	ll ans = 0;
	int an = n-1;
	for(int i = 1; i <= n; i++) {
		if(e[i].w >= m) break;
		if(vis[e[i].id]) continue;
		l = e[i].id;
		r = e[i].id;
		move(i);
		l++;
		r--;
		for(int j = l; j <= r-1; j++) {
			vis[j]++;
			vis[j+1]++;
		}
		ans += (r-l) * e[i].w;
		an -= (r-l);
	}
	ans += an * m;
	cout << ans << "\n";

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}