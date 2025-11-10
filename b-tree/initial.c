#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 we are going to create the  b-tree ,  for that  we need  to right few  stuff
 what is  the rule to go:
  -> b-tree is  the concepty from binary-search ->  m-way search tree

  **RULES**: (if order = m)
  1. Root(if not leaf) would have minimum 2 children (or ceil(m/2)) and maximum
 m  (exception there for only leaf node)
  2. A node can have maximum m-1 keys and minimum ceil(m/2)-1 keys
  3. if during the insertion any key added break the maximum barrier then node
 is  split up using median ,and median is being shifted to the up to parent (it
 is a recursive process)
  5. It is being built from bottom up.
  6. Deletion :
    a. if key to be delete at the leaf  delete it ,
    b. if it is internal node then you have to
*/

/* we have to crack up the insertion first
lets  say we have the value 10 22 14 16 09 61 48
let says we have the m order here 3
so,
  we can have the 3 children for each node and  2 keys per node

10 22 14 16 09 61 48


            [10]

          [10, 22]

         [10,14,22]  #split the node

           [14]
           /  \
         [10] [22]
-----------------------------
(except root)
maximum keys in the node is  3-1 = 2  and  minimum keys would be ceil(3/2)-1 =
2-1 > "1"


           [14]
           /  \
         [10] [16, 22]

----

              [14]
             /      \
         [09,10]  [16, 22]

-----
               [14]
              /    \
           [09,10]  [16,22,61] # split the right

-----
               [14,  22]
              /    \    \
           [09,10]  [16] [61]

------
             [14,    22]
              /    \    \
           [09,10]  [16] [48,61] final one


## normal node for the  B-tree would be :

    [p0, k0,p1,k1,p2,k2,p3]


*/
#define M 3

typedef struct BTreeNode {
  bool is_leaf;
  int num_keys;
  int keys[M];
  struct BTreeNode *children[M + 1]; // only valid if is_leaf
} Node;

typedef struct SplitResult {
  int promoted_key;
  Node *left;
  Node *right;
  bool did_split;
} Split;

// what node needs is  keys and  children pointer
Node *init_node(bool is_leaf) {
  Node *node = malloc(sizeof(Node));
  node->is_leaf = is_leaf;
  node->num_keys = 0;
  for (int i = 0; i <= M; i++) {
    node->children[i] = NULL;
  }

  return node;
}

void insertion_sort(Node *node, int key) {
  int i = node->num_keys - 1;

  while (i >= 0 && node->keys[i] > key) {
    node->keys[i + 1] = node->keys[i];
    i--;
  }

  node->keys[i + 1] = key;
  node->num_keys++; // here we are updating the num_keys
}

// Insert promoted key
void insert_promoted(Node *parent_node, int promoted_key, Node *left,
                     Node *right) {
  int i = parent_node->num_keys - 1;

  while (i >= 0 && parent_node->keys[i] > promoted_key) {
    parent_node->keys[i + 1] = parent_node->keys[i];
    parent_node->children[i + 2] = parent_node->children[i + 1];
    // one  extra shift so that it stay aligned when
    // right pointer of child of promoted_key else
    // children would overidden
    i--;
  }

  parent_node->keys[i + 1] = promoted_key;
  parent_node->children[i + 1] = left;
  parent_node->children[i + 2] = right;

  parent_node->num_keys++; // here we are updating the num_keys

  // return i + 1; optional if required
}

Split *node_splitting(Node *node) {

  // now just half one side and other on another
  //
  Split *split_data = malloc(sizeof(Split));
  split_data->left = init_node(node->is_leaf);
  split_data->right = init_node(node->is_leaf);

  int mid = M / 2;
  // we have to copy
  for (int i = 0; i < mid; i++) {
    split_data->left->keys[i] = node->keys[i];
  }

  for (int i = mid + 1; i < M; i++) {
    split_data->right->keys[i - (mid + 1)] =
        node->keys[i]; // this is i-(mid+1) is only for the right keys will have
                       // from initials (not mid)
  }

  for (int i = 0; i <= mid; i++)
    split_data->left->children[i] = node->children[i];
  for (int i = mid + 1, j = 0; i <= M; i++, j++)
    // just new way without using i-(mid + 1)
    split_data->right->children[j] = node->children[i];

  split_data->promoted_key = node->keys[mid];

  // Updated the num_keys for the left and right splitted nodes
  split_data->left->num_keys = mid;
  split_data->right->num_keys = M - mid - 1;
  return split_data;

  // now point root node child pointer to these ones
}

Split *insert(Node *root, int key_val) {
  // we have to implement the recursive function which split the node if it
  // contain more than required now  scenario is bit  different here why like
  // the array of keys is static array so we cant insert it and get the median
  // for splitting situation
  // ...

  if (root->is_leaf == true) { // means only one node
    insertion_sort(root, key_val);
    if (root->num_keys == M) {
      // split it
      return node_splitting(root);
    }
    return NULL;

  }

  // now for the internal node insertion
  else {
    // navigate to right node before insertion
    Node *temp = root;
    Node *parent_node;
    while (!temp->is_leaf) {
      int i = 0;
      while (i <= temp->num_keys && key_val > temp->keys[i]) {
        i++;
      }
      parent_node = temp;
      temp = temp->children[i];
    }

    // now we have to check for split or not which we we have to ripple it
    // upward

    Split *result = insert(temp, key_val);
    if (!result) {
      return NULL;
    }

    insert_promoted(root, result->promoted_key, result->left, result->right);

    if (root->num_keys == M) {
      return node_splitting(root);
    }

    return NULL;
  }
}

int main() {}
