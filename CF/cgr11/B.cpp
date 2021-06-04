#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,m;

void solve()
{
	int k;
	cin >> n >> k;
	string s;
	cin >> s;
	std::vector<int> p;
	std::vector<int> q;
	std::vector<int> v;
	// int ans = count(s.begin(),s.end(),'W');
	int ans = 0;
	int cnt = 0,o = 0;
	for(int i = 0,j; i < n; i = j) {
		for(j = i; j < n && s[i] == s[j]; j++);
		if(s[i] == 'L' && s[i-1] == 'W'){
			p.push_back(j-i);
			cnt++;
		}
		else if(s[i] == 'L') {
			q.push_back(j-i);
		}
		if(s[i] == 'W') {
			v.push_back(j-i);
		}
	}
	sort(p.begin(),p.end());
	sort(q.begin(), q.end());
	for(auto i: v) {
		ans += i*2-1;
	}
	cout << ans << endl;
	for(auto i : p) {
		if(k == 0) break;
		if(k >= i) {

			ans += i*2;
			k -= i; 
			//ans += 1;
		}
		else {
			ans += k * 2;
			k = 0;
			break;;
		}
	}
	cout << ans << "adas" << k << endl;
	for(auto i : q) {
		if(k == 0) break;
		if(k >= i) {
			ans += (i*2 - 1);
			k -= i;
			ans += 1;
		}
		else {
			ans += (k * 2 - 1);
			k = 0;
			break;
		}
	}
	cout << ans << endl;

}
int main() 
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