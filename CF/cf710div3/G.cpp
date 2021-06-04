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
char s[maxn];
// std::vector<int> a[maxn];
char ans[maxn],vis[maxn];
void solve() {
	// string s;
	cin >> (s + 1);
	CLR(vis,0);
	int n = strlen(s+1);
	std::map<char, int> mp;
	for(int i = 1; i <= n; i++) {
		mp[s[i]] = i;
	}
	stack<char> p;
	int j = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[s[i] - '0']) continue;
		while(s[i] > ans[j] && mp[ans[j]] > i) {
			vis[ans[j--] - '0'] = 0;
		}
		ans[++j] = s[i];
		vis[s[i] - '0'] = 1;
	}
	for(int i = 1; i <= j; i++) {
		cout << ans[i] ;
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