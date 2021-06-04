#include <bits/stdc++.h>
using namespace std;
int n,x,y,cont;
const int INF=0x7fffffff;;
struct node{
    int val,ls,rs,cnt,siz;
}tree[100005];
inline int read()
{
    int r=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        r=(r<<3)+(r<<1)+(ch^48);
        ch=getchar();
    }
    return r*w;
}
void add(int x,int v)//插入 
{
    tree[x].siz++;
    if(tree[x].val == v){
        tree[x].cnt++;
        return;
    } 
    if(v < tree[x].val){
        if(tree[x].ls != 0)
            add(tree[x].ls,v);
        else
        {
            cont++;
            tree[cont].cnt = 1;
            tree[cont].siz = 1;
            tree[cont].val = v;
            tree[x].ls = cont;
        }
    }
    if(v > tree[x].val){
        if(tree[x].rs != 0)
            add(tree[x].rs,v);
        else
        {
            cont++;
            tree[cont].cnt = 1;
            tree[cont].siz = 1;
            tree[cont].val = v;
            tree[x].rs = cont;
        }
    } 
}
//找前驱; 
int queryfr(int x,int val,int ans)//x是当前的节点的下标，val是要找前驱的值，ans是目前找到的比val小的数的最大值。
{
    if(tree[x].val >= val){///如果当前值大于val，就说明查的数大了，所以要往左子树找, 
        if(tree[x].ls == 0)
        {
            return ans;
        }
        else
            return queryfr(tree[x].ls,val,ans);
    }
    else//否则去右子树找, 
    {
        if(tree[x].rs == 0)
        {
            if(tree[x].val < val){
                return tree[x].val;
            }
            else
                return ans; 
        }
        if(tree[x].cnt != 0)
        {
            return queryfr(tree[x].rs,val,tree[x].val);//这里考虑到该节点是否被删除; 
        }
        else
            return queryfr(tree[x].rs,val,ans);
    } 

}
//找后继
int querysu(int x,int val,int ans)
{
    if(tree[x].val <= val )
    {
        if(tree[x].rs == 0)
            return ans;
        else
        {
            return querysu(tree[x].rs,val,ans);
        }
    }
    else
    {
        if(tree[x].ls == 0)
        {
            if(tree[x].val > val)
                return tree[x].val;
            else
                return ans;	
        }
        else
        {
            if(tree[x].cnt != 0)
                return querysu(tree[x].ls,val,tree[x].val);
            else
                return querysu(tree[x].ls,val,ans);	
        }	
    }	
} 
//按值找排名
int queryval(int x,int val)
{
    if(x == 0) return 0;
    if(val < tree[x].val) 
    {
        return queryval(tree[x].ls,val);
    }
    if(val == tree[x].val) 
        return tree[tree[x].ls].siz+1;
    return queryval(tree[x].rs,val) + tree[tree[x].ls].siz + tree[x].cnt;
} 
//按排名找值
int queryrk(int x,int rk)
{
    if(x == 0) return INF;
    if(rk <= tree[tree[x].ls].siz)
    {
        return queryrk(tree[x].ls,rk);	
    }
    if(tree[tree[x].ls].siz+tree[x].cnt >= rk)
    {
        return tree[x].val;
    }
    return queryrk(tree[x].rs,rk-tree[tree[x].ls].siz-tree[x].cnt);	
} 
int main()
{
    n = read();
    while(n--)
    {
        x = read(),y = read();
        if(x == 1){
            printf("%d\n",queryval(1,y)+1); 
        }
        else if(x == 2){
            printf("%d\n",queryrk(1,y));
        } 
        else if(x == 3){
            printf("%d\n",queryfr(1,y,-INF));
        }
        else if(x == 4){
            printf("%d\n",querysu(1,y,INF));
        }
        else
        {
            if(cont == 0)
            {
                cont++;
                tree[cont].val = y;
                tree[cont].siz = tree[cont].cnt = 1;
            }
            else
            {
                add(1,y);
            }
        }
    }
    return 0;
}
