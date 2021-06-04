#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin >> n;
    map<int,int>p;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        p[a]++;
    }
    int sum = 0;
    for(auto k = p.begin(); k != p.end(); k++) {
        if( k->second >= 3) {
            // int p = i->second;
            int i = k->second;
            sum += (i * (i-1) * (i-2)) / 6;
        } 
        int i = k->first;
        sum += (p[i] * p[i-1] * p[i+1]);
        if( k -> second >= 2) {
            sum += ((p[i] * (p[i]-1))/2*(p[i-1] + p[i-2] + p[i+1]+p[i+2]) );
        }
        if(p[i-1] == 0) p.erase(p.find(i-1));
        if(p[i-2] == 0) p.erase(p.find(i-2));
        if(p[i+1] == 0) p.erase(p.find(i+1));
        if(p[i+2] == 0) p.erase(p.find(i+2));
    }
    cout << sum << endl;
}
signed main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}