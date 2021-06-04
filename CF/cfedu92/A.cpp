#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int a[maxn],b[maxn],c[maxn],sum[maxn];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string ss = s.substr(0,s.size() - 6);
    long long m = atoi(ss.c_str());
    double ans;
    if(s[n-2] == 'G') {
        if(s[n-6] == 'M')
         ans = m*1.0/pow(2,10);
        if(s[n-6] == 'K')
         ans = m*1.0/pow(2,10)/pow(2,20);
        if(s[n-6] == 'G')
         ans = m*1.0;
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    cout << pow(2,30) << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}