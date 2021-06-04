#include <bits/stdc++.h>
using namespace std;

int n,m;
void solve()
{
    cin >> n;
    string a;
    string b;
    cin >> a;
    cin >> b;
    int l = 0,r = 0;
   // sort(a.begin(), a.end());
  //  sort(b.begin(), b.end());
    //cout << a << endl;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            r++;
        } 
        else if(b[i] > a[i]) {
            l++;
        }
    }
    cout << l << r << endl;
    if(l > r) {
        cout << "BLUE" << endl;
        return;
    }
    else if(l < r) {
        cout << "RED" << endl;
        return;
    }
    else {
        cout << "EQUAL" << endl;
        return;
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
// 10
// 1083891399
// 3985861313