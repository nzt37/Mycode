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
	// std::vector<int> a(n+1);
	std::map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		mp[p]++;
	} 
	int a,b;
	for(int i = 0; i < 101; i++) {
		if(mp[i] == 0) {
			a = i;
			break;
		}
		else {
			mp[i]--;
		}
	}
		// int a,b;
	for(int i = 0; i < 101; i++) {
		if(mp[i] == 0) {
			b = i;
			break;
		}
		else {
			mp[i]--;
		}
	}

	cout << a + b << "\n";
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