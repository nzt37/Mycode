#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    map<int,int> cnt;
    for(int i:s) {
        ++cnt[i];
    }
    vector<int >a;
    for(auto i : cnt) {
        a.push_back(i.second);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans = n - a[0];
    
    for(int i = '0'; i <= '9'; i++) {
        for(int j = '0'; j <= '9'; j++) {
            int l = 0;
            string c{char(i),char(j)};
            for(int x : s) {
                if( c[l%2] == x) {
                    l++;
                }
            }
            if( l & 1) l--;
             ans = min(ans,n-l);
        }
    }
    
    cout << ans << endl;


}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}