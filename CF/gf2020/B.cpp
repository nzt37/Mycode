#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
int a[200];
bool check()
{
	if(*max_element(a,a+n) != 0) {
		return false;
	}
	return true;
}
void solve()
{
	int k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(k == 1) {
		if((count(a,a+n,*max_element(a,a+n))) != n ) {
			cout << -1 << "\n";
			return;
		}
		else {
			cout << 1 << "\n";
			return;
		}
	}
	m = 0;
	while(!check()) {
		int tmp = k;
		m++;
		std::vector<int> b(n);
		for(int i = 0; i < n ;i++) {
			if(i == 0) {
				tmp--;
			}
			else {
				if(a[i] != a[i-1]) {
					if(tmp == 0) break;
					else {tmp--;} 
				}

			}
			b.push_back(i);
		}
		for(auto j : b) {
			a[j] = 0;
		}
	}
	cout << m << "\n";

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