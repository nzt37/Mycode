#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,m;
int a[maxn];
void solve()
{
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum == 0) {
		cout << "NO" << endl;
		return;
	}
	else {
		cout << "YES" << endl;
		sort(a+1,a+1+n);
		int cnt = 0,flag = 0;;
		for(int i = 1; i <= n; i++) {
			cnt += a[i];
			if(cnt == 0) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			for(int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			return;
		}
		else {
			for(int i = n; i >= 1; i--) {
				cout << a[i] << " ";
			}
			cout << endl;
			return;
		}
	}
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