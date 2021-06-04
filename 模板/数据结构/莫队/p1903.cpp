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

const int maxn = 1e6 + 10;

int n,m;
int w[maxn];
struct node{
	int l,r,pos,w,t;
}a[maxn],b[maxn];
int an1,an2,block;
int ans,Ans[maxn];
int cnt[maxn];
int belong[maxn];
bool cmp(node a,node b) {
	return (a.l / block) ^ (b.l / block) ? a.l / block < b.l / block : ((a.r / block) ^( b.r/block)) ? a.r / block < b.r / block : a.t < b.t ; 
}
int cmp1(node a, node b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.r] ^ belong[b.r]) ? belong[a.r] < belong[b.r] : a.t < b.t);
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int size = pow(n, 2.0 / 3.0);
	int bnum = ceil((double)n / size);
	for(int i = 1; i <= bnum; ++i) 
		for(int j = (i - 1) * size + 1; j <= i * size; ++j) belong[j] = i;
	for(int i = 1; i <= m; i++) {
		char c[100];
		int x,y;
		scanf("%s", c);
		if(c[0] == 'Q') {
			cin >> x >> y;
			// cin >> x >> y;
			a[++an1].l = x;
			a[an1].r = y;
			a[an1].pos = an1;
			a[an1].t = an2;
		}
		else if(c[0] == 'R'){
			cin >> x >> y;
			b[++an2].pos = x;
			b[an2].w = y;
		}
	}
	block=ceil(exp((log(n)+log(an1))/3));//分块大小
	sort(a+1,a+1+an1,cmp);
	// for(int i = 1; i <= n; i ++) {
	// 	cout << a[i].l << "\n";
	// }
	int time = 0;
	int l = 1,r = 0;
	for(int i = 1; i <= an1; i++) {
		int ql = a[i].l;
		int qr = a[i].r;
		int qt = a[i].t;
		while(l < ql) ans -= !--cnt[w[l++]];
		while(l > ql) ans += !cnt[w[--l]]++;
		while(r < qr) ans += !cnt[w[++r]]++;
		while(r > qr) ans -= !--cnt[w[r--]];
		while(time < qt) {
			++time;
			if(ql <= b[time].pos && b[time].pos <= qr) {
				ans -= !--cnt[w[b[time].pos]] - !cnt[b[time].w]++;
			}
				swap(w[b[time].pos],b[time].w);
		}
		while(time > qt) {
			if(ql <= b[time].pos && b[time].pos <= qr) {
				ans -= !--cnt[w[b[time].pos]] - !cnt[b[time].w]++;
			}
				swap(w[b[time].pos],b[time].w);
			--time;
		}
		Ans[a[i].pos] = ans;
	}
	for(int i = 1; i <= an1; i++) {
		cout << Ans[i] << "\n";
	}
	return 0;
}