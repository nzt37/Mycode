#include <bits/stdc++.h>
using namespace std;

int n,m;
bool cmp(int a,int b)
{
    return a > b;
}
void solve()
{
    cin >> n;
    if(n > 45) {
        cout << "-1" << endl;
        return;
    }
    int cnt = 9;
    string str = "";
    while(n > cnt) {
        str = (char)( '0' + cnt) + str;
        n -= cnt;
        cnt--;
    }
    if(n > 0) {
        str = char('0' + n) + str;
    }
    cout << str << endl; 
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}