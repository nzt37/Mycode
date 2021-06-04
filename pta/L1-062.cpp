#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {
    int a;
    cin >> a;
    while(a--){
        string s;
        cin >> s;
        int l = 0, r = 0;
        for(int i = 0; i <= 2 ; i++){
            l += s[i]-'0';
        }
        for(int j = 3; j <= 5; j++){
            r += s[j]-'0';
        }
        cout << (l == r ? "You are lucky!\n" : "Wish you good luck.\n");
    }

    return 0;
}
