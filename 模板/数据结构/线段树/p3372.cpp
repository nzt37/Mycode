#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
inline int ls(int p){return p<<1;}//左儿子 
inline int rs(int p){return p<<1|1;}//右儿子
struct node{
    int l,r;//该节点维护的区间 
    long long pre,laze;//pre为该点维护的值,laze为懒标记 
}t[maxn*4];
int a[maxn+2];
void build(int p,int l,int r)
{
    t[p].l=l;t[p].r=r;//以p为编号的节点维护由l到r的区间; 
    if(l == r){
        t[p].pre = a[l];
        return ;
    }
    int mid = l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;//上传区间和 ; 
}
void pushdown(int p) //下传laze标记;
{
    if(t[p].laze){//如果懒标记不为零,就下传,并更新左右儿子值; 
        t[ls(p)].pre += t[p].laze*(t[ls(p)].r-t[ls(p)].l+1); 
        t[rs(p)].pre += t[p].laze*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].laze += t[p].laze;
        t[rs(p)].laze += t[p].laze;
        t[p].laze = 0;
    }
} 
void change(int p,int x,int y,int z  ) 
{
    if(x <= t[p].l  && y >= t[p].r ){//被覆盖的话，就对其进行修改
        t[p].pre += (long long) z*(t[p].r-t[p].l+1);
        t[p].laze += z;//打上懒标记
        return;
    } 
    pushdown(p);//如果发现没有被覆盖，那就需要继续向下找，考虑儿子所维护的区间可能因为懒标记的存在而没有修改，因此将懒标记下放
    int mid = t[p].l + t[p].r >>1;
    if(x <= mid) change(ls(p),x,y,z);//如果要修改的区间覆盖了左儿子，就修改左儿子
    if(y > mid) change(rs(p),x,y,z);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;//上传区间和 ; 
}
long long query(int p,int x,int y)
{
    if(x <= t[p].l  && y >= t[p].r){//如果被覆盖，就返回维护的值
        return t[p].pre;//下传懒标记，并查询左右儿子
    }
    pushdown(p);
    int mid = t[p].l+t[p].r>>1;
    long long ans = 0;
    if(x <= mid) ans += query(ls(p),x,y);
    if(y>mid) ans+= query(rs(p),x,y);//累加答案，返回左右儿子的和
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&a[i]);
    }
    cout << "dsad" << endl;
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int q,x,y,z;
        scanf("%d",&q);
        if(q==1){//区间改变操作 
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
        else {//查询操作 
            scanf("%d%d",&x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}

