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
char a[maxn];
char b[maxn];
void solve() {
	cin >> n >> m;
	cin >> a + 1;
	for(int i = 1; i <= n; i++) b[i] = a[i];
	a[0] = b[0] = a[n+1] = b[n+1] = '0';
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			if(b[i] == '0')
			if((a[i-1] == '1') ^ (a[i+1] == '1')) {
				b[i] = '1';
			}
		}
		int flag = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i] != b[i]) {flag = 0;break;}
		}
		if(flag) break;
		for(int i = 1; i <= n; i++) {
			a[i] = b[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << "\n";
	

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