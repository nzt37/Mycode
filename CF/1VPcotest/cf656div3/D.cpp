#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
string s;
int dfs(int l,int r,char c)
{
	if(l == r) {
		return (s[l] != c) ;
	}
	int mid = (l + r) >> 1,ans1 = 0,ans2 = 0;
	for(int i = l; i <= mid ;i++) {
		if(s[i] != c) {
			ans1++;
		}
	}
	for(int i = mid + 1; i <= r; i++) {
		if(s[i] != c) {
			ans2++;
		}
	}
	return min(dfs(l,mid,c+1)+ans2,dfs(mid+1,r,c+1)+ans1);
}
void solve()
{
	cin >> n;
	
	cin >> s;
	cout << dfs(0,n-1,'a') <<  "\n";
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
