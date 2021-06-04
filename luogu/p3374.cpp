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

const int maxn = 5e5 + 10;
int lowbit(int x) {return (x &( -x));}
int n,m;
int a[maxn],c[maxn];

void add(int x,int k) {
	for(int i = x; i <= n; i+=lowbit(i)) {
		c[i] += k;
	}
}
int query(int x) {
	int sum = 0;
	for(int i = x; i ; i-= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		add(i,a[i]);
	}
	while(m--) {
		int x,y,z;
		cin >> x >> y >> z;
		if(x == 1) {
			add(y,z);
		}
		else {
			cout << query(z) - query(y - 1) << "\n";
		}
	}
	return 0;
}
/*
8 10
81 236 844 794 359 591 896 278 
1 8 -647
2 3 8
1 1 959
2 3 8
2 1 7
1 1 951
1 7 496
2 2 7
2 2 8
2 3 8
*/