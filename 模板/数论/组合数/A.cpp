//确定无向图欧拉回路的充要条件：除孤立节点外，其它节点满足 1.连通 2.度为偶数

#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int f[1001];
//并查集找父亲的操作
int find(int x){
    while(x!=f[x]){
        x = f[x];
    }
    return x;
}
//并查集合并的操作
void Union(int a, int b){
    int af = find(a);
    int bf = find(b);
    f[bf] = af;
}
 
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int d[1001]; //节点度
        fill(d,d+1001,0);
        for(int i=0;i<=n;i++) f[i]=i; //初始化f数组
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            d[a]++;
            d[b]++;
            Union(a,b);
        }
       int tmp=0;
        for(int i=1;i<=n;i++){
            //有奇数度，应打印0
            if (d[i]%2!=0){
                tmp++;
                break;
            }
        }
        if(tmp>0){
            printf("0\n");
            continue;
        }
        int t = 1;
        for(int i=0;i<=n;i++){  //寻找一个非孤立节点，存入t
            if(d[i]!=0){
                t = i;
                break;
            }
        }
        int f = find(t);
        bool flag = false;
        for(int i=2;i<=n;i++){
            if(find(i) != f && find(i) != i){
                flag = true;
                break;
            }
        }
        if(m == 1 || flag){
            printf("0\n");
            continue;
        }
        if(n!=0){
            printf("1\n");
        } 
    }
    return 0;
}