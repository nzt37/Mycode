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
//     1
//  110
// 1000
bool judge(int n,int m) {
	int a = 0,b = 0;
	for(int i = 0; i < 32; i++) {
		if(n >> i & 1) a++;
		if(m >> i & 1) b++;
		if(b) {
			if(!a) return false;
			else a--,b--; 
		}
	}
	return true;
}
void solve() {
	cin >> n >> m;
	if(m < n || !judge(n,m)) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}
//  110
// 1000