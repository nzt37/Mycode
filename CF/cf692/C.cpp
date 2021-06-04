#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,m;
int cnt1;
int f[maxn];
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int a = find(x),b = find(y);
	if(a == b) {
		cnt1++;
		return;
	}
		f[a] = b;
	
}

void solve()
{
	cin >> n >> m;
	int cnt = 0;
	cnt1 = 0;
	for(int i = 0; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		if(x == y) continue;
		cnt++;
		merge(x,y);
	}
	cout << cnt1 + cnt << endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
    while(T--) {
 		solve();   	
    }
    return 0;
}