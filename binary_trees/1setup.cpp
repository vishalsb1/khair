// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    
    node* left;
    node* right;
    
    node(){
        this->left=NULL;
        this->right=NULL;
    }
    
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


// creating an tree using recursion 
node *create_tree(){
    int data;
    cin>>data;
    
    if(data==-1){
        return NULL;
    }
    node *newnode=new node(data);

    // left la create karaycha
    newnode->left=create_tree();

    // atta right cha
    newnode->right=create_tree();

    return newnode;

}

int main() {
    
    cout<<"give inputs for the tree \n Elements are pushed in preorder format (Root → Left → Right).For each node, first enter the left child,\n then the right child, and use -1 to indicate no node (NULL). The function recursively creates nodes and links them to form the binary tree."<<endl;
    node* root=create_tree();

    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4  5  6   7

    //input-> 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout<<root->left->data<<endl;
    return 0;
}
