#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this ->left =NULL;
        this->right =NULL;

    }
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

}

void levelordertraversal(Node* root){
     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        Node* temp =q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
     }





}

Node* incertioninbst(Node* root,int d){
    if(root==NULL){
        root= new Node(d);
        return root;
    }

    if(d > root->data){
       root->right = incertioninbst(root->right,d);
    }
    else{
       root->right = incertioninbst(root->right,d);
    }
    return root;
}


void takeinput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        incertioninbst(root,data);
        cin >> data;
    } 
}


int main(){
Node* root = NULL;
cout<<"enter the data to creat bst"<<endl;
takeinput(root);
cout<<"levelorder traversal of  the tree"<<endl;
levelordertraversal(root);
// 2  3 4 11 5 22 7 23 8 -1
return 0;
}



