
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <biTree.h>




biTree::biTree()
{
  this->biRoot = NULL;
}

biTree::biTree(biTree& bt)
{
  printf("Not Supported Yet!!\n");
  bt.biRoot = NULL;
}

biTree::~biTree()
{
  this->destroy(this->biRoot);
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

int biTree::insNode(unsigned long key,void* val)
{
  biNode* node = NULL;
  node = this->createNode(key,val);
  if(node == NULL)
    return -1;
  this->insNode(node);
}

int biTree::delNode(biNode* node)
{
  return this->delNode(node->key);
}

int biTree::delNode(unsigned long key)
{
  biNode* btparent = NULL;
  biNode* tmp,*ctree = NULL;

  if(this->biRoot == NULL)
    return 0;

  if(this->biRoot->key == key)
  {
    ctree = this->biRoot;
    if(this->biRoot->rChild == NULL)
    {
      this->biRoot = this->biRoot->lChild;
      free(ctree);
    }
    else
    {
      while(ctree->rChild != NULL)
      {
        btparent = ctree;
        ctree = ctree->rChild;
      }
      btparent->rChild = ctree->lChild;
      ctree->rChild = this->biRoot->rChild;
      ctree->lChild = this->biRoot->lChild;
      free(this->biRoot);
      this->biRoot = ctree;
    }
    return 0;
  }

  btparent = this->biRoot;
  ctree = this->biRoot;
  while(ctree != NULL)
  {
    if(ctree->key == key)
      break;
    else if(ctree->key > key)
    {
      btparent = ctree;
      ctree = ctree->lChild;
    }
    else
    {
      btparent = ctree;
      ctree = ctree->rChild;
    }
  }
  /* Now ctree is the one to delete!!!!
   * btparent is the farther node of ctree!!  */
  if(ctree == this->biRoot ) // formal branch....
  {
    //should not get here!!
  }
  biNode* deleteNode = ctree;
  biNode* tmpFather = ctree;

  while( ctree->rChild != NULL )
  {
    tmpFather = ctree;
    ctree = ctree->rChild;
  }
  /* Now ctree is the one which replace the deleteNode;
   * */
  if( deleteNode == btparent->rChild)
    btparent->rChild = ctree;
  else
    btparent->lChild = ctree;
  ctree->rChild = deleteNode->rChild;
  ctree->lChild = deleteNode->lChild;
  free(deleteNode);

  return 0;
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

void biTree::destroy(biNode* root)
{
   if( root == NULL )
     return;
   if(root->lChild == NULL && root->rChild == NULL)
   {
     free(root);
     return;
   }
   if(root->lChild != NULL)
   {
     destroy(root->lChild);
     root->lChild = NULL;
   }
   if(root->rChild != NULL)
   {
     destroy(root->rChild);
     root->rChild = NULL;
   }
}



