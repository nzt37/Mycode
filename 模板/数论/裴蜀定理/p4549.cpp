#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans = __gcd(ans,abs(a));

	}
	cout << ans << endl;
}