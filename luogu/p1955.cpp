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

const int maxn = 2e6 + 10;

int n,m;
int f[maxn<<2],su[maxn<<2];
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
struct node{
	int x,y,e;
}a[maxn];
void  merge(int a,int b) {
	int x = find(a);
	int y = find(b);
	if(x != y) {
		f[x] = y;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= 2 * n; i++) f[i] = i;
		int flag = 0,cnt = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].e;
			su[++cnt] = a[i].x;
			su[++cnt] = a[i].y;
		}	
		sort(su+1,su+1+cnt);
		int k = unique(su+1,su+1+cnt) - su;
		for(int i = 1; i <= n; i++) {
			a[i].x = lower_bound(su+1,su+1+k,a[i].x)-su;
			a[i].y = lower_bound(su+1,su+1+k,a[i].y)-su;
		}
		sort(a+1,a+1+n,[](node x,node y){
			return x.e > y.e;
		});
		for(int i = 1; i <= n; i++) {
			if(a[i].e) {
				merge(a[i].x,a[i].y);
			}
			else {
				if(find(a[i].x) == find(a[i].y)) {
					flag = 1;
					break;
				}
			}
		}
		cout << (flag ? "NO" : "YES") << "\n";
	}	
	return 0;
}