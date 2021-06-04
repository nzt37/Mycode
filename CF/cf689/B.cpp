#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[550][550];
int ans;
int f[550][550];
void solve()
{
    cin >> n >> m;
    memset(f,0,sizeof(f));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> s[i][j];
            if(s[i][j] == '*') {
                f[i][j]++;
            } 
        }
    }
    ans = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '*') {
                f[i][j] += min(f[i+1][j],min(f[i+1][j-1],f[i+1][j+1]));
                ans += f[i][j];
            }
            
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