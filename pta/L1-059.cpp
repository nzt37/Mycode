#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {
    int n;
    cin >> n;
    cin.get();
    while(n--){
        string s;
        getline(cin,s);
        int l = s.find(",");
        int r = s.rfind(".");
        if(l >= 3 && s.substr(l-3,3) == "ong" && s.substr(r-3,3) == "ong"){
            int len = s.size();
            int cnt = 0;
            for(int i = len-1; i >= 0; i--){
                if(s[i] == ' '){
                    cnt++;
                }
                if(cnt == 3){
                    cnt = i;
                    break;
                }
            }
            s.erase(cnt+1);
            s += "qiao ben zhong.";
            cout << s << endl;
        }else{
            cout <<"Skipped" << endl;
        }
    }

    return 0;
}
