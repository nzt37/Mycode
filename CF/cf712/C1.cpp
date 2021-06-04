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
bool judge(string s) {
	stack<char> p;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			p.push('(');
		}
		else {
			if( p.empty() || p.top() != '(') {
				return false;
			}
			else {
				// return false;
				p.pop();
			}
		}
	}
	return true;
}
char s[maxn],a[maxn],b[maxn];
void solve() {
	cin >> n;
	cin >> s+1;
	std::vector<int> cnt_1,cnt_0;
	// std::vector<char> a,b;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			cnt_1.PB(i);
		}
		else cnt_0.PB(i);
	}
	// cout << cnt_1[0] << "\n";
	if(s[1] != '1' || s[n] != '1' || cnt_1.size() & 1) {
		cout << "NO" << "\n";
		return;
	}
	int r = cnt_1.size() - 1;
	for(int l = 0; l < r; l++,r--) {
		a[cnt_1[l]] = b[cnt_1[l]] = '(';
		a[cnt_1[r]] = b[cnt_1[r]] = ')';
	}
	for(int i = 0; i < cnt_0.size(); i++) {
		if(i & 1) {
			cout << cnt_0[i] << "\n";
			a[cnt_0[i]] = '(';
			b[cnt_0[i]] = ')';
		}
		else {
			a[cnt_0[i]] = ')';
			b[cnt_0[i]] = '(';
		}
	}
	cout << "YES" << "\n";
	for(int i = 1; i <= n; i++) {
		cout << a[i]  ;
	}
	cout << "\n";
	for(int i = 1; i <= n; i++) {
		cout << b[i] ;
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