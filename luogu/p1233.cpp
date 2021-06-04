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
struct node{
	int x,y;
}a[maxn];
int p[maxn];
int main() {
	cin >> n;	
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a+1,a+1+n,[](node a,node b){
		if(a.x != b.x) return a.x > b.x;
		else {
			if(a.x == b.x) {
				return a.y > b.y;
			}
		}
	});
	// int len = 1;
	int ans = -1;
	p[1] = a[1].y;
	int len = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i].y > p[len]) {
			p[++len] = a[i].y;
		}
		else {
			int m = lower_bound(p+1,p+1+len,a[i].y) - p;
			p[m] = a[i].y;
		}
	}
	cout << len << "\n";
	return 0;
}
// 9 5 1 4 