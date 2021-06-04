#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5050;

void solve()
{

        int n;
		scanf("%d",&n);
		if (n == 1)
        cout << 0 << endl;
		else if (n == 2)
        cout << 1 << endl;
		else if (n == 3)
        cout << 2 << endl;
		else if (n % 2 == 0)
        cout << 2 << endl;
		else printf("%d\n", 3);
	

}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}