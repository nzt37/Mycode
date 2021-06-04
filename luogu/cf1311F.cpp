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
#define int long long
const int maxn = 2e5 + 10;

int n,m;
int b[maxn],p[maxn];
int c1[maxn],c2[maxn];
struct node{
	int x,v;
}a[maxn];
int lowbit(int x) { return x & -x; }
void add1(int x,int k) {
	for(int i = x; i <= n; i += lowbit(i)) {
		c1[i]++;
	}
}
int que1(int x) {
	int ans = 0 ;
	for(int i = x; i; i -= lowbit(i)) {
		ans += c1[i];
	}
	return ans;
}
void add2(int x,int k) {
	for(int i = x; i <= n; i += lowbit(i)) {
		c2[i] += k;
	}
}
int que2(int x) {
	int ans = 0 ;
	for(int i = x; i; i -= lowbit(i)) {
		ans += c2[i];
	}
	return ans;
}
pii v[maxn];
signed main() {
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		cin >> a[i].x;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i].v;
		b[i] = a[i].v;
	}
	sort(b+1,b+1+n);
	m = unique(b+1,b+1+n) - b - 1;
	for(int i = 1; i <= n; i++) {
		a[i].v = lower_bound(b+1,b+1+n,a[i].v) - b;
	}
	sort(a+1,a+1+n,[](node x,node y){
		return x.x < y.x;
	});
	// for(int i = 1; i <= n; i++) {
	// 	cout << a[i].v << " \n"[i == n];
	// }
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = que1(a[i].v);
		int sum = que2(a[i].v);
		ans += (cnt * a[i].x - sum);
		add1(a[i].v,1);
		add2(a[i].v,a[i].x);
	}
	cout << ans << "\n";

	return 0;
}