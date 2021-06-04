#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+ 6;
int a[maxn],vis[maxn],v[maxn];
bool cmp(int a,int b)
{
    return a > b;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
     vector<int> arr;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[s[i]-48]) {
            vis[s[i]-48]++;
            a[cnt++] = s[i]-48;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i = 0; i < cnt; i++) {
        v[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        arr.push_back(v[s[i]-48]);
    }
    printf("int[] arr = new int[]{");
    for(int i = 0; i < cnt; i++) {
        cout << a[i] << (i == cnt-1 ? "}" : ",");
    }
    cout << ";" << endl;
    printf("int[] index = new int[]{");
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i ==arr.size()-1 ? "}" : ",");
    }
     cout << ";" << endl;

}
int main()
{
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}