#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 6;
inline int rd(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {x=x*10+(ch^48);ch=getchar();}
    return x;
}
bool isprime[maxn];
int p[maxn];
void getprime(int n) {
	memset(isprime,1,sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i * i <= n; i++) {
		if(isprime[i]) {
			int j = 2 * i;
			while(j <= n) {
				isprime[j] = 0;
				j += i;
			}
		}
	}
	int k = 1000003;
	for(int i = n; i >= 1; i--) {
		if(isprime[i]) {
			p[i] = k;
			k = i;
			continue;
		}
		p[i] = k;
	}
}
int main() {
	int T,n;
	cin >> T;
	int cnt = 0;
	getprime(1000003);
	while(T--) {	
		cin >> n;
		long long ans = 0;
		
		for(int i = 1; i <= n; i++) {
			int a; 
			cin >> a;
			ans += p[a];
		}
		
   	 printf("Case %d: %lld Xukha\n",++cnt,ans);
	}
}
