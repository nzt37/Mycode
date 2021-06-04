#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int > ,greater<int> > q;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        q.push(a); 
    }
    vector<int> a(n);
    while(!q.empty()) {
        int m = q.top();
        a.push_back(m);
        q.pop();
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}