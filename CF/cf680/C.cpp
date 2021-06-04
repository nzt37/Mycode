#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int inf = 1e8+6;
int a[220];
int f[1010][1010];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);

    memset(f,0x3f,sizeof(f));
    for(int i = 0 ; i <= 3*n ; i++) f[0][i] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= 2*n ; j++){
            for(int k = i-1 ; k < j ; k++){
                f[i][j] = min(f[i][j],f[i-1][k] + abs(a[i]-j));
                cout << i << " " << j << " " << f[i][j]<<" "<<k<<" "<<f[i-1][k] << " " << abs(a[i]-j)<< endl;
            }
        }
    }
    int minn = inf;
    for(int i = n ; i <= 3*n ; i++){
        minn = min(minn, f[n][i]);
    }
    cout << minn << endl;;	
}
int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}


