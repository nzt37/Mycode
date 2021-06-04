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
int a[maxn],cnt[maxn];
int ans[maxn];
int num,block;
struct node{
	int l,r,pos;
}q[maxn];
bool cmp(node a,node b) {
	return (a.l/block)^(b.l/block) ? a.l/block < b.l/block : a.r < b.r;
}
void add(int pos)
{
    if((++cnt[a[pos]]) == 1) ++num;
}
void del(int pos)
{
    if((--cnt[a[pos]]) == 0) --num;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
	}
	// block = ceil(exp(log(n) + log(m) / 3.0));
	block = sqrt(n);

	sort(q+1,q+1+m,cmp);
	int curR = 0,curL =1;
	for(int i = 1; i <= m; i++) {
		int L = q[i].l;
		int R = q[i].r;
		while(curL < L) num -= !--cnt[a[curL++]];
        while(curL > L) num += !cnt[a[--curL]]++;
        while(curR < R) num += !cnt[a[++curR]]++;
        while(curR > R) num -= !--cnt[a[curR--]];
		if(num == (R-L+1)) {
			ans[q[i].pos] = 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		if(ans[i]) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}