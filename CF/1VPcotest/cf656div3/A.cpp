#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	std::vector<int> a(3);
	for(int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if(a[1] == a[2]) {
		puts("YES");
		printf("%d %d %d\n",a[1],a[0],a[0] );
	}
	else {
		puts("NO");
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