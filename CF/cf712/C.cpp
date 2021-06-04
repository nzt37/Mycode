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
string s;
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
void solve() {
	cin >> n;
	cin >> s;
	string an = "";
	if(s[0] != '1' || s[n-1] != '1') {
		cout << "NO" << "\n";
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(i & 1) {
			an += '(';
		}
		else {
			an += ')';
		}
	}
	string tmp = "";
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			tmp += an[i];
		}
		else {
			if(an[i] == '(') {
				tmp += ')';
			}
			else {
				tmp += '(';
			}
		}
	}
	// cout << tmp << "\n";
	if(judge(tmp)) {
		cout << "YES" << "\n";
		cout << an << "\n";
		cout << tmp << "\n";
	}
	else {
		cout << "NO" << "\n";
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