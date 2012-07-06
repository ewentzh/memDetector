
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <biTree.h>




biTree::biTree()
{
  this->biRoot = NULL;
}

biTree::~biTree()
{
  this->destroy();
}


biNode* biTree::getRoot()
{
  return this->biRoot;
}

biNode* biTree::createNode(unsigned long key,void* val)
{
  biNode* node  = (biNode*)malloc(sizeof(biNode));

  if(!node) return NULL;
  node->key     = key;
  node->element = val;
  node->rChild  = NULL;
  node->lChild  = NULL;

  return node;
}
//----------------------------------------------
/*********** Insertion Function ****************/
int biTree::insNode(biNode* e)
{
  if(e == NULL)
    return -1;

  if( this->biRoot == NULL )
  {
    this->biRoot = e;
    return 0;
  }

  /* if the Node is in the avl tree, return false! 
     if the key is equal to the key of root return false! */
  if( this->biRoot==e || this->biRoot->key == e->key)
    return -1;
    
  return this->InsertNode(this->biRoot,e);
}

void biTree::travelBiTree()
{
   if(this->biRoot == NULL)
      return;

   this->travelBiTreeNode(this->biRoot);

}

void biTree::travelBiTreeNode(biNode* e)
{ 
  if(e == NULL)
    return;
  printf(" key=[0x%08X]\n",e->key);
  travelBiTreeNode(e->lChild);
  travelBiTreeNode(e->rChild);
}

void* biTree::searchKey(unsigned long key)
{
  return this->searchNode(this->biRoot,key);
}

//----------------------------------------------
/*********** Searching Function ****************/
void* biTree::searchNode(biNode* e,unsigned long key)
{
  if(e == NULL )
    return NULL;

  if(e->key > key)
    return this->searchNode(e->lChild,key);
  if(e->key < key)
    return this->searchNode(e->rChild,key);
  return e->element;
}

//----------------------------------------------
/*********** Insertion Function ****************/
int biTree::InsertNode(biNode* root,biNode* e)
{
    if( root-> key > e->key )// left insert!
    {
        if(root->lChild == NULL)
            root->lChild = e;
        else
            return InsertNode(root->lChild,e);
    }
    else //right insert!!
    {
        if(root->rChild == NULL)
            root->rChild = e;
        else
            return InsertNode(root->rChild,e);
    }
    return 0;
}

void biTree::destroy()
{

}



