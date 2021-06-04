#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+5;
int n,m;
int vis[maxn];
void solve()
{
	cin >> n;
	memset(vis,0,sizeof(vis));
	std::vector<int> a;
	std::vector<int> b;
	for(int i = 0; i < n; i++) {
		cin >> m;
		vis[m]++;
		b.push_back(m);
	}
	for(int i = 1; i <= 2*n; i++) {
		if(!vis[i]) {
			a.push_back(i);
		}
	}
	auto check = [&](int mid){
		for(int i = 0; i < mid; i++) {
			if(b[i] > a[n-mid+i]) {
				return 1;
			}
		}
		for(int i = 0; i < n-mid;  i++) {
			if(b[i+mid] < a[i]) {
				return 2;
			}
		}
		return 0;
	};
	int l = 0,r = n;
	int L = n;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(check(mid) != 2) {
			L = mid;
			r = mid - 1;
		}
		else {
			l = mid+1;
		}
	}
	l = 0; r = n;
	int R = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid) != 1) {
			R = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << (R-L + 1) << "\n";
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