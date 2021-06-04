#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
inline int ls(int p) {return(p<<1);}
inline int rs(int p) {return(p<<1|1);}
int n,m,a[maxn],x,y,cnt;
struct node{
    int val,l,r;
}t[maxn<<2];
void push(int p)
{
    t[p].val = max(t[ls(p)].val,t[rs(p)].val);
}
void build(int p,int l,int r)
{
    if(l == r) {
        t[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push(p);
}
void change(int p,int l,int r)
{
    if(l == r) {
        t[p].val = max(y,t[p].val);
        return;
    }
    int mid = (l+r)>>1;
    if(x <= mid) {
        change(ls(p),l,mid);
    }
    else {
        change(rs(p),mid+1,r);
    }
    push(p);
}
int query(int p,int l,int r)
{
    if(x <= l && y >= r) {
        return t[p].val;
    }
    int ansl = 0,ansr = 0;
    int mid = (l+r) >> 1;
    if(x <= mid) {
        ansl = max(ansl,query(ls(p),l,mid));
    }
    if(y > mid) {//左右都要更新
        ansr = max(ansr,query(rs(p),mid+1,r));
    }
    return max(ansl,ansr);
}

signed main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    char ch;
    while(m--) {
        cin >> ch >> x >> y;
        if(ch == 'Q') {
            printf("%lld\n",query(1,1,n));
        }
        else {
            change(1,1,n);
        }
    }
    return 0;
}
