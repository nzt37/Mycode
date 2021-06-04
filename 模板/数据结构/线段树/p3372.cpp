#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
inline int ls(int p){return p<<1;}//����� 
inline int rs(int p){return p<<1|1;}//�Ҷ���
struct node{
    int l,r;//�ýڵ�ά�������� 
    long long pre,laze;//preΪ�õ�ά����ֵ,lazeΪ����� 
}t[maxn*4];
int a[maxn+2];
void build(int p,int l,int r)
{
    t[p].l=l;t[p].r=r;//��pΪ��ŵĽڵ�ά����l��r������; 
    if(l == r){
        t[p].pre = a[l];
        return ;
    }
    int mid = l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;//�ϴ������ ; 
}
void pushdown(int p) //�´�laze���;
{
    if(t[p].laze){//�������ǲ�Ϊ��,���´�,���������Ҷ���ֵ; 
        t[ls(p)].pre += t[p].laze*(t[ls(p)].r-t[ls(p)].l+1); 
        t[rs(p)].pre += t[p].laze*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].laze += t[p].laze;
        t[rs(p)].laze += t[p].laze;
        t[p].laze = 0;
    }
} 
void change(int p,int x,int y,int z  ) 
{
    if(x <= t[p].l  && y >= t[p].r ){//�����ǵĻ����Ͷ�������޸�
        t[p].pre += (long long) z*(t[p].r-t[p].l+1);
        t[p].laze += z;//���������
        return;
    } 
    pushdown(p);//�������û�б����ǣ��Ǿ���Ҫ���������ң����Ƕ�����ά�������������Ϊ����ǵĴ��ڶ�û���޸ģ���˽�������·�
    int mid = t[p].l + t[p].r >>1;
    if(x <= mid) change(ls(p),x,y,z);//���Ҫ�޸ĵ����串��������ӣ����޸������
    if(y > mid) change(rs(p),x,y,z);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;//�ϴ������ ; 
}
long long query(int p,int x,int y)
{
    if(x <= t[p].l  && y >= t[p].r){//��������ǣ��ͷ���ά����ֵ
        return t[p].pre;//�´�����ǣ�����ѯ���Ҷ���
    }
    pushdown(p);
    int mid = t[p].l+t[p].r>>1;
    long long ans = 0;
    if(x <= mid) ans += query(ls(p),x,y);
    if(y>mid) ans+= query(rs(p),x,y);//�ۼӴ𰸣��������Ҷ��ӵĺ�
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&a[i]);
    }
    cout << "dsad" << endl;
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int q,x,y,z;
        scanf("%d",&q);
        if(q==1){//����ı���� 
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
        else {//��ѯ���� 
            scanf("%d%d",&x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}

