#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long 
const int maxn = 2e5 + 6;
int a,b[maxn];
struct node{
    int w,num;
}c[maxn];
bool cmp(node a,node b) {
    return a.w < b.w;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a <= m) {
            c[++cnt].w = a;
            c[cnt].num = i;
        }
    }
    int flag = 0;
    sort(c+1,c+1+cnt,cmp);
    for(int i = cnt; i >= 1; i--) {
        sum += c[i].w;
        if(sum >= (m+1)/2) {
            flag = i;
            break;
        }
    }
    if(!flag ) {
        cout << "-1" << endl;
        return;
    }
    cout << cnt - flag + 1  << endl;
    for(int i = cnt; i >= flag; i--) {
        cout << c[i].num << " ";
    }
    cout << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
