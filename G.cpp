#include<bits/stdc++.h>
#define LL long long
using namespace std;
bool a[10000][10000];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
LL ans;
struct node{
    int x,y,step;
};
queue<node>q;
void bfs() 
{
    a[0+3000][0+3000]=1; //相对位置不变结果不变 ，不加数组会越界 
    a[2020+3000][11+3000]=1;
    a[11+3000][14+3000]=1;
    a[2000+3000][2000+3000]=1;
    q.push({0+3000,0+3000,0});
    q.push({2020+3000,11+3000,0});
    q.push({11+3000,14+3000,0});
    q.push({2000+3000,2000+3000,0});
    ans=4; //初始有4个
    while(q.size())
    {
        node temp=q.front();
        q.pop();
        cout << temp.x << "\n";
        if(temp.step==2020)
            continue;
        for(int i=0;i<4;i++)
        {
            int xx=temp.x+dir[i][0];
            int yy=temp.y+dir[i][1];
            if(!a[xx][yy])
            {
                ans++;
                a[xx][yy]=1;
                q.push({xx,yy,temp.step+1});
            }
        }
    }
}
int main()
{

    bfs();
    cout<<ans<<endl;
    return 0;
}

