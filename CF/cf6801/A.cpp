#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5 + 6;
int a[maxn], b[maxn];
bool cmp(int x,int y){
    return x > y;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1; j <= n; j++){
        cin >> b[j];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,cmp);
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] + b[i] > m){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("No\n");    
    }else{
        printf("Yes\n");
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
