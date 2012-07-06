/*********************************
 *
 *
** */


#ifndef __BITREE__MEM_PRJECT__H__
#define __BITREE__MEM_PRJECT__H__

class biNode
{
public:
    unsigned long key;
    biNode *lChild;
    biNode *rChild;
    void* element;
    biNode(){
        key     = 0;
        lChild  = NULL;
        rChild  = NULL;
        element = NULL;
    }
};

class biTree{
public:
  biTree();
  ~biTree();
public:
  biNode*    getRoot();
  biNode*    createNode(unsigned long key,void* val);
  int        insNode(biNode* node);
  void*      searchKey(unsigned long key);
  void       travelBiTree();
private:
  void       destroy(biNode*);
  void       travelBiTreeNode(biNode* e);
  int        InsertNode(biNode* root,biNode* e);
  void*      searchNode(biNode* e,unsigned long key);
private:
  biNode* biRoot;
};

#endif



