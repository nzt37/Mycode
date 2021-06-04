#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 6;
int f[maxn];
map<int,int> p[maxn];
int find(int a)
{
    if(f[a] == a) {
        return a;
    }
    return f[a] = find(f[a]);
}
void merge(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if(x == y) return;
    if(p[x].size() > p[y].size()) {
        f[y] = x;
        for(auto k : p[y]) {
            p[x][k.first] += k.second;
        }

     } else {
         f[x] = y;
         for(auto k : p[x]) {
             p[y][k.first] += k.second;
         }
     }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        p[i][a]++;
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1) {
            merge(b,c);
        }
        else {
            int k = find(b);
            cout << p[k][c] << endl;
        }
    }
    return 0;
}

