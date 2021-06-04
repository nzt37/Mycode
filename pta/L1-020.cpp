#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e6+6;
int s[maxn];
map<string, int> a;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        if( m == 1 ){
            string b;
            cin >> b;
        }
        else{
            for(int i = 1; i <= m; i++){
                string b;
                cin >> b;
                a[b]++;
            }
        }

    }
    int p;
    cin >> p;
    int flag = 0,vis = 0;
    for(int i = 1; i <= p; i++){
        string c;
        cin >> c;
        if(!a[c]){
            a[c]++;
            if(vis != 0) 
                cout << " " << c ;
            else{
                cout << c;
            }
            vis = 1;
            flag = 1;
        }
    }
    if(!flag) printf("No one is handsome");

    return 0;
}
