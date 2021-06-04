#include <windows.h>
#include <stdio.h>
#include <process.h>


#define TRUE 1
#define FALSE 0
#define INVALID -1
#define NULL 0

#define NUMBER_OF_INSTRUCTION 320  //ָ������ָ������
#define NUMBER_OF_VP 32            //���̵���ҳҳ��

//#define LINEAR_ADDRESS           //��ѡ���ԵĴ򿪸ú꿪��
       
typedef struct
{
    int no_of_vp;            //����ҳ��
    int no_of_pp;            //����ҳ��
    int counter_in_period;   //һ�����ڷ��ʵĴ���
    int time;               //����ʱ��
}vp_struct;    //ҳ������

vp_struct vp_array[NUMBER_OF_VP];        //ҳ��ṹ����


struct pp_struct           //����ҳ��ṹ
{
    int no_of_vp;
    int no_of_pp;
    struct pp_struct *next;
};

typedef struct pp_struct pp_type;
pp_type pp_control[NUMBER_OF_VP],*free_pp_head,*busy_pp_head,*busy_pp_tail;

int counter_page_default;
int address_of_instruction[NUMBER_OF_INSTRUCTION];

int page_of_instruction[NUMBER_OF_INSTRUCTION],offset_of_instruction[NUMBER_OF_INSTRUCTION];

int MAXI = 2147483647;     //((1<<30)-1)*2+1; //2^31-1 2147483647
       
void initialize(int);

void FIFO(int);   //�Ƚ��ȳ�
void LRU(int);    //������δʹ��ҳ����̭�㷨��least recently used��
//void OPT(int);    //�����̭�㷨
int main()
{
    int S,i;
    srand( (int)getpid() ); 
    S=(int)rand() % 200;
//#ifndef LINEAR_ADDRESS    
    
    for(i=0;i<NUMBER_OF_INSTRUCTION;i++)  /*����ָ�����*/
    {
        address_of_instruction[i]=S;                               /*��ѡһָ����ʵ�*/
        address_of_instruction[i+1]=address_of_instruction[i]+1;   /*˳��ִ��һ��ָ��*/
        address_of_instruction[i+2]=(int)rand()%200;               /*ִ��ǰ��ַָ��m'*/
        address_of_instruction[i+3]=address_of_instruction[i+2]+1; /*ִ�к��ַָ��*/
        S=(int)rand()%200;
    }
    
//#else
//  
  //  for(i=0;i<NUMBER_OF_INSTRUCTION;i+=1)  /*����ָ�����*/
//  {
//      address_of_instruction[i]=i;
//  }
//#endif
    
    for(i=0;i<NUMBER_OF_INSTRUCTION;i++)               /*��ָ�����б任��ҳ��ַ��*/
    {       
        page_of_instruction[i]=address_of_instruction[i]/10;
        offset_of_instruction[i]=address_of_instruction[i]%10;
    }
    
    for(i=4;i<=32;i++)                        /*�û��ڴ湤������4��ҳ�浽32��ҳ��*/
    {
        printf("%2d ����飺",i);
        FIFO(i);
        LRU(i);
    //  OPT(i);
        printf("\n");
    }
    //getchar();
    return 0;
}

//�Ƚ��ȳ���̭�㷨
void FIFO(int total_pf)
{
    int i,j;
    pp_type *p,*t;
    initialize(total_pf);
    busy_pp_head=busy_pp_tail=NULL;
    for(i=0;i<NUMBER_OF_INSTRUCTION;i++)
    {
    if(vp_array[page_of_instruction[i]].no_of_pp==INVALID)
    {
        counter_page_default+=1;
        if(free_pp_head==NULL)
        {
            p=busy_pp_head->next;
            vp_array[busy_pp_head->no_of_vp].no_of_pp=INVALID;
            free_pp_head=busy_pp_head;
            free_pp_head->next=NULL;
            busy_pp_head=p;
        }
        p=free_pp_head->next;
        free_pp_head->next=NULL;
        free_pp_head->no_of_vp=page_of_instruction[i];
        vp_array[page_of_instruction[i]].no_of_pp=free_pp_head->no_of_pp;
        if(busy_pp_tail==NULL)
            busy_pp_head=busy_pp_tail=free_pp_head;
        else
        {
            busy_pp_tail->next=free_pp_head;
            busy_pp_tail=free_pp_head;
        }
        free_pp_head=p;      
    }
    }
    printf("FIFOȱҳ�ʣ�%6.4f     ",(float)counter_page_default/320);
    return;
}

//���������̭ʹ���㷨
void LRU(int total_pf)
{
    int min,minj,i,j,present_time;//����ʱ��
    initialize(total_pf);
    present_time=0;
    for(i=0;i<NUMBER_OF_INSTRUCTION;i++)
    {
    if(vp_array[page_of_instruction[i]].no_of_pp==INVALID)
    {
        counter_page_default++;
        if(free_pp_head==NULL)  //�޿���ҳ��
        {
            min=MAXI;
            for(j=0;j<NUMBER_OF_VP;j++)
                if(min>vp_array[j].time&&vp_array[j].no_of_pp!=INVALID)
                {
                    min=vp_array[j].time;
                    minj=j;
                }
            free_pp_head=&pp_control[vp_array[minj].no_of_pp];
            vp_array[minj].no_of_pp=INVALID;
            vp_array[minj].time=-1;
            free_pp_head->next=NULL;
        }
        vp_array[page_of_instruction[i]].no_of_pp=free_pp_head->no_of_pp;
        //vp_array[page_of_instruction[i]].time=present_time;
        free_pp_head=free_pp_head->next;
    } 
    else
        vp_array[page_of_instruction[i]].time=present_time;// ʹ��
    
    present_time++;
    }
    printf("LRUȱҳ�ʣ�%6.4f     ",(float)counter_page_default/320);
    return ;
}



void initialize(int total_pf)
{
    int i;
    counter_page_default=0;
    for(i=0;i<NUMBER_OF_VP;i++)
    {
        vp_array[i].no_of_vp=i;
        vp_array[i].no_of_pp=INVALID;
        vp_array[i].counter_in_period=0;
        vp_array[i].time=-1;
    }

    for(i=1;i<total_pf;i++)
    {
        pp_control[i-1].next=&pp_control[i];  //����pp_control[i-1]��ptf[i]֮�������
        pp_control[i-1].no_of_pp=i-1;
        pp_control[i-1].no_of_vp = -1;
    }
    pp_control[total_pf-1].next=NULL;
    pp_control[total_pf-1].no_of_pp=total_pf-1;
    pp_control[total_pf-1].no_of_vp = -1;
    free_pp_head=&pp_control[0];

    return;
}

