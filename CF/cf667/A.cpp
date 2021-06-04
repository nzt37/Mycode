#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
void solve()
{
    int n;
    cin>>n;
    int l = n + 1,r ,o = 0;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&a[i]);
        if(a[i] == 1){
            if(l == n + 1) {
                l = i;
            }
            r = i;
            o++;
        }
    }
    if(l == r){
        puts("0");
    }
    else{
        cout<<(r-l+1-o)<<endl;
    }
}
int main() {
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}


