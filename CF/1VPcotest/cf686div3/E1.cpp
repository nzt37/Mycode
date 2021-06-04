#include <bits/stdc++.h>
using namespace std;
long long t, n, u, v, du[200005], ans, siz[200005], tmp;
bool vis[200005];
vector<long long> e[200005];
queue<long long> tpo, emp;
void findSIZE(int dep, int fa)
{
    siz[dep] = 1;
    for (int i = 0; i < e[dep].size(); i++)
    {
        if (e[dep][i] != fa)
        {
            findSIZE(e[dep][i], dep);
            siz[dep] += siz[e[dep][i]];
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            du[i] = 0;
            siz[i] = 0;
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            ++du[u];
            ++du[v];
        }
        tpo = emp;
        for (int i = 1; i <= n; i++)
            if (du[i] == 1)
                tpo.push(i);
        while (tpo.size())
        {
            int tp = tpo.front();
            tpo.pop();
            for (int i = 0; i < e[tp].size(); i++)
                if (--du[e[tp][i]] == 1)
                    tpo.push(e[tp][i]);
        }
        for (int i = 1; i <= n; i++)
            if (du[i] > 1)
               {
               	 vis[i] = 1;
               	 // cout << i << " ";
               }
        for (int i = 1; i <= n; i++)
            if (vis[i])
            {
                tmp = 0;
                for (int j = 0; j < e[i].size(); j++)
                {
                    if (!vis[e[i][j]])
                    {
                        findSIZE(e[i][j], i);
                        tmp += siz[e[i][j]];
                        cout << tmp << "\n";
                    }
                }
                ans += tmp;
                ans += tmp * (tmp - 1) / 2;
                // cout << tmp << "\n";
            }
        cout << n * (n - 1) - ans << endl;
    }
}