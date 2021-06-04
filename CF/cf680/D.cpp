#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 2e5+6;
int a[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            scanf("%d", a+i);
        }
        if(n == 1) {
            puts("0");
            continue;
        }
        if(n == 2){
            puts("1");
            continue;
        }
        int now = 0, pre = 1, cnt = 0,ans = 0;
        for(int i = 2; i <= n; i++){
            if(a[i]> a[i-1]) cnt++;
            else{
                now++;
                if(now == pre) {
                    ans++;
                    pre = cnt;
                    now = 0;
                }

            }
        }
        cout << ans+1 << endl;
    }


    return 0;
}
