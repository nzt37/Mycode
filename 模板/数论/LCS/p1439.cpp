#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int n,a[maxn],b[maxn],f[maxn];
map<int,int> mp;
int main()
{
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
		mp[a[i]] = i;
	}
	for(int i = 1 ; i <= n ; i++){
		cin>>b[i];
	}
	int len = 0;
	f[0] = 0;
	int l = 0,r = len;
	for(int i = 1 ; i <= n ; i++){
		if(mp[b[i]] > f[len]) f[++len] = mp[b[i]];
		else{
			int p = lower_bound(f,f+len,mp[b[i]])- f;
			f[p] = mp[b[i]];
		}
	}
	cout<<len;
	return 0;
 } 
