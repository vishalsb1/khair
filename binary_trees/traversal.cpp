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




// traversal techiniques 


// dfs 
// 1 preorder 

void preorder_traversal(node* root){
    if(root==NULL)return;

    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    
}
// 2 inorder 
void inorder_traversal(node* root){
    if(root==NULL)return;

    preorder_traversal(root->left);
    cout<<root->data<<" ";
    preorder_traversal(root->right);
    
}

// 3 postorder 
void postorder_traversal(node* root){
    if(root==NULL)return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
    
}

// bfs 
// 1 level order traversal 

vector<vector<int>> level_order_traversal(node* root){

    vector<vector<int>> ans;
    queue<node*> q;

    if(root!=NULL){
        q.push(root);
    }

    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        
        for(int i=0;i<n;i++){
            node* temp=q.front();
            q.pop();

            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);

            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

// iterative traversals 

// itervative using stack

// adhi topcha uchla ani ans madhi taka , jar tyala right asla tr sstack madhi taka ani ssmae for right nassla tr kai nhi 

void iterative_pre(node* root){
    node* parent=root;
    stack<node*> st;
    

    if(parent!=NULL){
        st.push(parent);
    }else{
        cout<<"root is null";
        return ;
    }
    cout<<"iterative preorder traversal ->  ";
    while(!st.empty()){
        node* temp=st.top();

        st.pop();

        cout<<temp->data<<" ,";

        if(temp->right!=nullptr){
            st.push(temp->right);
        }
        if(temp->left!=nullptr){
            st.push(temp->left);
        }
    }
    cout<<endl;

}

//  iterative inorder 

void iterative_inorder(node* root){
    stack<node*> st;
    node* temp=root;
    cout<<"iterative inorder traversal ->  ";

    while(true){
        if(temp!=nullptr){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ,";
            temp=temp->right;
        }
    }
    cout<<endl;
}

// iterative postorder 

void iterative_postorder_2st(node* root){
//   2st represents 2 stacks
    stack<node*> left;
    stack<node*> right;

    node* n1=root;
    left.push(root);

    while(!left.empty()){
        node*temp=left.top();
        left.pop();

        // left asla tr left cha ghetla 
        if(temp->left!=nullptr){
            left.push(temp->left);
        }
        // right asla tr right cha ghetla 
        if(temp->right!=nullptr){
            left.push(temp->right);
        }
        // nanter dusrya stack madhi node push kela 
        right.push(temp);
    }

    // ek ek kadat gelo top varna 
    while(!right.empty()){
        node* temp=right.top();
        cout<<temp->data<<" ->";
        right.pop();
    }
    cout<<endl;

}

void iterative_postorder_1st(node* root){
    stack<node*>st;

    node* curr=root;
    // st.push(curr);

    while(curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            node* temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ->";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ->";
                }

            }else{
                curr=temp;
            }
        }
    }
}


void preInPostTraversal(node* root) {
    if (root == NULL) return;

    stack<pair<node*, int>> st;
    st.push({root, 1});

    vector<int> pre, in, post;

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else {
            post.push_back(it.first->data);
        }
    }

    // 🔹 Printing Preorder
    cout << "Preorder: ";
    for (int x : pre) {
        cout << x << " ";
    }
    cout << endl;

    // 🔹 Printing Inorder
    cout << "Inorder: ";
    for (int x : in) {
        cout << x << " ";
    }
    cout << endl;

    // 🔹 Printing Postorder
    cout << "Postorder: ";
    for (int x : post) {
        cout << x << " ";
    }
    cout << endl;
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


    // cout<<"preorder traversal-> ";
    // preorder_traversal(root);
    // cout<<endl;

    // cout<<"inorder traversal-> ";
    // inorder_traversal(root);
    // cout<<endl;


    // cout<<"postorder traversal-> ";
    // postorder_traversal(root);
    // cout<<endl;

    // vector<vector<int>> ans_lot=level_order_traversal(root);

    // for(int i=0;i<ans_lot.size();i++){
    //     int n=ans_lot[i].size();

    //     for(int j=0;j<n;j++){
    //         cout<<ans_lot[i][j];
    //     }cout<<endl;
    // }

    // iterative_pre(root);
    // iterative_inorder(root);
    // iterative_postorder_2st(root);
    // iterative_postorder_1st(root);

    preInPostTraversal(root);
    return 0;
}
