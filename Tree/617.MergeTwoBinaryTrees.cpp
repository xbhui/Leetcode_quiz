#include<iostream>

using namespace std;

struct TreeNode {
  int value;
  TreeNode left;
  TreeNode right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1,TreeNode* t2){

      if(t1 == NULL)
        return t2;
      if(t2 == NULL)
        return t1;
      t1.value +=t2.value
      t1.left = mergeTrees(t1.left,t2.left);
      t1.right = mergeTrees(t1.right,t2.right);
      return t1;

  }
}

void printTree(struct TreeNode* node){
  if(node == NULL) return ;
  printTree(node->left);
  printf("%d\n", node->value);
  printTree(node->right);
}

struct TreeNode * insertNode(TreeNode *node,int data)
{
  node->value = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main (){
  TreeNode *root1 = NULL;
  TreeNode *nodeLeft1 = NULL;
  TreeNode *nodeRight1 = NULL;

  root1 = insertNode(new TreeNode,3);
  nodeLeft1 = insertNode(new TreeNode,-1);
  root1->left = nodeLeft1;
  nodeRight1 = insertNode(new TreeNode,-2);
  root1->right = nodeRight1;

  nodeLeft1->left = insertNode(new TreeNode,5);
  nodeLeft1->right = insertNode(new TreeNode,7);
  nodeRight1->left = insertNode(new TreeNode,1);

  TreeNode *root2 = NULL;
  TreeNode *nodeLeft2 = NULL;
  TreeNode *nodeRight2 = NULL;

  root2 = insertNode(new TreeNode,3);
  nodeLeft2 = insertNode(new TreeNode,-1);
  root2->left = nodeLeft2;
  nodeRight2 = insertNode(new TreeNode,-2);
  root2->right = nodeRight2;

  nodeLeft2->left = insertNode(new TreeNode,5);
  nodeLeft2->right = insertNode(new TreeNode,7);
  nodeRight2->left = insertNode(new TreeNode,1);


  TreeNode * node = mergeTrees(root1,root2);
  printTree(node);

  return 0;
}
