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



bool search_rec(node* root, int value){
    if(root==nullptr){
        return false;
    }


    if(value==root->data){
        return true;
    }else if(root->data<value){
        return search_rec(root->right,value);
    }else{
        return search_rec(root->left,value);
    }
}


bool search(node* root,int value){
    while(root!=NULL ){
        if(root->data==value) return true;
        if(root->data<value){
            root=root->right;
        }else{
            root=root->left;
        }
    }

    return false;
}


int ceil(node* root,int key){
    if(root==nullptr) return 0;

    int c=-1;//ceil value
    while(root){
        if(root->data==key){
            return key;
        }else if(root->data>key){
            c=root->data;
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return c;
}

int main(){

    node* root=create_tree();

    // cout<<search(root,999);

    int key=5;
    cout<<ceil(root,key);
    return 0;
}