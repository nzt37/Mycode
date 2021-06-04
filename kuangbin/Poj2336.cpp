#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1010;
int f[maxn],x[maxn],y[maxn],c[maxn],vis[maxn];
int find(int x)
{
    if(x == f[x]) return x;
    return f[x] = find(f[x]);//路径压缩
}
double dis(int a,int b)//求距离
{
    return sqrt( (double)((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b])) );
}
void unite(int x,int y)//合并
{
    x=find(x);
    y=find(y);
    if(x==y)//根相同不用管
        return;
    f[x]=y;//若根不同，y并入x，则y的根为x，同理x也能并入y  这里随意
}
int main() {
    int n, d;
    cin >> n >> d;
    for(int i = 0 ; i < n ; i++){
        f[i] = i;
        cin >> x[i] >> y[i]; 
    }
    char s;
    int len = 0;
    while(cin >> s){
        if(s == 'O'){
            int a;
            cin >> a;
            a--;
            if(vis[a]) continue;
            vis[a] = 1;
            c[len++] = a;
            cout << a << endl;
            for(int i = 0 ; i < len ; i++){
                if(dis(c[i], a) <= (double)d){
                    f[find(c[i])] = find(a);
                }
            }
        }
        else{
            int a, b;
            cin >> a >> b;
            a--,b--;
            if(find(a) == find(b)){
                cout << "SUCCESS" << endl;
            }
            else{
                cout << "FAIL" << endl;
            }
        }

    }
    return 0;
}
