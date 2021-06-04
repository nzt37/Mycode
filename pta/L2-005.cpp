#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+4;
set<int > a[55];
int main()
{
    int T,n;
    cin >> T;
    
    for(int i = 1; i <= T; i++) {
       cin >> n;
       for(int j = 1; j <= n; j++) {
           int c;
           cin >> c;
           a[i].insert(c); 
       }
    }
    // sort(a.begin(),a.end());
    int K,m;
    cin >> K;
    for(int i = 1; i <= K; i++) {
        int n,m;
        cin >> n >> m;
        int cnt1 = 0;
        for(auto it = a[n].begin(); it != a[n].end(); ++it) {
            if(a[m].count(*it)) {
                cnt1++;
            }
        }
        printf("%.2f%\n",cnt1*1.0/(a[n].size()+a[m].size()-cnt1)*100);
    }
    
    return 0;
}