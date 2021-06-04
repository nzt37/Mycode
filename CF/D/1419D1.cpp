#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+ 6;
int a[maxn],l[maxn],cnt;
int main() {
    int n;
    cin >> n;
    for(int  i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int m = n/2+1;
    int i;
    for( i = m;  i < n; i++) {
        l[cnt++] = a[i];
        l[cnt++] = a[i-n/2];
    }
    if(n & 1 ) {
        l[cnt++] = a[i];
    }
    else { 
        l[cnt++] = a[i];
        l[cnt++] = a[i-n/2];
    }
    int ans = 0;
    for(int i = 1; i < cnt; i++) {
        if(l[i] < l[i-1] && l[i] < l[i+1]) {
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < cnt; i++) {
        printf("%d ",l[i]);
    }
    return 0;
} 


// 1 3 2 2 4 5 4
// 1 2 3 4 5

