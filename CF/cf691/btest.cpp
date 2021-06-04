
#include <bits/stdc++.h>
#include <queue> 
using namespace std;

inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

const int N = 1001;
int n, vis[N][N], ans;
struct node{
	int direction;//这次移动的方向
	//1是南北，2是东西 
	int step;//步数
	int x, y;//坐标 
};
queue<node> q;
int main()
{
	n = read();
	if(n == 1){
		cout << 4 << '\n';
		return 0;
	}
	q.push((node){1, 1, 1000, 1000 - 1});//南 
	q.push((node){1, 1, 1000, 1000 + 1});//北 
	q.push((node){2, 1, 1000 - 1, 1000});//西 
	q.push((node){2, 1, 1000 + 1, 1000});//东 
	while(!q.empty()){
		node now = q.front();
		q.pop();
		if(now.step == n){
			if(vis[now.x][now.y] == 1) continue;
			vis[now.x][now.y] = 1;
			ans += 1;
			continue;
		}
		if(now.direction == 1){//上一次是南北 
			q.push((node){2, now.step + 1, now.x - 1, now.y});//西 
			q.push((node){2, now.step + 1, now.x + 1, now.y});//东 
		}
		else if(now.direction == 2){//上一次是东西 
			q.push((node){1, now.step + 1, now.x, now.y - 1});//南 
			q.push((node){1, now.step + 1, now.x, now.y + 1});//北 
		}
	}	
	cout << ans;
	return 0;
}