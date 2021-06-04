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
int c1[maxn],c2[maxn];
int lowbit(int x) { return (x  & -x); }
void add1(int x,int k) {
	for(int i = x; i <= m; i += lowbit(i)) {
		c1[i]++;
	}
}
int que1(int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) {
		ans += c1[i];
	}
	return ans;
}
void add2(int x,int k) {
	for(int i = x; i <= m; i+= lowbit(i)) {
		c2[i] += k;
	}
}
int que2(int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) {
		ans += c2[i];
	}
	return ans;
}
struct node{
	int v,x;
}a[maxn];
signed main() {
	cin >> n;	
	for(int i = 1; i <= n; i++) {
		cin >> a[i].v >> a[i].x;
		m = max(a[i].x,m);
	}
	sort(a+1,a+1+n,[](node a,node b){
		return a.v < b.v;
	});
	ll ans = 0;
	int p = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = que1(a[i].x);
		int sum = que2(a[i].x);
		ans += (cnt * a[i].x - sum) * a[i].v;
		ans += (p - sum - (i - cnt - 1)*a[i].x) * a[i].v;
		add1(a[i].x, 1);
		add2(a[i].x,a[i].x);
		p += a[i].x;
	}
	cout << ans << "\n";
	return 0;
}