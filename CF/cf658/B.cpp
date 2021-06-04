#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x = 1,y = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1 ) {
           if(x) {
               x = 0;
               y = 1;
           }
           else if(y) {
               y = 0;
               x = 1;
           }
        }
        else {
            if(x) {
                x = y = 1;

            }
            else {
                x = y = 0;
            }
            break;
        }
    }
    if(y) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
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