#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+6;
int f[maxn],mp[2020][2020];
int find(int a)
{
    if(f[a] == a) return a;
    return f[a] = find(f[a]);
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
    int n, m ,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(c == 1) {
            merge(a,b);
        }
        mp[a][b] = mp[b][a] =  c;
    }
    for(int i = 1; i <= m; i++) {
        int a,b;
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        if(x == y && mp[a][b] == 1) {
            cout << "No problem!" << endl;
        } else if(mp[a][b] == 0 && x != y) {
            cout << "OK" << endl;
        } else if(mp[a][b] == -1 && x == y) {
            cout << "OK but..." << endl;
        }else if(x != y && mp[a][b] == -1) {
            cout << "No way" << endl;
        }
    }
    return 0;
}