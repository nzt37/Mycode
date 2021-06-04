#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn],pre[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (pre[i-1] ^ a[i]);
    }
    if(n > 96) {
        cout << 1 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for(int l = 1; l <= n; l++) {
        for(int r = l + 1; r <= n; r++) {
            for(int k = l; k < r; k++) {
                int tmp1 = pre[k] ^ pre[l-1];
                int tmp2 = pre[k] ^ pre[r];
                if(tmp1 > tmp2) {
                    ans = min(ans,r-l-1);
                }
            }
        }
    }
    printf("%d\n",ans == INT_MAX ? -1 : ans);
    return 0;
}
/*
    01 10 11 100 101 110 111 1110  
*/