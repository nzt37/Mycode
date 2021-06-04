#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
void solve() {
	cin >> n;
	std::vector<int> a(n),b(n),c(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	cout << a[0] << " ";
	int pre = a[0];
	for(int i = 1; i < n - 1; i++) {
		if(a[i] != pre) {
			cout << a[i] << " \n"[i == n-1]; 
			pre = a[i];
		}
		else {
			if(b[i] != pre) {
				cout << b[i] << " \n";
				pre = b[i];
			}
			else {
				if(c[i] != pre) {
					cout << c[i] << " \n"[i == n-1]; 
					pre = c[i];
				}
			}
		}
	}
	if(a[n-1] != a[0] && (a[n-1] != pre)) {
			cout << a[n-1] << "\n"; 
			pre = a[1];
		}
		else {
			if(b[n-1] != a[0] && (b[n-1] != pre)) {
				cout << b[n-1] << "\n"; 
				pre = b[1];
			}
			else {
				if(c[n-1] != a[0] && c[n-1] != pre) {
					cout << c[n-1] << "\n"; 
					pre = c[1];
				}
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