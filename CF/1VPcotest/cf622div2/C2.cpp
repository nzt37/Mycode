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
int a[maxn],l[maxn],r[maxn],an[maxn],ans[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		// l[i] = l[i-1] + a[i];
		// r[i] = r[i-1] + a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		while(cnt && a[i] < a[an[cnt]]) {
			cnt--;
		}
		int p = an[cnt];
		l[i] = l[p] + a[i] * (i - p);
		an[++cnt] = i;
	}
	cnt = 0;
	an[++cnt] = n + 1;
	for(int i = n; i >= 1; i--) {
		while(cnt && a[i] < a[an[cnt]]) {
			cnt--;
		}
		int p = an[cnt];
		r[i] = r[p] + a[i] * (p - i);
		an[++cnt] = i;
	}
	int mx = 0;
	int p = 0;
	for(int i = 1; i <= n; i++) {
		if(l[i] + r[i] - a[i] > mx) {
			mx = l[i] + r[i] - a[i];
			p = i; 
		}
	}
	mx = a[p];
	for(int i = p-1; i >= 1; i--) {
		if(a[i] > mx) {
			a[i] = mx;
		}
		mx = a[i];
	}
	mx = a[p];
	for(int i = p + 1; i <= n; i++) {
		if(a[i] > mx) {
			a[i] = mx;
		}
		mx = a[i];
	}
	for(int i = 1; i <= n; i++) {
		cout << r[i] << " \n"[i == n];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}