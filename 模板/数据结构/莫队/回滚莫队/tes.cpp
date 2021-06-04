#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn],bl,cnt[maxn],ed[maxn],st[maxn],ed2[maxn],R[maxn],b[maxn];
int an[maxn];;
struct node{
	int l,r;
	int pos;
}q[maxn];
bool cmp(node x,node y) {
	return (b[x.l]==b[y.l])?x.r<y.r:b[x.l]<b[y.l];
}
void work()//开始处理询问 
{
	int block=0,tmp1=0,l=0,r=0;
	//block:块,代表上次询问左端点在哪个块
	//如果块一样我们就可以直接使用上次留下来的进程 
	//不一样就舍弃上次的进程,全部推翻
	//tmp1:在公共L到上一次询问R时得出的答案
	//l:公共L
	//r:上一次询问的R 
	for(int i=1;i<=m;i++)
	{
		int ql = q[i].l;
		int qr = q[i].r;
		if(ql / bl == qr / bl) 
		//如果是同一个块就没有什么好说的了 
		//你的莫队技巧全部木大,还不如暴力求解，时间复杂度不会退化 
		{
			tmp1=0;
			for(int j=q[i].l;j<=q[i].r;j++)st[a[j]]=0;
			//你只需要用到st，就只清空st
			//诶你可能会想:st清空了,l,r没动,那后面求解不就乱套了？ 会不会调用到错误的st 
			//不会的
			//你想一想，询问左右端点变成在一个块时,是什么时候
			//是左端点所在块已经不同于之前的块的时候啊! 
			//是你前面求出的tmp1,st,ed已经失去利用价值的时候啊! 
			//肯定后面需要清空(摈弃)之前的数组，开始解新一组的询问
			//那么之后的l,r,st,肯定会清空掉 
			//总而言之：我这里清空st,根本就不影响之后啊哈哈哈哈哈反正都会清空 
			//听不懂就算了... 
			for(int j=q[i].l;j<=q[i].r;j++)
			{		
				if(!st[a[j]])st[a[j]]=j;
				tmp1=max(tmp1,j-st[a[j]]);
			}
			for(int j=q[i].l;j<=q[i].r;j++)st[a[j]]=0;
			an[q[i].pos]=tmp1;
			continue ;
		}
		//要开始正常求解了 
		int now=b[q[i].l];//先记录下左端点所在的块，偷懒嗷 
		if(block!=now)//左端点所在块发生变化了 
		{
			tmp1=0;
			for(int j=l;j<=r;j++)st[a[j]]=ed[a[j]]=0;//之前求解的玩意儿都不要了,这里没用 
			//从头开始算 
			l=R[now];
			r=l-1;//莫队细节：记得r=l-1； 
			block=now;//更新所在块 
		}
		while(r<q[i].r)
		{
			r++;
			if(!st[a[r]])st[a[r]]=r;//st(start:元素第一次出现的位置)只需要更新一次 
			ed[a[r]]=r;//从前移向后,ed(end:元素最后出现的位置)要一直更新 
			tmp1=max(tmp1,r-st[a[r]]);//更新答案 
		}
		//公共左端点到r的答案处理出来了,你还记得前面的有一小端还没有算吗 
		int p=l,tmp2=0;
		while(q[i].l<p)
		{
			p--;
			if(!ed2[a[p]])ed2[a[p]]=p;//从后向前移动,ed更新一次就够了嗷 
			//防止想怎么撤回想出脑膜炎,直接开个临时数组记录一下新的ed就行 
			tmp2=max(tmp2,max(ed[a[p]],ed2[a[p]])-p);//细节:记得取个max,你公共左端点右边也可能出现这个元素 
		}
		while(p<l)//算完了就撤回 
		{
			ed2[a[p]]=0;
			p++;
		}
		an[q[i].pos]=max(tmp2,tmp1);//在公共左端点左右答案中取个max 
	}
}
int main() {
	freopen("P5906_1_1.txt","r",stdin);
	cin >> n;
	std::vector<int> v;
	bl = sqrt(n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
		b[i] = (i-1)/bl + 1;
	}
	for(int i = 1; i <= b[n]; i++) {
		R[i] = (i == b[n] ? n : i * bl);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(v),a[i]) - v.begin() + 1;
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
	}
	sort(q+1,q+1+m,cmp);
	work();
	for(int i = 1; i <= m; i++) {
		cout << an[i] << "\n";
	}
	return 0;
}