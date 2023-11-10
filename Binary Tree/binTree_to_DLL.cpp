#include<iostream>
#include "tree.cpp"
using namespace std;

class Convert{
public:
    Node* prev = NULL;
    Node* head = NULL;

    Node* convertToDLL(Node* root){
        if(root == NULL) {
            return NULL;
        }
        convertToDLL(root -> left);
        if(prev == NULL){
            head = root;
        }
        else{
            root -> left = prev;
            prev -> right = root; 
        }
        prev = root;
        convertToDLL(root -> right);

        //root -> right = NULL;
        return head;
    }

    void display(Node* head){
        if(head == NULL){
            cout << "Empty list" <<endl;
            return;
        }
        Node *current = head;

        while(current){
            cout << current -> data << " ";
            current = current -> right;
        }

    }
};


int main(){
    
    Convert obj;
    Node *root, *head;
    root = createTree();
    inOrder(root);
    head = obj.convertToDLL(root);
    cout << endl;
    obj.display(head);

    return 0;
}
