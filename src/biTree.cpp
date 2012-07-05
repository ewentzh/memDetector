
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct avlNode
{
    int key
    int bf // ballanced factor!!
    struct avlNode *lChild;
    struct avlNode *rChild;
    void* bbtRoot;
    void* element;
}avlNode_t;

typedef bbTree{
    int isTaller;  //is taller
    bbTree_t* avlRoot;
}bbTree_t;

bbTree_t* createBBTNode(int key,void* val)
{
    bbTreeNode_t*  bbtNode = NULL;
    bbtNode = malloc( sizeof(bbTreeNode_t) );
    if( NULL == bbtNode ) return NULL;

    bbtNode->bf  = 0;
    bbtNode->key = key;
    bbtNode->element = val;
    bbtNode->lChild  = NULL;
    bbtNode->rChild  = NULL;
    bbtNode->bbtRoot = NULL;

    return bbtNode;
}
 
 ///------------Bit operation-------------------
void setbit(char *i,char val,char pos)
{
     if(pos==1)
         (*i)=(*i)|1;
     else
     {
         if(val==1)    (*i)=(*i)|2;
         else    (*i)=(*i)&1;
     }
 }
 char getbit(char i,char pos)
 {
 //    return (i&pos); 出错的地方
     return (i&pos)&&1;
 }
 ///--------------------------------------------
 
 ///---------------------------------------------
 
 ///★★★★★★★★AVL的核心操作★★★★★★★★★★★★
 ///★★★★★★★★★保持平衡★★★★★★★★★★★★★★
 
 //改变因子函数
 void setfactor(AVL f,int button)
 {
     char fir=button/10,sec=button%10;
     AVL s=f->child[fir],ss=s->child[sec];
     char choice=ss->bf;
     int a=1,b=0;
 
     //////////调试时发现，删除时的特殊情况/////////////
 /////插入时，不会有这种情况，若button=0,则s->bf=1//
 /////若button=11，则s->bf=-1；然而删除时，却会出现/
 /////button=0或者button=11时 s->bf=0!!!!!!!////////
 /////那么这种特殊情况，平衡后所得的因子就跟一般的//
 /////不一样了!!!如下///////////////////////////////
     if(button==0 && s->bf==0)    f->bf=1,s->bf=-1;
     else if(button==11 && s->bf==0)    f->bf=-1,s->bf=1;
     ///////////////////////////////////////////////////
     else if(button==0 || button==11)
     {
         f->bf=0;
         s->bf=0;
     }
     else
     {
         /////写博客时，发现这里有问题///////////////////
     //    if(button==1)    choice=-choice;
         /////但是为什么我测试的时候怎么都对?!///////////
 /////经再次测试，上边确实错了!!!////////////////
 /////改为下边应该就对了吧///////////////////////
         if(button==1)    {a^=b,b^=a,a^=b;}
         ////////////////////////////////////////////////
 
         if(choice==-1)    f->bf=a,s->bf=b;
         else if(choice==0)    f->bf=s->bf=0;
         else    f->bf=-b,s->bf=-a;
         
         ss->bf=0;
     }
 }
 //两节点变换函数
 void conversion(AVL *T,char direction)
 {
     AVL f=*T,s=f->child[direction];
 
     f->child[direction]=s->child[!direction];
     s->child[!direction]=f;
     *T=s;
 }
 //保持平衡函数
 void keepbalance(AVL *T,char fir,char sec)
 {
     AVL *s=&((*T)->child[fir]);
     int button=fir*10+sec;
 
     if(button==0 || button==11)
     {
         setfactor((*T),button);
         conversion(T,fir);
     }
     else
     {
         setfactor((*T),button);
         conversion(s,sec);
         conversion(T,fir);
     }
 }
 ///★★★★★★★★★★★★★★★★★★★★★★★★★★
 
 ///------------插入时的选向操作-------------------
 void selectforInsert(AVL *T,char *info,int direction)
 {
     AVL cur=*T;
     char firdirection,secdirection;
 
     if(direction==0)    (cur->bf)++;
     else    (cur->bf)--;
 
     if(cur->bf==0)    setbit(info,1,1);
     else if(cur->bf==-1 || cur->bf==1)    setbit(info,direction,2);
     else
     {        
         firdirection=direction;
         secdirection=getbit(*info,2);
         keepbalance(T,firdirection,secdirection);
         setbit(info,1,1);
     }
 }

bbTree_t* CreateAVLRoot()
{
    bbTree_t* bbt = malloc(sizeof(bbTree_t));
    if( NULL==bbt) return NULL;
    
    bbt->avlRoot = NULL;
    bbt->bf = 0;
    return bbt;
}

static int handleAvlNodeBf(avlNode_t* e,int type)
{
    if( NULL == e) 
        return -1;

    switch(e->bf)
    {
    case 0: // equal.
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        return -1;
        break;
    }
    return 0;
}

