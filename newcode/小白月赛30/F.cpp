#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 6;
int a[maxn],vis[maxn];
int n,m;

signed main(){
    cin >> n;
    int maxx = 0,pos = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] >= maxx) {
            maxx = a[i];
            pos = i;
        }
    }
    int sum = 0;
    for(int i = pos+1; i <= n; i++) {
            sum += (maxx + a[i]);
    }
    for(int i = 1; i < pos; i++) {
        sum += (maxx + a[i]);
    }
    cout << sum << endl;
    return 0;
}