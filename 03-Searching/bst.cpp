#include <bits/stdc++.h>
using namespace std;

enum side { LEFT, RIGHT };

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
} TreeNode;

void inOrderBST(TreeNode* T) {
  if (T == NULL) return;
  inOrderBST(T->left);
  cout << T->data << " ";
  inOrderBST(T->right);
}

TreeNode* createNodeBST(int n) {
  TreeNode* node = new TreeNode();
  node->data = n;
  node->left = node->right = node->parent = NULL;

  return node;
}

TreeNode* insertBST(TreeNode* T, int value) {
  if (T == NULL) T = createNodeBST(value);
  else
    if (value <= T->data) {
      T->left = insertBST(T->left, value);
      T->left->parent = T;
    }
    else {
      T->right = insertBST(T->right, value);
      T->right->parent = T;
    }
  return T;
}

bool searchBST(TreeNode* T, int value) {
  if (T == NULL) return false;
  else
    if (value == T->data) return true;
    else
      if (value < T->data)
        return searchBST(T->left, value);
      else
        return searchBST(T->right, value);
}

TreeNode* getBST(TreeNode* T, int value) {
  if (T == NULL) return NULL;
  else
    if (value == T->data) return T;
    else
      if (value < T->data)
        return getBST(T->left, value);
      else
        return getBST(T->right, value);
}

enum side checkChildSide(TreeNode* T) {
  if (T->parent->left == T) return LEFT;
  else return RIGHT;
}

TreeNode* extractIOSBST(TreeNode* T) {
  if (T->left == NULL) return T;
  return extractIOSBST(T->left);
}

void deleteBST(TreeNode* T, int value) {
  if (searchBST(T, value)) {
    TreeNode* dead = getBST(T, value);
    do {
      if (dead->left == NULL && dead->right == NULL) {
        if (checkChildSide(dead) == LEFT)
          dead->parent->left = NULL;
        else dead->parent->right = NULL;

        delete dead;
        return;
      }

      if (dead->left != NULL && dead->right == NULL) {
        if (checkChildSide(dead) == LEFT) {
          dead->parent->left = dead->left;
          dead->left->parent = dead->parent;
        }
        else {
          dead->parent->right = dead->left;
          dead->left->parent = dead->parent;
        }

        delete dead;
        return;
      }

      if (dead->left == NULL && dead->right != NULL) {
        if (checkChildSide(dead) == LEFT) {
          dead->parent->left = dead->right;
          dead->right->parent = dead->parent;
        }
        else {
          dead->parent->right = dead->right;
          dead->right->parent = dead->parent;
        }

        delete dead;
        return;
      }

      TreeNode* ios = extractIOSBST(T->right);
      swap(dead->data, ios->data);
      dead = ios;
    } while (true);
  }
  else cout << "El dato " << value << " no está en el BST.\n";
}

void destroyBST(TreeNode* T) {
  if (T == NULL) return;
  destroyBST(T->left);
  destroyBST(T->right);
  delete T;
}

void kElementAux(TreeNode* T, int k, TreeNode*& result, int& i, bool& isDone) {
  if (T == NULL || isDone) return;
  kElementAux(T->left, k, result, i, isDone);
  if (isDone) return;
  (++i);
  if (i == k) {
    result = T;
    isDone = true;
    return;
  }

  kElementAux(T->right, k, result, i, isDone);
}

TreeNode* kElement(TreeNode* T, int k) {
  if (k <= 0) return NULL;
  TreeNode* result = NULL;
  int i = 0;
  bool isDone = false;
  kElementAux(T, k, result, i, isDone);
  return result;
}

int nodeNumber(TreeNode* T) {
  if (T == NULL) return 0;
  return 1 + nodeNumber(T->left) + nodeNumber(T->right);
}

int nodeDepth(TreeNode* N, TreeNode* T) {
  if (N == NULL) return -1;
  if (T == N) return 0;
  int up = nodeDepth(N->parent, T);
  if (up == -1) return -1;
  else return up + 1;
}

TreeNode* deleteLeaves(TreeNode* T) {
  if (T == NULL) return NULL;

  if(T->left == NULL && T->right == NULL) {
    delete T;
    return NULL;
  }

  T->left = deleteLeaves(T->left);
  if (T->left != NULL) T->left->parent = T;
  
  T->right = deleteLeaves(T->right);
  if (T->right != NULL) T->right->parent = T;  

  return T;
}

int main() {
  TreeNode* T = NULL;

  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 52);
  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 16);
  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 3);
  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 75);
  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 90);
  inOrderBST(T);
  cout << "\n";
  T = insertBST(T, 66);
  inOrderBST(T);
  cout << "\n";

  deleteBST(T, 52);
  inOrderBST(T);
  cout << "\n";

  int k = 4;
  TreeNode* kth = kElement(T, k);
  if (kth) cout << k << "-esimo en inorden: " << kth->data << "\n";
  else cout << "k fuera de rango\n";

  int nodes = nodeNumber(T);
  cout << nodes << "\n";

  TreeNode* depth = getBST(T, 66);
  int nodeDepthCalc = nodeDepth(depth, T);
  cout << nodeDepthCalc << "\n";


  destroyBST(T);


  return 0;
}