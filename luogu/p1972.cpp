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

const int maxn = 1000119;
inline int lowbit(int x){
	return x&(-x);
}
int n,m;
int an[maxn],b[maxn],cnt[maxn],vis[maxn];
struct node{
	int l,r;
	int pos;
}a[maxn];
void add(int x,int k) {
	for(int i = x; i <= n; i += lowbit(i)) {
		cnt[i] += k;
	}
}
int que(int x) {
	int ans =0 ;
	for(int i = x; i ; i -= lowbit(i)) {
		ans += cnt[i];
	}
	return  ans;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].pos = i;
	}
	sort(a+1,a+1+m,[](node x,node y) {
		return x.r < y.r;
	});
	int p = 1;
	for(int i = 1; i <= m; i++) {
		for(int j = p; j <= a[i].r; j++) {
			if(vis[b[j]]) {
				add(vis[b[j]],-1);
			}
			add(j,1);
			vis[b[j]] = j;
		}
		p = a[i].r+1;
		an[a[i].pos] = que(a[i].r) - que(a[i].l-1);
	}
	for(int i = 1; i <= m; i++) {
		cout << an[i] << "\n";
	}
	return 0;
}