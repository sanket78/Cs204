#include <bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    node *l, *r;
};

node *newNode(int key_value)
{
    node *temp = new node{key_value, NULL, NULL};
    return temp;
}

node *insertRight(node *root, int key_value)
{
	if(root == NULL)
    return newNode(key_value);
	root->r =  insertRight(root->r, key_value);
	return root;
}

node *insertLeft(node *root, int key_value)
{
	if(root == NULL)
    return newNode(key_value);
	root->l =  insertLeft(root->l, key_value);
	return root;
}

void inorder(node* root)
{
    if(root == NULL)
      return;
    inorder(root->l);
    cout << root->key << " ";
    inorder(root->r);
}

bool search(node* root, int key_value)
{
    if(root == NULL)
        return false;
    if(root->key == key_value)
        return true;
    bool left = search(root->l, key_value);
    bool right = search(root->r, key_value);
    return left || right;
}

int getHeight(node* root)
{
    if(root == NULL)
        return 0;
    int lHeight = getHeight(root->l);
    int rHeight = getHeight(root->r);
    return 1+max(lHeight, rHeight);
}

int countNodes(node* root)
{
    int counter = 1;
    if(root == NULL)
        return 0;
    if(root->l != NULL)
    {
        counter+=countNodes(root->l);
    }
    if(root->r != NULL)
    {
        counter+=countNodes(root->r);
    }
    return counter;
}

int main(){
    node* root = NULL;
	root = insertLeft(root, 4);
		inorder(root);
	insertRight(root, 3);
		inorder(root);
insertLeft(root->r, 6);
	inorder(root);

insertLeft(root, 64);
	insertRight(root->l, 46);
	inorder(root);

insertRight(root, 57);

	inorder(root);
	cout<<endl;
	cout<<search(root, 84);
	cout << getHeight(root) << " " << countNodes(root);
}