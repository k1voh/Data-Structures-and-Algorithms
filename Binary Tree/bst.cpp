#include<iostream>
using namespace std;

class Node{
    int val;
    Node *left, *right;

    public:
        /* INSERTION */
        Node* insert(Node* root, int ele){
            // creation of a new temporary node
            Node *temp = new Node;
            temp -> val = ele;
            temp -> left = temp -> right = NULL;

            //if root is empty, temp is the new root
            if(root == NULL){
                return temp;
            }

            //two pointer for traversal, parent and child
            //parent of root is 'null' and child is 'root'
            Node* p = NULL;
            Node* c = root;

            //while child is not null
            //it will compare the value of each child
            //with the value of temp node created and traverse accordingly
            while(c != NULL){
                if(c -> val > temp -> val){
                    p = c;
                    c = c -> left;
                }
                else{
                    p = c;
                    c = c -> right;
                }
            }

            //after traversal append the node 
            //in its appropriate location
            //by checking if it's greater than the parent or not
            if(p -> val > temp -> val){
                p -> left = temp;
                return root;
            }
            else{
                p -> right = temp;
                return root;
            }
        }

        /* DISPLAY*/
        void display(Node* root, int level){
            if(root == NULL){
                return;
            }

            //recursive display of left nodes
            display(root -> left, level + 1);

            //printing spaces as per the number of level
            int i;
            for(i = 0; i < level; i++){
                cout << " ";
            }

            //printing of value
            cout << root -> val <<endl;

            //recursive dispaly of right nodes
            display(root -> right, level + 1);
        }

        /* SEARCHING IN BST*/
        bool search (Node* root, int x){
            if(root == NULL){
                return false;
            }

            if(root -> val = x){
                return true;
            }

            if(root -> val < x){
                return search(root -> right, x);
            }
            else{
                return search(root -> left, x);
            }
        }

        /* INORDER TRAVERSAL*/
        void inorder(Node* root){
            if(root == NULL){
                return;
            }

            inorder(root -> left);
            cout << root -> val << " ";
            inorder(root -> right);
        }

        /* NODE DELETION IN BST*/
        Node* deleteNode(Node* root, int ele){
            Node *parent, *child, *s;

            if(root == NULL){
                return;
            }

            parent = child = NULL;
            Node *q = root;
            while(q){
                if(q -> val == ele){
                    child = q;
                    break;
                }
                parent = q;
                if(q -> val > ele){
                    q = q -> left;
                }
                else{
                    q = q -> right;
                }
            }
            if(q == NULL){
                cout << "ELEMENT NOT FOUND\n";
                return root;
            }

            //DELETING TWO CHILD NODE
            if(child -> left != NULL && child -> right != NULL){
                parent = child;
                s = child -> right;

                while( s -> left != NULL){
                    parent = s;
                    s = s -> right;
                }

                child -> val = s -> val;
            }

            //DELETING ONE CHILD NODE
            if(child -> left != NULL && child -> right == NULL){
                if(parent -> left == child){
                    parent -> left = child -> left;
                }
                else{
                    parent -> right = child -> left;
                }
                delete child;
                return root;
            }

            if(child -> left == NULL && child -> right != NULL){
                if(parent -> left == child){
                    parent -> left = child -> right;
                }
                else{
                    parent -> right = child -> right;
                }
                delete child;
                return root;
            }

            //DELETING LEAF NODE
            if( child -> left == NULL && child -> right == NULL){
                if( parent -> right == child){
                    parent -> right = NULL;
                }
                else{
                    parent -> left = NULL;
                }
                delete child;
                return root;
            }
        }

        /* ALTERNATE METHOD TO DELETE*/

        Node* _delete(Node* root, int key){
            if(root == NULL){
                return root;
            }

            if(root -> val < key){
               root -> right = _delete(root -> right, key); 
            }
            else if(root -> val < key){
                root -> left = _delete(root -> left, key);
            }
            else{
                if(root -> left == NULL){
                    return root -> right;
                }
                else if(root -> right == NULL){
                    return root -> left;
                }
                root -> val = minValue(root -> right);
                root -> right = _delete(root -> right, root -> val);

            }
            return root;
        }

        int minValue(Node* root){
            int minV = root -> val;

            while(root -> left != NULL){
                minV = root -> left -> val;
                root = root -> left;
            }

            return minV;
        }
};

int main(){
    
    return 0;
}