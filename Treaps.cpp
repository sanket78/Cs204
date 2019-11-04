#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct Node{
    lli key;
    lli priority;
    struct Node *left,*right;
};


Node * newNode(lli key){
    Node *temp= new Node;
    temp->key=key;
    temp->priority=rand()%100;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* search(Node* root, lli key){
    if((root==NULL)||(root->key==key)){
        return root;
    }
    if(root->key>key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

Node* leftrotate(Node* x){
    Node* y=x->right;
    x->right=y->left;
    y->left=x;
    return y;
}

Node* rightrotate(Node* y){
    Node* x=y->left;
    y->left=x->right;
    x->right=y;
    return x;
}

Node* insert(Node* root,lli key){
    if(root==NULL){
        return newNode(key);
    }
    if(root->key>=key){
        root->left=insert(root->left,key);
        if(root->priority < root->left->priority){
            root=rightrotate(root);
        }
        
    }else{
        root->right= insert(root->right,key);
        if(root->priority  < root->right->priority){
            root=leftrotate(root);
        }
        
    }
    return root;
}


Node* Delete(Node* root, lli key){
    if(root==NULL){
        return root;
    }
    if(root->key>key){
        root->left=Delete(root->left,key);
    }else if(root->key<key){
        root->right=Delete(root->right,key);
    }else{
    if(root->left==NULL){
        Node* temp=root->right;
        delete (root);
        root = temp;
        return root;
    }else if (root->right==NULL){
        Node* temp =root->left;
        delete(root);
        root=temp;
        return root;
    }else{
        if(root->left->priority>root->right->priority){
            root=rightrotate(root);
            root->right=Delete(root->right,key);
        }else{
            root=leftrotate(root);
            root->left=Delete(root->left,key);
        }
    }
    }
    return root;
}

void inorder(Node* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        cout << "key: "<< root->key << " | priority: %d "
            << root->priority; 
        cout << endl; 
        inorder(root->right); 
    } 
} 

int main(){
    srand(time(NULL));
    struct Node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 20\n"; 
    root = Delete(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 30\n"; 
    root = Delete(root, 30); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 50\n"; 
    root = Delete(root, 50); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    Node *result = search(root, 30); 
    if(result == NULL){
        cout << "\n30 Not Found \n";
    }
    else{ 
        cout << "\n30 found\n";
    }
  
  
    
    return 0;
}