#include <bits/stdc++.h>
using namespace std;
int n,x,y,cont,m,k;
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
    cin >> m >> k; 
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(cont == 0)
			{
				cont++;
				tree[cont].val = a;
				tree[cont].siz = tree[cont].cnt = 1;
			}
			else
			{
				add(1,a);
			}

    }
    for(int i = 1; i <= m; i++) {
        int x,y;
        cin >> x;
        if(x == 1) {
            cin >> y;
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
        else {
            printf("%d\n",queryrk(1,k));
        }
    }
	
	return 0;
}