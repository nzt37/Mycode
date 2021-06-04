#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
string s1,s2;
map<char, int> q;
int main() {
    getline(cin,s1);
    getline(cin,s2);
    for(int i = 0; i < s2.size(); i++){
        q[s2[i]] = 1;
    }
    for(int i = 0; i < s1.size(); i++){
        if(q[s1[i]]) continue;
        cout << s1[i];
    }

    return 0;
}
