#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long
inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}
const int maxn = 1e5 + 6;
int a[maxn],n,mod;
int x,y,z;
int m;
struct node{
    int l,r;
    int val,add,mul;
}t[maxn<<4];
void push(int p) {t[p].val = (t[ls(p)].val+t[rs(p)].val)%mod;}
void build(int p,int l,int r)
{
    t[p].mul = 1;
    t[p].l = l, t[p].r = r;
    if(l == r) {
        t[p].val = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push(p);
    if(t[p].val > mod) t[p].val -= mod;
}
void pushdown(int p,int k)
{
    if(t[p].add || t[p].mul != 1) {
        t[ls(p)].val = ((t[ls(p)].val*t[p].mul)%mod+t[p].add*((k+1)>>1))%mod;
        t[rs(p)].val = ((t[rs(p)].val*t[p].mul)%mod+t[p].add*(k>>1))%mod;
        t[ls(p)].mul = (t[ls(p)].mul*t[p].mul)%mod;
        t[rs(p)].mul = (t[rs(p)].mul*t[p].mul)%mod;
        t[ls(p)].add = (t[ls(p)].add*t[p].mul+t[p].add)%mod;
        t[rs(p)].add = (t[rs(p)].add*t[p].mul+t[p].add)%mod;
        t[p].mul = 1;
        t[p].add = 0;
    }
}
void jia(int p,int l,int r,int val){
    if (x<=l && r<=y){
        t[p].add+=val;
        if (t[p].add>=mod) t[p].add-=mod;
        t[p].val=(t[p].val+(r-l+1)*val)%mod;
        return;
    }
    pushdown(p,r-l+1);
    int mid=l+r>>1;
    if (x<=mid) jia(p<<1,l,mid,val);
    if (mid<y) jia(p<<1|1,mid+1,r,val);
    push(p);
}
void addchange(int p,int l,int r,int z)
{
    if(x <= l && r <= y) {
        if(t[p].add >= mod) t[p].add -= mod;
        t[p].val =(t[p].val+z*(r-l+1))%mod;
        t[p].add += z;
        return;
    }
    pushdown(p,r-l+1);
    int mid = (l+r) >> 1;
    if(x <= mid) addchange(ls(p),l,mid,z);
    if(y > mid) addchange(rs(p),mid+1,r,z);
    push(p);
}
void mulchange(int p,int l,int r,int z)
{
    //if(x > t[p].r || y < t[p].l) return;
    if(x <= l && y >= r) {
        t[p].val = (t[p].val * z) % mod;
        t[p].add = (t[p].add * z) % mod;
        t[p].mul = (t[p].mul * z) % mod;
        return;
    }
    pushdown(p,r-l+1);
    int mid = (l+r) >> 1;
    if(x <= mid) mulchange(ls(p),l,mid,z);
    if(y > mid) mulchange(rs(p),mid+1,r,z);
    push(p);
}
int query(int p,int l,int r)
{
    if(x <= l && y >= r) {
        return t[p].val;
    }
    pushdown(p,r-l+1);
    int ans = 0;
    int mid = (l+r) >> 1;
    if(x <= mid) ans += query(ls(p),l,mid);
    if(y > mid) ans += query(rs(p),mid+1,r);
    if(ans > mod) ans-=mod;
    push(p);
    return ans;
}
signed main() {

    cin >> n >> mod;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    cin >> m;
    while(m--) {
        int t,g,c;
        cin >> t >> x >> y;
        if(t == 1) {
            cin >> z;
            mulchange(1,1,n,z);

        } else if(t == 2) {
            cin >> z;
            addchange(1,1,n,z);
            //cout << "dsad" << endl;
        }
        else {
            int an = query(1,1,n)%mod;
            printf("%lld\n",an);
        }
    }
    return 0;
}
