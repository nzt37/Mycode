#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int a[maxn],lg[maxn] = {-1},f1[maxn][35],f2[maxn][35];
int pre[maxn];
int query(int l,int r)
{
	int len = lg[r - l + 1];
	return min(f2[l][len],f2[r-(1<<(len))+1][len]);
}
void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		lg[i] = lg[i/2] + 1;
		cin >> a[i];
		f1[i][0] = a[i];
		f2[i][0] = a[i];
	}
	for(int j = 1; j <= lg[n]; j++) {
		for(int i = 1; i + (1 << j) <= n; i++) {
			f1[i][j] = max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j = 1; (1<<j) <= n; j++) {
		for(int i = 1; i + (1 << j) <= n; i++) {
			f2[i][j] = min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
	pre[n] = a[n];
	for(int i = n - 1; i >= 1; i--) {
		pre[i] = max(pre[i+1],a[i]);
	}
	int mx = 0,b=  0;
	for(int i = 1; i <= n-2; i++) {
		mx = max(mx,a[i]);
		int l = i + 1,r = n,mid;
		while(l <= r) {
			mid = (l + r) >> 1;
			int num = query(i+1,mid);
			if(num > mx) l = mid+1;
			else if(num < mx) r = mid - 1;
 			else if(num == mx) {
 				if(pre[mid+1] > mx) l =mid+1;
 				else if(pre[mid+1] < mx) r = mid - 1;
 				else if(pre[mid+1] == mx) break;
			}	
		}
		if(query(i + 1,mid) == mx && pre[mid+1] == mx) {
			b = 1;
			puts("YES");
			printf("%d %d %d\n",i,mid-i,n-mid);
			break;
		}
	}
	if(!b) {
		puts("NO");
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
	
    while(T--) {
 		solve();   	
    }
    return 0;
}