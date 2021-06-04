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
#define int long long
const int maxn = 5e5 + 10;

int n,m;
int a[maxn];
signed main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	stack<pll> s;
	for(int i = 1; i <= n; i++) {
		int an = 0;
		while(!s.empty() && a[i] >= s.top().first) {
			if(s.top().first == a[i]) {
				an = s.top().second;
			}
			ans += s.top().second;
			s.pop();
		}
		if(!s.empty()) ans++;
		s.push(make_pair(a[i],an+1));
	}
	cout << ans << "\n";
	return 0;
}