int InsertAVLNode(avlNode_t* root,avlNode_t* e)
{
    bbTree_t bbt = root->bbtRoot;
    if( root-> key > e->key )// left insert!
    {
        if(root->lChild == NULL)
        {
            root->lChild = e;
            bbt->istaller = true;
        else
            InsertAVLNode(root->lChild,e);
        if(bbt->istaller)
            handleAvlNodeBf(root,1);
    }
    else //right insert!!
    {
        if(root->rChild == NULL)
        {
            root->rChild = e;
            bbt->istaller = true;
        }
        else
            InsertAVLNode(root->lChild,e);
        if(bbt->istaller)
            handleAvlNodeBf(root,2);
    }
    return 0;
}

 //----------------------------------------------
 
//*********** Insertion Function ****************//
int InsertAVL(bbTree_t *root, avlNode_t* e)
{
    if( !root )
        return -1;
     
    /* if empty Root, just add this Node to Root! */
    if(!root->avlRoot)
    {
        root->avlRoot= e;
        return 0;
    }
    /* if the Node is in the avl tree, return false! 
       if the key is equal to the key of root return false! */
    if( root->avlRoot==e || root->e->key == e->key)
        return -1;
    
    return InsertAVLNode(root->avlRoot,e);
 }
 //*********************************************//
 
 //-------------删除时的选向操作--------------------
 void selectforDelete(AVL *T,char *info,char direction)
 {
     AVL cur=(*T);
     char firdirection,secdirection;
 
     if(direction==0)    (cur->bf)--;
     else    (cur->bf)++;
     
     if(cur->bf==0)    *info=0;
     else if(cur->bf==-1 || cur->bf==1)    *info=1;
     else
     {
         firdirection=!direction;
         ///调试时，发现这里少写了一个等号////////////////////
 //        if(cur->child[firdirection]->bf=1)    secdirection=0;草，真帅气!原来1==a这样写确实有必要!
         if(1==cur->child[firdirection]->bf)    secdirection=0;
         /////////////////////////////////////////////////////
         else    secdirection=1;
         keepbalance(T,firdirection,secdirection);
 
         /////////////////////////////////////////////////////////////////////////////////////////
 ///调试时，发现经过子树平衡操作后，*info不一定都是0，就是那个特殊情况，在setfactor中/////
 ///的那种特殊情况时，这里*info应改为1! 所以代码改如下：//////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////
     //    *info=1; 写代码时：这跟插入可不一样啊...该子树平衡了，它父节点的因子比变!
 //    *info=0;//因此，这还没完还要是0!! ............啊……这里不一定是0! 
 ////还是那个特殊情况搞的鬼!//
         if(cur->bf==0)    *info=0;
         else    *info=1;
         /////////////////////////////////////////////////////////////////////////////////////////
     }
 }
 //------------------------------------------------
 
 //-------------变向递归--辅助删点-----------------
 char find(AVL *gogal,AVL *p)
 {
     char info;
     AVL tp=NULL;
     
     if(NULL!=(*p)->child[0])
     {
         info=find(gogal,&((*p)->child[0]));
         if(info!=0)    return info;
         selectforDelete(p,&info,0);
     }
     else
     {
         (*gogal)->e=(*p)->e;
         tp=(*p)->child[1];
         free((*p));
         *p=tp;
         info=0;
     }
     return info;
 }
 //------------------------------------------------
 
 //**************删除操作*************************//
 char DeleteAVL(AVL *T,Elemtype e)
 {
     char info;
     AVL tp=NULL;
 
     if(!(*T))    return -1;//原if(!T)    return -1;于2011年11月29日8:59:15修改
     else if((*T)->e==e)
     {
         if(NULL!=(*T)->child[1])
         {
             info=find(T,&((*T)->child[1]));
             if(info!=0)    return info;
             selectforDelete(T,&info,1);
         }
         else
         {
             //////////////调试时，发现这样写不对!!!///////////////////////////////////////
         //    (*T)=(p=(*T)->child[0])-(free((*T)),0);//Just save a variable! 这里出问题
 //    (*T)=p-(free((*T)),0); 可以
 //    (*T)=(p=((*T)->child[0]))+(free((*T)),0); 不可以
             tp=((*T)->child[0]);
             free((*T));
             *T=tp;
             //调试时，发现这里漏了给info赋值
             info=0;
             ///////////////////////////////////////////////////////////////////////////////
         }
     }
     else if((*T)->e>e)
     {
         info=DeleteAVL(&(*T)->child[0],e);
         if(info!=0)    return info;
         selectforDelete(T,&info,0);
     }
     else
     {
         info=DeleteAVL(&(*T)->child[1],e);
         if(info!=0)    return info;
         selectforDelete(T,&info,1);
     }
     return info;
 }
 //************************************************//
 
 
 //*****************JUST FOR TEST************************//
 #define MOVE(x)    (x=(x+1)%1000)
 AVL queue[1000];
 
 void print(AVL p,int i)
 {
     int front,rear,temp,count;
 
     front=rear=-1; count=temp=0;
     queue[MOVE(rear)]=p; count++;
     
     printf("%d\n",i);
     while(front!=rear)
     {
         p=queue[MOVE(front)];    count--;
         
         
         if(p->child[0])    queue[MOVE(rear)]=p->child[0],temp++;
         if(p->child[1])    queue[MOVE(rear)]=p->child[1],temp++;
         
         printf("%d->%d ",p->e,p->bf);
         if(count==0)
         {
             printf("\n");
             count=temp;
             temp=0;
         }    
     }
     printf("\n");
 }
 //**************************************************//
 
 
 int main()
 {
     AVL T=NULL;
     int i,nodenum=0;
 
     freopen("input.txt","w",stdout);
     nodenum=100;
     for(i=0;i<nodenum;i++)
     {
         InsertAVL(&T,i);
     }
     
     print(T,-1);
 
     for(i=0;i<nodenum-1;i++)
     {
         DeleteAVL(&T,i);
         print(T,i);
     }
     
     return 0;
 }
