#include <bits/stdc++.h>
using namespace std;

int n,m;
void solve()
{
    cin >> n;
    int flag = 0;
    for(int i = n/7; i >= 0; i--) {
        for(int j = 0; j*5 + i*7 <= n; j++) {
            if((n-(i*7+j*5))%3 == 0) {
                flag = 1;
               int k = (n-(i*7+j*5))/3;
				printf("%d %d %d\n",k,j,i);
                // cout << endl;
                break;
            }
            
        }
        if(flag) break;
    }
    if(!flag) {
        puts("-1");
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}