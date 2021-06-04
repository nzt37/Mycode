#include <bits/stdc++.h>

using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n;
    cin >> n;
    int ans = 0,sum = 0;
    while(sum < n) {
        ans++;
        sum+=ans;
    }
    if(sum - n == 1) {
        ans++;
    }
    cout << ans << endl;
    }
    return 0;
}