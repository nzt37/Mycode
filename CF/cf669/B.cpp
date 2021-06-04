#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5050;
int a[maxn][maxn],c[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> q;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            cin >> a[i][j];
        }
        q[a[i][1]] = i;
    }
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ;j++){
            cin >> c[j];
        }
        if(q.find(c[1]) != q.end()){
            for(int i = 1 ; i <= n ; i++ ){
                for(int j = 1 ; j <= m ; j++){
                    cout << a[q[c[i]]][j] << " ";
                }
                cout << endl;
            }
        }
    }
}
int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
