#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int n,m;
struct node{
    int x,y;
}a[maxn];
void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    int cnt ,f = 0;;
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= m) cnt++;
        }
        if(cnt == n-1) {
            f = 1;
            break;
        }
    }
    if(!f) {
        cout << -1 << endl;
    }
    else cout << 1 << endl;
}
int main(){
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}