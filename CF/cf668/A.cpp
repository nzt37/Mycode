#include <bits/stdc++.h>
using namespace std;
int fac(int n)
{
    if(n == 0){
        return 1;
    }
    return fac(n)*fac(n-1);
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            int a;
            cin >> a;
            ans += a;
        }
        if(ans == m){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;

        }
    }
    return 0;
}
