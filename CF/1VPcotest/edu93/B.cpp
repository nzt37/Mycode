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
	string s;
	cin >> s;
	std::vector<int> v;
	for(int i=0,j=0; i < (int)s.size(); i=j) {
		for(j = i; j<(int)s.size()&&s[i]==s[j];j++);
			if(s[i] == '1') v.push_back(j-i);
	}
	sort(v.begin(),v.end(),[](int a,int b){
		return a > b;
	});
	int ans = 0;
	for(int i = 0; i < (int)v.size(); i++) {
		if(i%2==0) {
			ans += v[i];
		}
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