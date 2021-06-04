#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
struct node{
	int h,w;
}a[maxn];
int ans[maxn];
bool cmp(node a, node b) {
    return a.h < b.h;
}
void solve() {
	cin >> n;
	std::vector<node> v(n);
	memset(ans,0,sizeof(ans));
	for(int i = 0; i < n; i++) {
		cin >> a[i].h >> a[i].w;
		if(a[i].h > a[i].w) swap(a[i].h,a[i].w);
		v[i] = node{a[i].h,i};
		ans[i] = -2;
	}
	sort(v.begin(),v.end(),cmp);
	int p = -1, j = 0;
	for(int i = 0; i < n; i++) {
		int m = v[i].w;
		while(a[m].h > v[j].h) {
			if(p == -1 || (a[p].w > a[v[j].w].w)) p = v[j].w;
			j++;
		}
		if(p != -1 && a[m].w > a[p].w) ans[m] = p;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";

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