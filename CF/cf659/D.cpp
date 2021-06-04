#include <bits/stdc++.h>
using namespace std;

int n,m;
int f[30];
int find(int x)
{
    if(f[x] == x) return x;
    return f[x] = find(f[x]);

}
int ans = 0;
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if(x != y) {
        ans++;
        f[x] = y;
    }
}
void sovle()
{
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 1; i <= 26; i++) {
        f[i] = i;
    }
    ans = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] > s2[i]) {
            cout << -1 << endl;
            return;
        }
        merge(s1[i]-'a'+1,s2[i]-'a'+1);
    }
    cout << ans << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        sovle();
    }
    return 0;
}