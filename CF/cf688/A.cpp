#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int a[maxn],b[maxn];
int n,m;
void solve()
{

    cin >> n >> m;
    set<int > an;
    int ans = 0;
    for(int i = 1; i <= n+m; i++) {
        int p;
        cin >> p;
        if(an.count(p)) {
            ans++;
        }else {
            an.insert(p);
        }
    }
    cout << ans << endl;

}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
