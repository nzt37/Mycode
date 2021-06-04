#include<cstdio>
#include<stack>
using namespace std;
int n,a[3000005],f[3000005];//a是需要判断的数组（即输入的数组），f是存储答案的数组
stack<int>s;//模拟用的栈
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();//弹出栈顶比当前数小的
        f[i]=s.empty()?0:s.top();//存储答案，由于没有比她大的要输出0，所以加了个三目运算
        s.push(i);//压入当前元素
    }
    for(int i=1;i<=n;i++) printf("%d ",f[i]);//输出
    return 0;
}