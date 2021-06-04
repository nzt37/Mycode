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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
bool check(int x) {
	int l =a[1];
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i] - l < x) {
			ans++;
		}
		else {
			l = a[i];
		}
		if(ans > n-m) return false;
	}
	// return (ans <= m ? true : false);
	return true;
}
int main() {
	cin >> n >> m;	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l = 1,r = a[n] - a[1];
	int ans = 0 ;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			ans = max(ans,mid);
			l = mid+1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}