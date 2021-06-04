#include <iostream>
using namespace std;

int n,m;
const int maxn = 1e6 + 5;
int a[maxn],b[maxn],p[maxn],f[maxn],cnt;
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int j = 0;
    for(int i = 2; i <= m; i++) {
        while(j && b[i] != b[j+1]) j = p[j];
        if(b[i] == b[j+1]) j++;
        p[i] = j;
    }
    j = 0;
    for(int i = 1; i <= n; i++) {
        while(j && a[i] != b[j+1]) j = p[j]; 
        if(a[i] == b[j+1]) j++;
        if(j == m) {
            cout << i - m + 1 << endl;
            return;
        }
    }    
    cout << -1 << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
