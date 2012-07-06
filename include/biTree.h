/*********************************
 *
 *
** */


#ifndef __BITREE__MEM_PRJECT__H__
#define __BITREE__MEM_PRJECT__H__

typedef struct avlNode
{
    int key;
    struct avlNode *lChild;
    struct avlNode *rChild;
    void* element;
}avlNode_t;

typedef struct bbTree{
    avlNode_t* avlRoot;
}bbTree_t;


extern bbTree_t* CreateAVLRoot();
extern avlNode_t* createBBTNode(int key,void* val);
extern int InsertAVL(bbTree_t *root, avlNode_t* e);
extern void* searchAVL(bbTree_t* root,unsigned int key);
extern void printAvl(avlNode_t* root);



#endif



