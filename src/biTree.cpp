
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <biTree.h>

static int rightBallance(avlNode_t* e);
static int leftBalance(avlNode_t* e);
static int InsertAVLNode(avlNode_t* root,avlNode_t* e);
static void* searchAvlNode(avlNode_t* e,unsigned int key);
static int handleAvlNodeBf(avlNode_t* e,int type);
static void lRotate(avlNode_t* e);
static void rRotate(avlNode_t* e);


avlNode_t* createBBTNode(int key,void* val)
{
    avlNode_t*  avl = NULL;
    avl = (avlNode_t*) malloc( sizeof(avlNode_t) );
    if( NULL == avl ) return NULL;

    avl->bf  = 0;
    avl->key = key;
    avl->element = val;
    avl->lChild  = NULL;
    avl->rChild  = NULL;
    avl->bbtRoot = NULL;

    return avl;
}
 

bbTree_t* CreateAVLRoot()
{
    bbTree_t* bbt = (bbTree_t*)malloc(sizeof(bbTree_t));
    if( NULL==bbt) return NULL;
    
    bbt->avlRoot = NULL;
    bbt->isTaller = 0;
    return bbt;
}


//----------------------------------------------
/*********** Insertion Function ****************/
int InsertAVL(bbTree_t *root, avlNode_t* e)
{
    if( !root || !e)
        return -1;

    /* set bbt Root */
    e->bbtRoot = root;
    /* if empty Root, just add this Node to Root! */
    if(!root->avlRoot)
    {
        root->avlRoot = e;
        return 0;
    }
    /* if the Node is in the avl tree, return false! 
       if the key is equal to the key of root return false! */
    if( root->avlRoot==e || root->avlRoot->key == e->key)
        return -1;
    
    return InsertAVLNode(root->avlRoot,e);
}

void* searchAVL(bbTree_t* root,unsigned int key)
{
    if( !root )
        return NULL;
    return searchAvlNode(root->avlRoot,key);
}

void printAvl(avlNode_t* root)
{
   if(root == NULL)
      return;

   printf("Root key=0x%08X \n",root->key);
   printAvl(root->lChild);
   printAvl(root->rChild);
}

//----------------------------------------------
/*********** Searching Function ****************/
static void* searchAvlNode(avlNode_t* e,unsigned int key)
{
    if(e == NULL )
        return NULL;
    printf("Searching for 0x%08x, current: 0x%08X \n",key,e->key);

    if(e->key > key)
        return searchAvlNode(e->lChild,key);
    if(e->key < key)
        return searchAvlNode(e->rChild,key);
    return e->element;
}

//----------------------------------------------
/*********** Insertion Function ****************/
static int InsertAVLNode(avlNode_t* root,avlNode_t* e)
{
    bbTree_t* bbt = (bbTree_t*)root->bbtRoot;
    if( root-> key > e->key )// left insert!
    {
        if(root->lChild == NULL)
        {
            root->lChild = e;
            bbt->isTaller = 1;
        }
        else
            InsertAVLNode(root->lChild,e);
        if(bbt->isTaller)
            handleAvlNodeBf(root,1);
    }
    else //right insert!!
    {
        if(root->rChild == NULL)
        {
            root->rChild = e;
            bbt->isTaller = 1;
        }
        else
            InsertAVLNode(root->lChild,e);
        if(bbt->isTaller)
            handleAvlNodeBf(root,2);
    }
    return 0;
}

/**************************************************/
static int handleAvlNodeBf(avlNode_t* e,int type)
{
    bbTree_t* bbt = (bbTree_t*) e->bbtRoot;
    if( NULL == e) 
        return -1;

    return 0;

    switch(e->bf)
    {
    case 0: // equal.
        printf("Equal===>  set Node Bf=(%d)\n",type);
        e->bf = type;// left 1, right 2
        break;
    case 1: // left high
        if(type == 1) // left high, insert left, need leftBalance & after balance equal.
            leftBalance(e);
        else // Left high ,insert right... so hight equal.
            e->bf = 0;
        bbt->isTaller = 0;
        break;
    case 2: // right high
        if(type == 1)
            e->bf = 0;
        else
            rightBallance(e);
        bbt->isTaller = 0;
        break;
    default:
        return -1;
        break;
    }
    return 0;
}




static int rightBallance(avlNode_t* e)
{
    avlNode_t* rc = e->rChild;
    avlNode_t* rlc = rc->lChild;
    switch(rc->bf)
    {
    case 0:// none here!!
        break;
    case 2:// right high
        e->bf=0;
        rc->bf = 0;
        lRotate(e);
        break;
    case 1: //left high
        switch(rlc->bf)
        {
        case 0:
            rc->bf = 0;
            e->bf = 0;
            break;
        case 1:
            rc->bf = 0;
            e->bf = 2;
            break;
        case 2:
            e->bf = 1;
            rc->bf = 0;
            break;
        }//switch
        rlc->bf = 0;
        rRotate(e->rChild);
        lRotate(e);
        break;
    default:
        break;
    }
    return 0;
}
static int leftBalance(avlNode_t* e)
{
    return 0;
}

static void lRotate(avlNode_t* e)
{
}


