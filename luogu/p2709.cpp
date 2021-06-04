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
#define int long long
const int maxn = 2e5 + 10;

int n,m;
int cnt[maxn],ans,an[maxn],bl,a[maxn],s[maxn],id[maxn],l1[maxn],r1[maxn];
struct node{
	int l,r,pos;
}q[maxn];
bool cmp(node x,node y)
{
	if(id[x.r]==id[y.r])return x.l<y.l;
	else return x.r<y.r;
}
void chan(int x,int add) {
	ans -= s[a[x]]*s[a[x]];
	s[a[x]] += add;
	ans += s[a[x]]*s[a[x]];

}
signed main() {
	cin >> n >> m;
	bl = n/sqrt(m*2/3);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		id[i]=(i-1)/bl+1;
	}	
	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
		l1[i]=q[i].l,r1[i]=q[i].r;
	}
	sort(q+1,q+1+m,cmp);
	int l = 1,r = 0;
	for(int i = 1; i <= m; i++) {
		while(l<q[i].l)ans-=s[a[l]]*(s[a[l]]-1)/2,s[a[l]]--,ans+=s[a[l]]*(s[a[l]]-1)/2,l++;
		while(l>q[i].l)l--,ans-=s[a[l]]*(s[a[l]]-1)/2,s[a[l]]++,ans+=s[a[l]]*(s[a[l]]-1)/2;
		while(r<q[i].r)r++,ans-=s[a[r]]*(s[a[r]]-1)/2,s[a[r]]++,ans+=s[a[r]]*(s[a[r]]-1)/2;
		while(r>q[i].r)ans-=s[a[r]]*(s[a[r]]-1)/2,s[a[r]]--,ans+=s[a[r]]*(s[a[r]]-1)/2,r--;
		an[q[i].pos]=ans;
		// cout << q[i].pos << "\n";
	}
	// for(int i = 1; i <= m; i++) {
	// 	cout << an[i] << "\n";
	// }
	for(int i = 1,x; i <= m; i++) {
		x=__gcd((long long)an[i],(long long)(r1[i]-l1[i]+1)*(r1[i]-l1[i])/2);
		if(l1[i]==r1[i])printf("0/1\n");
		else printf("%d/%lld\n",an[i]/x,(long long)((r1[i]-l1[i]+1)*(r1[i]-l1[i])/2)/x);
	}
	return 0;
}