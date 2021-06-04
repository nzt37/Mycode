#include <bits/stdc++.h>

using namespace std;
const int maxn = 40;
int pre[maxn],in[maxn];
struct node{
    int l,r;
}a[maxn];
int build(int la,int ra,int lb,int rb)
{
    if(la > ra) return -1;
    int rt = pre[lb];
    int pos1 = la;
    while(in[pos1] != rt) pos1++;
    int pos2 = pos1 - la;
    a[rt].l = build(la,pos1-1,lb+1,lb+pos2);
    a[rt].r = build(pos1+1,ra,lb+pos2+1,rb);
    return rt;  

}
vector<int> v;
void bfs(int rt)
{
    queue<int> p;
    p.push(rt);
    while(!p.empty()) {
        int m = p.front();
        p.pop();
        v.push_back(m);
        if(a[m].r != -1) {
            p.push(a[m].r);
        }
        if(a[m].l != -1) {
            p.push(a[m].l); 
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    int rt = build(0,n-1,0,n-1);
    bfs(rt);
    for(int i = 0; i < (int)v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size()-1];
    return 0;
}