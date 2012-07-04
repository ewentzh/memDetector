/*********************************
 *
 *
** */


#ifndef __BITREE__MEM_PRJECT__H__
#define __BITREE__MEM_PRJECT__H__

struct BiNode{
  void* elementPtr;
  int   key;
  BiNode* parent;
  BiNode* lChild;
  BiNode* rChild;
 
  // BiNode Construction Function!
  BiNode(){
   elementPtr = NULL;
   priority = 0;
   parent = NULL;
   lChild = NULL;
   rChild = NULL;
 } 
};

class BiTree
{
public:
  void BiTree();
  ~BiTree();

  BiNode* getBiTreeRoot() const;
  void    insertBiNode(BiNode* node);
  void     
private:
  BiNode* biNodeRoot;
};


#endif



