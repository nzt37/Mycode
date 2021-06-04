#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,m;
int len[maxn],v[maxn];
void solve()
{
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int  > p;
    int cnt = 0;
    for(int i = 0,j ; i < n; i = j) {
        for(j = i; j < n && s[i] == s[j]; j++);
        len[cnt] = j - i;
        v[cnt] = (s[i] == 'W' ? 1 : 0);
        cnt++;
    }
    int one_cnt = 0,sum = 0;
    for(int i = 0 ;i < cnt; i++) {
        if(v[i] == 1) {
            one_cnt += len[i];
            sum += 2*len[i]-1;
        }
        else{
            if(i!=0 && i != cnt-1)
                p.push_back(len[i]);
        }
    }
    //cout << one_cnt << endl;
    sort(p.begin(),p.end());
    if(m + one_cnt >= n) {
        cout << n*2-1 << endl;
        return ;
    }
    if(one_cnt == 0) {
        cout <<  (m == 0 ? 0 : 2*m-1)<< endl;
        return;
    }
    for(int i = 0; i <(int)p.size(); i++) {
        if(m >= p[i]) {
            m -= p[i];

            sum += 2*p[i]+1;
        }
    }
    if(m) {
        sum += m*2;
    }
    cout << sum << endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
    while(T--) {
    	solve();
    }
    return 0;
}