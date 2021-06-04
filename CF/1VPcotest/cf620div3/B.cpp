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
string s[maxn];

void solve() {
	cin >> n >> m;
	int p;
	map<string,int> mp;
	vector<string> v;
	int flag = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		string an = s[i];
		reverse(an.begin(),an.end());
		if(an == s[i] && !flag) {
			flag = 1;
			p = i;
		}
		else {
			if(mp[an]) {
				v.PB(s[i]);
				v.PB(an);
				mp[an]--;
			}
			else mp[s[i]]++;
		}
		
	}
	if(v.empty()) {
		if(flag) {
			cout << s[p].size() << "\n";
			cout << s[p] << "\n";
			return;
		}
		else{
			cout << 0 << "\n";
			return;
		}
	}
    else {
    	if(flag) {
    		cout << (int)v.size()*m+m << "\n";
    		for(int i = 0; i < (int)v.size(); i++) {
    			if(i % 2 == 0)
    			cout << v[i];
    		}
    		cout << s[p];
    		for(int i = v.size()-1; i >= 0; i--) {
    			if(i & 1)
    			cout << v[i];
    		}
    		cout << "\n";
    	}
    	else {
    		cout << v.size()*m << "\n";
    		for(int i = 0; i < (int)v.size(); i++) {
    			if(i % 2 == 0)
    			cout << v[i];
    		}
    		// cout << s[p];
    		for(int i = v.size()-1; i >= 0; i--) {
    			if(i & 1)
    			cout << v[i];
    		}
    		cout << "\n";
    	}
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}