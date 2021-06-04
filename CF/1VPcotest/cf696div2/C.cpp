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

const int maxn = 2001;

int n,m;
int a[maxn],cnt1[maxn],cnt2[maxn];
void solve() {
	 int n;
     cin >> n;
     n += n;
     for(int i = 1; i <= n; i++) {
     	cin >> a[i];
     }   
    sort(a+1,a+1+n);
	int flag = 0;
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		int  m = a[n];
		cnt = 0;
		flag = 0;
		cnt1[++cnt] = m;
		cnt2[cnt] = a[i];
		multiset<int> v;
		for(int j = 1; j < n; j++) {
			if(j!=i) v.insert(a[j]);
		} 
		multiset<int> :: iterator it1,it2;
		while(!v.empty()) {
			it1 = v.end();
			it1--;
			int t = *it1;
			v.erase(it1);
			it2 = v.find(m - t);
			if(it2 != v.end()) {
				cnt1[++cnt] = t;
				cnt2[cnt] = m-t;
				m = t;
				v.erase(it2);
			}
			else {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			break;
		}
	}
	if(flag) cout << "NO" << "\n";
	else {
		cout << "YES" << "\n";
		cout << cnt1[1] + cnt2[1] << "\n";
		for(int i = 1; i <= cnt; i++) {
			cout << cnt1[i] << " " << cnt2[i] << "\n";
		}
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