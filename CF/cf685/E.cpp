#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e7 + 5;
int vis[maxn],a[maxn];
int tmpx,tmpy,tmpz,tmpw;
int main()
{
    int n;
    cin >> n;
    vis[0] = 1;
    for(int i = 2; i <= n; i++) {
        printf("XOR %d %d\n",1,i);
        fflush(stdout);
        int m;
        cin >> m;
        a[i] = m;
        if(vis[a[i]]) { tmpx = vis[a[i]],tmpy = i; }
        else { vis[a[i]] = i; }
        if(a[i] == 1) tmpz = i;
        if(a[i] == 2) tmpw = i;

    }
    if(tmpx) {
        printf("AND %d %d\n",tmpx,tmpy);
        fflush(stdout);
        int m;
        cin >> m;
        a[1] = a[tmpx] ^ m;
        for(int i = 2; i <= n; i++) {
            a[i] ^= a[1];
        }
    }
    else {
        printf("AND %d %d\n",1,tmpz);
        fflush(stdout);
        int m;
        cin >> m;
        printf("AND %d %d\n",1,tmpw);
        fflush(stdout);
        int k;
        cin >> k;
        if(k & 1) m++;
        a[1] = m;
        for(int i = 2; i <= n; i++) {
            a[i] ^= a[1];
        }
    }
    printf("! ");
    for(int i = 1; i <= n ; i++ ) {
        cout << a[i] << " ";
    }
    fflush(stdout);
    return 0;
}