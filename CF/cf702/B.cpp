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
void solve() {
	cin >> n;
	// std::vector<int> a(n);
	int c[4] = {0};
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		c[a % 3]++ ;
	}
	int an = (c[0] + c[1] + c[2]) / 3;
	c[0] -= an;
	c[1] -= an;
	c[2] -= an;
    int ans = 0;
    // -1 -1 2
    // cout << c[0] << " " << c[1] << " " << c[2] << "\n";
   while(1) {
   		int flag = 0;
   		for(int i = 0; i < 3; i++) {
   			if(c[i] > 0) {
   				flag = 1;
   				c[(i+1)%3] += c[i];
   				ans += c[i];
   				c[i] = 0;
   			}
   		}
   		if(!flag) break;
   }
    cout << ans << "\n";
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