#include<bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    node *left, *right;
    int height;
};

node* newNode(int key_value)
{
    node* temp = new node{key_value, NULL, NULL, 1};
    return temp;
}

int height(node* node)
{
    if(node == NULL)
        return 0;
    else
        return node->height;
}

node* leftRotate(node* x)
{
    node* y = x->right;
    node* z = y->left;
    x->right = z;
	y->left = x;
	x->height = height(x->left) > height(x->right) ? height(x->left) : height(x->right);
	y->height = height(y->left) > height(y->right) ? height(y->left) : height(y->right);
	return y;
}

node* rightRotate(node* x)
{
    node* y = x->left;
    node* z = y->right;
    x->left = z;
    y->right = x;
    x->height = height(x->left) > height(x->right) ? height(x->left) : height(x->right);
	y->height = height(y->left) > height(y->right) ? height(y->left) : height(y->right);
	return y;
}

int balanceFactor(node* node)
{
    if(node == NULL)
        return 0;
    return height(node->left)-height(node->right);
}

node* insert(node* root, int key_value)
{
    if(root == NULL)
        return newNode(key_value);
    if(key_value < root->key)
        root->left = insert(root->left, key_value);
    else if(key_value > root->key)
        root->right = insert(root->right, key_value);
    else
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && key_value < root->left->key)
        return rightRotate(root);
    if(balance < -1 && key_value > root->right->key)
        return leftRotate(root);
    if(balance > 1 && key_value > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key_value < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

node* deleteNode(node* root, int key_value)
{
    if(root == NULL)
        return root;
    if(key_value < root->key)
        root->left = deleteNode(root->left, key_value);
    else if(key_value > root->key)
        root->right = deleteNode(root->right, key_value);
    else{
        if((root->left == NULL)||(root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            node* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if(root == NULL)
        return root;
    root->height = 1+max(height(root->left), height(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && key_value < root->left->key)
        return rightRotate(root);
    if(balance < -1 && key_value > root->right->key)
        return leftRotate(root);
    if(balance > 1 && key_value > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key_value < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

node* search(int key_value, node* root)
{
    if(root == NULL || root->key == key_value)
        return root;
    if(root->key > key_value)
        return search(key_value, root->left);
    return search(key_value, root->right);
}

int main()
{
    node *root = NULL;

  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    inorder(root);
    root = deleteNode(root, -1);
    inorder(root);
    return 0;
}