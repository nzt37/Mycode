#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 6;
int f[maxn],a[maxn],b[maxn],vis[maxn];
int n,k;
int find(int x)
{
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if(x != y) {
        f[x] = y;
    }

}
int main()
{
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i];
        merge(a[i],b[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(f[i] == i) {
            cnt++;
        }
    }
    //cout << "cnt " << cnt << endl;
    cin >> k;
    for(int j = 1; j <= k; j++) {

        for(int i = 0; i < n; i++) f[i] = i;
        int m;
        cin >> m;
        vis[m] = 1;
        for(int i = 1; i <= k; i++) {
            if(vis[a[i]] == 1 || vis[b[i]] == 1) continue;
            else merge(a[i],b[i]);
        }
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(f[i] == i && vis[i] == 0) {
                tmp++;
            }
        }
        if(tmp + 1 == cnt || tmp == cnt) {
            printf("City %d is lost!\n",m);
        } else {
            printf("Red Alert: City %d is lost!\n",m);
        }
        //cout << "tmp " << tmp << endl;
        cnt = tmp;
    }
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(f[i] == i) {
            cnt++;
        }
    }
    if(cnt == n) printf("Game Over.\n");
    return 0;
}
