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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int que1(int i,int j) {
	cout << "? 1 " << i << " " << j << " " << n-1 << endl;
	int p;
	cin >> p;
	return p;
}
int que2(int i,int j) {
	cout << "? 2 " << i << " " << j << " " << 1 << endl;
	int p;
	cin >> p;
	return p;
}
int a[maxn];
void solve() {
	cin >> n;
	int t = n;
	for(int i = 1; i + 1<= n; i += 2) {
		int p = que1(i,i+1);
		if(p == n) {
			t = i + 1;
			break;
		}
		else if(p == n-1) {
			p = que1(i+1,i);
			if(p == n) {
				t = i;
				break;
			}
		}
	}
	a[t] = n;
	for(int i = 1; i <= n; i++) {
		if(i == t) continue;
		int p = que2(i,t);
		a[i] = p;
	}
	cout << "! ";
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
	}
	fflush(stdout);
}
int main() {	
	int T ;
	cin >> T;
	while(T--) {
		solve();
		// fflush(stdout);
	}	
	return 0;
}