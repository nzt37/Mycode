#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 6;
int f[maxn],vis[maxn],m[maxn];
struct node{
    double ans1,ans2;
    int id,num;
}a[maxn],b[maxn],c[maxn];
bool cmp(node a,node b){//根据题目写出的排序规则
	if(a.ans2!=b.ans2)
		return a.ans2>b.ans2;//按人均面积降序输出
	return a.id<b.id;//并列时按成员编号升序输出
}
int find(int x)
{
    if(f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}
void unite(int a,int b)
{
    int x = find(a),y = find(b);
    if(x != y) {
        if(x > y) f[x] = y;
        else {
            f[y] = x;
        }
    }
}

int main()
{
    int n,k;
    cin >> n;
    for(int i = 0; i <= 10000; i++) {
        f[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int p1,p2;
        cin >> a[i].id >> p1 >> p2;
        vis[a[i].id] = 1;
        if(p1 != -1) {
            unite(a[i].id,p1);
            vis[p1] = 1;
        }
        if(p2 != -1) {
            unite(a[i].id,p2);
            vis[p2] = 1;
        }
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int s;
            cin >> s;
            unite(a[i].id,s);
            vis[s] = 1;
        }
        cin >> a[i].ans1 >> a[i].ans2;
    }
    for(int i = 0; i < n; i++) {
        int id = find(a[i].id);
        b[id].id = id;
        b[id].ans1 += a[i].ans1;
        b[id].ans2 += a[i].ans2;
    }
    for(int i = 0; i <= 10000; i++) {
        if(vis[i]) {
            b[find(i)].num++;
        }
    }
    int cnt = 0;
    for(int i = 0; i <= 10000; i++) {
        if(vis[i]) {
            int  id = find(i);
            if(!m[id]) {
                m[id] = 1;
                 int num = b[id].num;
                 c[cnt].ans1 = b[id].ans1*1.0 / num*1.0;
                 c[cnt].ans2 = b[id].ans2*1.0 / num*1.0;
                 c[cnt].id = id;
                 c[cnt++].num = (int)num;
                cout << num << endl;
                // cout << b[id].ans1 << " ds " << b[id].num << endl;
            }
           

        }
    }
    sort(c,c+cnt,cmp);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
    printf("%04d %d %.3lf %.3lf\n",c[i].id,c[i].num,c[i].ans1,c[i].ans2);
    return 0;
}