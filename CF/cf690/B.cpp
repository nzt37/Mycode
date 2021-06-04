#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    string s;
    cin >> n >> s;
    if(s.substr(0,2) == "20" && s.substr(s.size() - 2,2) == "20") {
        cout << "YES" << endl;
        return;
    }
    else if(s.substr(0,4) == "2020" || s.substr(s.size() - 4,4) == "2020") {
        cout << "YES" << endl;
        return;
    } 
    else if(s.substr(0,1) == "2" && s.substr(s.size() - 3,3) == "020") {
        cout << "YES" << endl;
        return;
    } 
    else if(s.substr(0,3) == "202" && s.substr(s.size() - 1,1) == "0") {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

        
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}