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
int sum[maxn],sum2[maxn],flag;
string s1,s2;
bool check(int l,int r) {
	string an1 = s1.substr(l,r-l+1);
	string an2 = s2.substr(l,r-l+1);
	// cout << an1 << "\n" << an2 << "\n";
	if(an1 == an2 ) {
		return true;
	}
	reverse(all(an2));
	if(an1 == an2 ) {
		return true;
	}
	return false;
}
std::vector<int> p;
void solve() {
	cin >> n;
	cin >> s1;
	cin >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	flag = 0;
	p.clear();
	p.PB(0);
	CLR(sum,0);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + (s1[i] == '1');
		if(sum[i] * 2 == i) p.PB(i);
	}
	for(int i = p.back()+1; i <= n; i++) {
		if(s1[i] != s2[i]) {
			cout << "NO" << "\n";
			return;
		}
	}
	for(int i = p.size()-1; i >= 1; i--) {
		if(!check(p[i-1]+1,p[i])) {
			cout << "NO" << "\n";
			return;
		}
	}
	cout << "YES" << "\n";
	
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