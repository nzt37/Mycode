#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
    int num;
    double w;
};
map<int , double> p[2001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        for(int j = 1; j <= a; j++){
            double  an = 1 / a;
            int b;
            cin >> b;
            if(p[b][i])
                p[b][i] += an;
            else{
                p[b][i] = an;
            }
        }
    }
    cout << p[-3][4];
    return 0;
}
