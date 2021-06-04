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
// #define mid ((r+l)>>1)
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
int a[maxn];
int cx(int pos)
{
	if(pos == 0 || pos == n + 1) return 1e9 + 4;
	cout << "? " << pos << endl;
	int x;
	cin >> x;
	fflush(stdout);
	return x;
}
void print(int pos)
{
	cout << "! " << pos << endl;
	fflush(stdout);
	exit(0);
}
void solve() {
	// int a;
	cin >> n;
	if(n == 1) {
		cout << "! " << 1 << "\n";
		return;
 	}
	a[1] = cx(1);
	a[2] = cx(2);
	a[n] = cx(n);
	a[n-1] = cx(n-1);
	if(a[1] < a[2]) {
		print(1);
	}
	if(a[n] < a[n-1]) {
		print(n);
 	}
	int l = 1,r = n;
	while(l != r) {
		int mid = (l + r) >> 1;
		
		int left = cx(mid - 1);
		int right = cx(mid + 1);
		int now = cx(mid);
		
		if (left > now && right > now) print(mid);
		
		else if (left < now) r = mid;
		else l = mid + 1;
	}
	print(l);
	return;
}
int main() {

	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}