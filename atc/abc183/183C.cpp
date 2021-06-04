#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(i);
    }
    v.push_back(0);
    int ans = 0;
    do{
        int sum = 0;
        for(int i = 0; i < (int)v.size() - 1; i++) {
            sum += t[v[i]][v[i+1]];
        }
        if(sum == k) {
            ans++;
        }
    }while(next_permutation(v.begin()+1, v.end()-1));
    cout << ans << endl;
    return 0;
}
