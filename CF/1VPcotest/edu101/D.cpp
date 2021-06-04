#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
struct node{
	int x,y;
}a[maxn];
void solve()
{
	cin >> n;
	int _n = n;
	int cnt = 0 ;
	for(int i = n-1; i >= 3; i--) {
		if(_n / i >= i ) {
			if(_n % i == 0) {
				_n /= i;
			}
			else {
				_n = (_n / i + 1);
			}
			a[++cnt].x = n;
			a[cnt].y = i;
		}
		a[++cnt].x = i;
		a[cnt].y = n;
	}
	while(_n >= 2) {
		if(_n % 2 == 0) {
			_n /= 2;
		}
		else {
			_n = (_n / 2 + 1);
		}
		a[++cnt].x = n;
		a[cnt].y = 2;
	}
	cout << cnt << "\n";
	for(int i = 1; i <= cnt; i++) {
		cout << a[i].x << " " << a[i].y << "\n";
	}
	return;
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