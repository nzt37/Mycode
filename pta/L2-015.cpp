#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4+5;
int a[maxn],b[maxn];
double sum[maxn];
int main()
{
    int n, k, m;
    cin >> n >> m >> k;
    memset(b,0x3f,sizeof(b));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int p;
            cin >> p;
            a[i] = max(a[i],p);
            b[i] = min(b[i],p);
            sum[i] += p;
        }
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = (sum[i] - a[i] - b[i])*1.0/(m-2);
    }
    sort(sum+1,sum+1+n);
    for(int i = n-k+1; i < n; i++) {
        cout << fixed << setprecision(3) <<  sum[i] << " ";
    }
    cout << fixed << setprecision(3) <<  sum[n] << " ";
    return 0;
}