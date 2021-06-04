#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+5;
int n,m;
inline bool check(int x)
{
	int sum = x,flag = 0;
	while(x) {
		int cnt = x%10;
		x /= 10;
		if(cnt == 0) continue;
		if(sum % cnt != 0) return false;
	}
	 return true;
}
void solve()
{
	cin >> n;
 		for(int i = n; ; i++) {
 			if(check(i)) {
 				cout << i << endl;
 				return;
 			}
 		}   	
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
    while(T--) {
 		solve();
    }
    return 0;
}