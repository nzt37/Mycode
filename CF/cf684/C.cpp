#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 120;
struct node{
    int a, b, c, d, e, f;
}p[10005];
int a[maxn][maxn];
int main()
{
    int n,m,t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        int k = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%1d", &a[i][j]);
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= m; j++)
                if (a[i - 1][j - 1] || a[i][j - 1])
                {
                    if (a[i - 1][j - 1] && a[i][j - 1])
                    {
                        a[i - 1][j - 1] = a[i][j - 1] = 0;
                        if (a[i - 1][j])
                            p[++k] = (node){i - 1, j - 1, i, j - 1, i - 1, j}, a[i - 1][j] ^= 1;
                        else
                            p[++k] = (node){i - 1, j - 1, i, j - 1, i, j}, a[i][j] ^= 1;
                    }
                    else if (!a[i - 1][j - 1])
                        p[++k] = (node){i, j - 1, i, j, i - 1, j}, a[i][j - 1] = 0, a[i][j] ^= 1, a[i - 1][j] ^= 1;
                    else
                        p[++k] = (node){i - 1, j - 1, i, j, i - 1, j}, a[i - 1][j - 1] = 0, a[i - 1][j] ^= 1, a[i][j] ^= 1;
                }
        for (int j = 2; j <= m; j += 2)
        {
            if (a[n][j - 1] && a[n][j])
            {
                p[++k] = (node){n - 1, j - 1, n - 1, j, n, j - 1};
                p[++k] = (node){n - 1, j - 1, n - 1, j, n, j};
                a[n][j - 1] = a[n][j] = 0;
            }
            else if (a[n][j - 1] || a[n][j])
            {
                if (a[n][j - 1])
                {
                    p[++k] = (node){n - 1, j - 1, n - 1, j, n, j - 1};
                    p[++k] = (node){n - 1, j - 1, n, j - 1, n, j};
                    p[++k] = (node){n - 1, j, n, j - 1, n, j};
                    a[n][j - 1] = 0;
                }
                else
                {
                    p[++k] = (node){n - 1, j - 1, n - 1, j, n, j};
                    p[++k] = (node){n - 1, j - 1, n, j - 1, n, j};
                    p[++k] = (node){n - 1, j, n, j - 1, n, j};
                    a[n][j] = 0;
                }
            }
        }
        for (int i = 2; i <= n; i += 2)
        {
            if (a[i - 1][m] && a[i][m])
            {
                p[++k] = (node){i - 1, m - 1, i, m - 1, i - 1, m};
                p[++k] = (node){i - 1, m - 1, i, m - 1, i, m};
                a[i - 1][m] = a[i][m] = 0;
            }
            else if (a[i - 1][m] || a[i][m])
            {
                if (a[i - 1][m])
                {
                    p[++k] = (node){i - 1, m - 1, i - 1, m, i, m - 1};
                    p[++k] = (node){i - 1, m - 1, i - 1, m, i, m};
                    p[++k] = (node){i, m - 1, i - 1, m, i, m};
                    a[i - 1][m] = 0;
                }
                else
                {
                    p[++k] = (node){i - 1, m - 1, i, m - 1, i, m};
                    p[++k] = (node){i - 1, m - 1, i - 1, m, i, m};
                    p[++k] = (node){i - 1, m, i, m - 1, i, m};
                    a[i][m] = 0;
                }
            }
        }
        if (a[n][m])
        {
            p[++k] = (node){n - 1, m - 1, n, m - 1, n, m};
            p[++k] = (node){n - 1, m - 1, n - 1, m, n, m};
            p[++k] = (node){n, m - 1, n - 1, m, n, m};
        }
        printf("%d\n", k);
        for (int i = 1; i <= k; i++)
            printf("%d %d %d %d %d %d\n", p[i].a, p[i].b, p[i].c, p[i].d, p[i].e, p[i].f);
    }
    return 0;
}

