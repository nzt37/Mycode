#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long
void solve()
{
    int p,q;
    cin >> p >> q;
    if(p%q!=0){
        cout << p << endl;
        return;
    }
    int tmp = q;
    int maxx = -1;
    for(int i = 2; i*i <= tmp; i++){
        if(q % i == 0){
            while(q%i==0) q/=i;
            int tmp1 = p;
            while(tmp1 % tmp == 0) tmp1 /= i;
            maxx = max(maxx, tmp1);
        }
    }
    if(q > 1){
        int tmp1 = p;
        while(tmp1 % tmp == 0) tmp1 /= q;
        maxx = max(maxx,tmp1);
    }
    cout << maxx << endl;
}
signed main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
