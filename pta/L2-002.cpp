#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5 + 6;
struct node{
    int a,next;
    int c;
}v[maxn],m[maxn],k[maxn];
map<string, int >q;
map<int, string>p;
map<int, int>vis;
int main() {
    int s;
    int n;
    cin >> s;
    cin >> n;
    int cnt = 0,num = 0;
    for(int i = 1; i <= n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        v[x].a = x;
        v[x].c = y;
        v[x].next = z;
    }
    for(int i = s ; i != -1 ; i = v[i].next){
        if(!vis[abs(v[i].c)]){
            vis[abs(v[i].c)] = 1;
            m[++cnt] = v[i];
        }
        else{
            k[++num] = v[i];
        }
    }
    for(int i = 1; i <= cnt; i++){
        if(i != cnt)
            printf("%05d %d %05d\n",m[i].a,m[i].c,m[i+1].a);
        else
            printf("%05d %d -1\n",m[i].a,m[i].c);

    }
    for(int i = 1; i <= num; i++){
        if(i != num)
            printf("%05d %d %05d\n",k[i].a,k[i].c,k[i+1].a);
        else
            printf("%05d %d -1\n",k[i].a,k[i].c);

    }
    return 0;
}
