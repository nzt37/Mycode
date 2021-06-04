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
void solve() {
	cin >> n >> m;
	int len = (n + m);
	cin >> s + 1;
	if(n + m == 1) {
		if(s[1] == '?') {
			cout << (m ? '1' : '0') << "\n";
			return;
		}
		if((m && (s[1] == '1')) || (n && s[1] == '0')) {
			cout << s+1 << "\n";
			return;
		}
		else {
			cout << -1 << "\n";
			return;
		}
	}
	if((n & 1) && (m & 1)) {
		cout << -1 << "\n";
		return;
	}
	for(int i = 1,j = (n + m); i < j; i++,j--) {
		if(s[i] != '?' && s[j] != '?') {
			if(s[i] != s[j]) {
				cout << -1 << "\n";
				return;
			}
			if(s[i] == '0'){n-=2; }
			else{m-=2; }
			
		}
		else if(s[i] == '?' && s[j] != '?') {
			if(s[j] == '0') {
				if(!n) {cout << -1 << "\n"; return;}
				else { s[i] = '0'; n -= 2;}
			}
			else {
				if(!m) {cout << -1 << "\n"; return;}
				else { s[i] = '1'; m -= 2;}	
			}
		}
		else if(s[i] != '?' && s[j] == '?') {
			if(s[i] == '0') {
				if(!n) {cout << -1 << "\n"; return;}
				else { s[j] = '0'; n -= 2;}
			}
			else {
				if(!m) {cout << -1 << "\n"; return;}
				else { s[j] = '1'; m -= 2;}	
			}
		}
		if(n < 0 || m < 0) {
				// cout << n;
				cout << -1 << "\n";
				return;
		}
	}
	// cout << s+1 << "\n";
	// cout << n << m << "\n";
	for(int i = 1,j = len; i < j ; i++,j--) {
		if(s[i] == '?') {
			// cout << i << "csd\n";
			int flag = 0;
			if(m >= 2) {
				s[i] = s[j] = '1';
				m -= 2;
				flag = 1;
			}
			else if(n >= 2) {
				s[i] = s[j] = '0';
				n -= 2;
				flag = 1;
			}
			else { cout << -1 << "\n";return;}
		}
	}
	// cout << n << " csc " << m << "\n";
	if(((n + m) & 1)) {
		if(n + m > 1) {
			cout << -1 << "\n";
		}
		else {
			int p = len / 2 + 1;
			// cout << p << "\n";
			if((m == 1 && (s[p] == '1' || s[p] == '?')) || (n == 1 && (s[p] == '0' || s[p] == '?'))) {
				s[p] = (m ? '1' : '0');
				cout << s + 1 << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
	else
	cout << s + 1 << "\n";
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