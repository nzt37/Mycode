#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +6;
int a[maxn],b[maxn];
int n,m;

void solve()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        a[p]++;
    }
    int flag = 0;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        if(a[b[i]]) {
            if(flag == 0) {
                cout << "YES" << endl;
               cout << "1" << " "<< b[i] << endl;
                flag = 1;
            }
        }
    }
    if(!flag) {
        cout << "NO" << endl;
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}