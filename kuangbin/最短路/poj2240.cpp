#include <iostream>
#include <map>
using namespace std;
string str[35],s1,s2;
const int maxn = 2e5 + 10;
map<string,int> mp;
int n,m;
double dis[1000][1000];
int main() {
	int ans = 1;
	while(cin >> n && n) {
			
		for(int i = 1; i <= n; i++) {
			cin >> str[i];
			mp[str[i]] = i;
		}
		cin >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = (i == j ? 1 : 0);
			}
		}
		for(int i = 0; i < m; i++) {
			// string str1,str2;
			double w;
			cin >> s1 >> w >> s2;
			dis[mp[s1]][mp[s2]] = w;
		}
		int flag = 0;
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					dis[i][j] = max(dis[i][j],dis[i][k]*dis[k][j]);
				}
				if(dis[i][i] > 1) {
					flag = 1;
					break;
				}
			}
		}
		cout<<"Case "<<ans++<<": ";
        if(flag==1)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}	
	return 0;
}