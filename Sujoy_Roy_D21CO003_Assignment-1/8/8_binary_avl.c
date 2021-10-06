#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define maxi 10000
struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d   ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

/*avl tree*/
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* ainsert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = ainsert(node->left, key);
    else if (key > node->key)
        node->right = ainsert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Node* asearch(struct Node * root, int k)
{
  if (root == NULL)
      return NULL;

  if (k < root->key)
      root->left  = asearch(root->left,k);
  else if (k > root->key)
      root->right = asearch(root->right, k);
  else if(k== root->key)// Equal keys are not allowed in BST
      return root;
}


void main()
{
    node *root;
    node *tmp;
    root = NULL;
    int r[maxi];

    struct Node *aroot = NULL;
    struct Node *atmp;
    for(int i =0; i<maxi;i++)
    {
      r[i]=rand();
    }

    clock_t begin = clock();
    for(int j=0;j<maxi;j++)
    insert(&root,r[j]);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    clock_t begin1 = clock();
    for(int k=0;k<maxi;k++)
    aroot=ainsert(aroot,r[k]);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    printf("\nPre Order Display of binary tree :\n");
    print_preorder(root);

    /* Search node into binary tree */
    int i=0;
    printf("\nenter the item to search:");
    scanf("%d",&i);
    clock_t begin2 = clock();
    tmp = search(&root, i);
    if (tmp)
    {
        printf("Searched node= %d is present\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    printf("Preorder traversal of the constructed AVL  tree is \n");
    preOrder(aroot);

    int s;
    printf("\n\nenter the element to search ");
    scanf("%d",&s);
    clock_t begin3 = clock();
    atmp = asearch(aroot,s);
    if (atmp)
    {
        printf("\n\nSearched node= %d is present\n", atmp->key);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
    clock_t end3 = clock();
    double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;

    printf("\nTime to insert in binary tree: %lf",time_spent );
    printf("\nTime to insert in AVL tree: %lf",time_spent1 );

    printf("\nTime needed to search the item in binary tree : %lf",time_spent2);
    printf("\nTime needed to search the item in AVL tree : %lf",time_spent3);

}
