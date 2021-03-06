
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <biTree.h>

static int InsertAVLNode(avlNode_t* root,avlNode_t* e);
static void* searchAvlNode(avlNode_t* e,unsigned int key);


avlNode_t* createBBTNode(int key,void* val)
{
    avlNode_t*  avl = NULL;
    avl = (avlNode_t*) malloc( sizeof(avlNode_t) );
    if( NULL == avl ) return NULL;

    avl->key = key;
    avl->element = val;
    avl->lChild  = NULL;
    avl->rChild  = NULL;

    return avl;
}
 

bbTree_t* CreateAVLRoot()
{
    bbTree_t* bbt = (bbTree_t*)malloc(sizeof(bbTree_t));
    if( NULL==bbt) return NULL;
    
    bbt->avlRoot = NULL;
    return bbt;
}


//----------------------------------------------
/*********** Insertion Function ****************/
int InsertAVL(bbTree_t *root, avlNode_t* e)
{
    if( !root || !e)
        return -1;

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
    if( root-> key > e->key )// left insert!
    {
        if(root->lChild == NULL)
            root->lChild = e;
        else
            return InsertAVLNode(root->lChild,e);
    }
    else //right insert!!
    {
        if(root->rChild == NULL)
            root->rChild = e;
        else
            return InsertAVLNode(root->rChild,e);
    }
    return 0;
}



