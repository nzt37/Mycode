#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 3; i < n; i++) {
        if(s[i] = 'f' && s[i+1] == 'o' && s[i+2] == 'x') {
            s.erase(s.begin()+i,s.begin()+i+3);
            i-=3;
        }
        
    }
    int k = s.size();
    cout << k << endl;
    return 0;

}
