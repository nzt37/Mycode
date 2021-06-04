#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 6;
int vis[maxn],v[maxn];
struct node{
    int c,num,o;
}a[maxn];
bool cmp(node a,node b)
{
    return a.c <= b.c;
}
void solve()
{
    int n;
    cin >> n;
    int minn = 2000010,num = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) {
        cin >> a[i].c;
        a[i].num = i;
    }
    int cnt = 0;
    sort(a+1,a+1+n,cmp);
    for(int i = 1,j; i <= n; i = j) {
        for(j = i + 1; a[i].c == a[j].c; j++);
        v[i] = j-i;
        cnt++;
    }
    for(int i = 1; i <= cnt; i++) {
        if(v[i] == 1) {
            cout << i << endl;
        }
    }
    cout << -1 << endl;
    

}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}       