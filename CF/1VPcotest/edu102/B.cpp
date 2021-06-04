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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("qqglb")
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
void solve() {
	string s1,s2,s3,s4;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	s3 = s1;
	s4 = s2;
	int p = n * m / (__gcd(n,m));
	int a1 = p/n,a2 = p/m;
	a1--;
	a2--;
	// cout << a1 << " " << a2 << "\n";
	while(a1) {s3 += s1;a1--;}
	while(a2) {s4 += s2;a2--;}
	// cout << s1 << " "<< s2 << "\n";
	if(s3 == s4) {
		cout << s3 << "\n";
	}
	else {
		cout << -1 << "\n";
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
}