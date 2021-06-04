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

const int maxn = 3e5 + 10;

int n,m;
int a[maxn],cnt[maxn],an[maxn],t[maxn],Ans,p[maxn];
struct node{
	int l,r,pos;
}q[maxn];
int bl;
bool cmp (node a,node b) {
	return a.l/bl ^ b.l/bl ? a.l/bl < b.l/bl : a.r < b.r ;
}
void add(int i){
	t[cnt[a[i]]]--;
	t[++cnt[a[i]]]++;
	Ans=max(Ans,cnt[a[i]]);
}
void del(int i){
	t[cnt[a[i]]]--;
	if(cnt[a[i]]==Ans&&!t[cnt[a[i]]])Ans--;
	t[--cnt[a[i]]]++;
}
void solve() {
	cin >> n >> m;
	bl = sqrt(n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
		p[i] = q[i].r - q[i].l+1;
	}
	sort(q+1,q+1+m,cmp);
	int l = 1,r = 0;
	for(int i = 1; i <= m; i++) {
		int ql = q[i].l;
		int qr = q[i].r;
		while(l > ql) add(--l);
		while(r < qr) add(++r);
		while(l < ql) del(l++);
		while(r > qr) del(r--);
		an[q[i].pos] =  Ans;
		// cout << ans << "\n";
	}
	for(int i = 1; i <= m; i++) {
		cout << max(2 * an[i] - p[i],1) << "\n";
		
	}

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