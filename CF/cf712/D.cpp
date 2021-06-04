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
void print(int a,int x,int y) {
	cout << a << " " << x << " " << y << "\n";
	cout.flush();
}
int main() {
	cin >> n;
	std::vector<pii> a,b;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if((i + j) & 1) {
				a.PB(make_pair(i,j));
			}
			else {
				b.PB(make_pair(i,j));
			}
		}
	}			
	for(int i = 1; i <= n*n; i++) {
		int x;
		cin >> x;
		if(x != 1 && !a.empty()) {
			print(1,a.back().first,a.back().second);
			a.pop_back();
		}
		else if(x != 2 && !b.empty()) {
			print(2,b.back().first,b.back().second);
			b.pop_back();
		}
		else if(a.size()) {
			print(3,a.back().first,a.back().second);
			a.pop_back();
		}
		else if(b.size()) {
			print(3,b.back().first,b.back().second);
			b.pop_back();
		}
	}
	return 0;
}