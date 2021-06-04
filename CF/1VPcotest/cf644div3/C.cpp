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
int vis[101];
int a[maxn];
void solve() {
	cin >> n;
	// map<int,int> vis;
	CLR(vis,0);
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]]++;
		if(a[i] & 1) cnt1++;
		else cnt2++;
	}
	if(cnt2 % 2 == 0) {
		cout << "YES" << "\n";
	}
	else {
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[a[i]+1]) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "YES" : "NO" )<< "\n";
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