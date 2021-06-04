#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,c0,c1,h;
    string s;
    cin >> n >> c0 >> c1 >> h;
    int cnt1 = 0,cnt0 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') cnt1++;
        else {
            cnt0++;
        }
    }
    cout << min(n*c1+cnt0*h,n*c0+cnt1*h) << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}