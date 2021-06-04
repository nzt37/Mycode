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

const int maxn = 3e6 + 10;

int n,m;
int a[maxn];
int check(int i) {
	if( i == n || i == 1) return 0;
	if(a[i] < a[i + 1] && a[i] < a[i-1]) return 1;
	if(a[i] > a[i + 1] && a[i] > a[i-1]) return 1;
	return 0;
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++ ) {
		cin >> a[i];
	} 
	int an = 0;
	for(int i = 2; i < n; i++) {
		if(check(i)) {
			an++;
		}
	}
	int cnt = 0;
	for(int i = 2; i < n; i++) {
		int ans = 0,ans1 = 0;
		if(check(i)) ans++;
		if(check(i-1)) ans++;
		if(check(i+1)) ans++;
		int t = a[i];
		a[i] = a[i-1];
		if(check(i)) ans1++;
		if(check(i-1)) ans1++;
		if(check(i+1)) ans1++;
		cnt = max(cnt,ans - ans1);
		ans1 = 0;
		a[i] = a[i+1];
		if(check(i)) ans1++;
		if(check(i-1)) ans1++;
		if(check(i+1)) ans1++;
		cnt = max(cnt,ans - ans1);
		a[i] = t;
	}
	cout << max(an - cnt,0) << "\n";
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