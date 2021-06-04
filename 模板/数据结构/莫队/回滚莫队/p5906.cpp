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

const int maxn = 2e5 + 10;

int n,m;
int a[maxn],bl,cnt[maxn],ed[maxn],st[maxn],ed2[maxn],R[maxn],b[maxn];
int an[maxn];
struct node{
	int l,r;
	int pos;
}q[maxn];
bool cmp(node x,node y) {
	return (b[x.l]==b[y.l])?x.r<y.r:b[x.l]<b[y.l];
}
int main() {
	// freopen("P5906_1_1.txt","r",stdin);
	cin >> n;
	std::vector<int> v;
	bl = sqrt(n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
		b[i] = (i-1)/bl + 1;
	}
	for(int i = 1; i <= b[n]; i++) {
		R[i] = (i == b[n] ? n : i * bl);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(v),a[i]) - v.begin() + 1;
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
	}
	sort(q+1,q+1+m,cmp);
	int l = 0,r = 0,block = 0,mx = 0;
	for(int i = 1; i <= m; i++) {
		int ql = q[i].l;
		int qr = q[i].r;
		if(b[ql] == b[qr]) {
			mx = 0;
			for(int j = ql; j <= qr; j++) {
				st[a[j]] = 0;
			}
			for(int j = ql; j <= qr; j++) {
				if(!st[a[j]]) st[a[j]] = j;
				mx = max(mx,j - st[a[j]]);
			}
			for(int j = ql; j <= qr; j++) {
				st[a[j]] = 0;
			}
			an[q[i].pos] = mx;
			continue;
		}
		int now = b[ql];
		if(block != now) {
			mx = 0;
			for(int j = l; j <= r; j++) {
				st[a[j]] = ed[a[j]] = 0;
			}
			l = R[now];
			r = l - 1;
			block = now;
		}
		while(r < qr) {
			r++;
			if(!st[a[r]]) st[a[r]] = r;
			ed[a[r]] = r;
			mx = max(mx,r - st[a[r]]);
		}
		int p = l,mx1 = 0;
		while(p > ql) {
			p--;
			if(!ed2[a[p]]) ed2[a[p]] = p;
			mx1 = max(mx1,max(ed[a[p]],ed2[a[p]]) - p);
		}
		while(p < l) {
			ed2[a[p]] = 0;
			p++;
		}
		an[q[i].pos] = max(mx,mx1);
	}
	for(int i = 1; i <= m; i++) {
		cout << an[i] << "\n";
	}
	return 0;
}