#include<iostream>
#include<queue>
#define MAX 100
#include<math.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

class stk{

    private:
        Node* arr[MAX];
        int top;
    
    public:
        stk(){
            top = -1;
        }

        void push(Node* root){
            if(top == (MAX - 1)){
                cout << "STACK OVERFLOW" <<endl;
                return;
            }
            arr[++top] = root;
        }

        Node* pop(){
            if(top == -1){
                //cout << "STACK UNDERFLOW" <<endl;
                return NULL;
            }
            return arr[top--];
        }

        bool isEmpty(){
            return top == -1;
        }

        Node* peak(){
            return arr[top];
        }

};

/* LEVEL ORDER*/
void lvl_order(Node* root){
    if(root == NULL)return;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* cur = q.front();
        cout << cur -> data << " ";
        q.pop();
        if(cur -> left){
            q.push(cur -> left);
        }
        if(cur -> right){
            q.push(cur -> right);
        }
    }
    cout << endl;
}


/* ITERATIVE INORDER */
void iter_inOrder(Node* root){
    stk s;
    while(true){
        for(;root;root = root -> left){
            s.push(root);
        }
        root = s.pop();
        if(!root) break;
        cout << root -> data;
        root = root -> right;
    }
}

/* ITERATIVE PREORDER GG */
void iter_preOrder(Node* root){
    Node *cur = root;
    stk s;

    while(cur -> data != NULL){
        cout << cur -> data;
        if(cur -> right != NULL){
            s.push(cur -> right);
        }
        if(cur -> left != NULL){
            s.push(cur -> left);
        }
        cur = s.pop();
    }

}

/* ITERATIVE POSTORDER GG? */
/* GAY LODE */
void iter_postOrder(Node* root){
    stk s;
    
    while(!s.isEmpty()){
        for(;root;root = root -> left){
        if(root -> right){
            s.push(root -> right);
            s.push(root);
        }
        else{
            s.push(root);
        }
        }
        root = s.pop();
        if(root -> right && root -> right == s.peak()){
            s.pop();
            s.push(root);
            root = root -> right;
        }
        if(!root -> right || root -> right != s.peak()){
            cout << root -> data;
            root = NULL;
        }
    }
}

/* parent of node*/
void parentOf(Node* parent, Node* current, int x){
    if(current == NULL){
        return;
    }
    if(current -> data == x && parent == NULL){
        cout << "is root" <<endl;
        return;
    }
    if(current -> data == x){
        cout << "parent is : " << parent -> data << endl;
    }
    parentOf(current, current -> right, x);
    parentOf(current, current -> left, x);
}
/* TOTAL NODES */

int nodeCount(Node* root){
    if(!root) return 0;
    return (1 + nodeCount(root -> left) + nodeCount(root -> right));
}

/* leaf nodes*/
int leaf(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }
    return leaf(root -> left) + leaf(root -> right);
}

/* 2 degree Node*/

int twoDegreeNode(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left != NULL && root -> right != NULL){
        return 1 + twoDegreeNode(root->left) + twoDegreeNode(root->right);
    }
    if((root -> left == NULL && root -> right != NULL) || (root -> left != NULL && root -> right == NULL)){
        return twoDegreeNode(root->left) + twoDegreeNode(root->right);
    }   
}

/* Ancestor*/
bool ancestor(Node* current, int key){
    if(current == NULL){
        return false;
    }
    if(current -> data == key){
        return true;
    }
    if(ancestor(current -> right, key) || ancestor(current -> left, key)){
        cout << current -> data <<" ";
        return true;
    }
    else{
        return false;
    }
}

/* DEPTH OF A NODE*/
int depth(Node* current){
    if(current == NULL){
        return 0;
    }
    int depthl = depth(current -> left);
    int depthr = depth(current -> right);
    if(depthl > depthr){
        return depthl+1;
    }
    else{
        return depthr+1;
    }
}

/* MINIMUM DEPTH OF A NODE*/
int minDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    return !root -> right || !root -> left ? 1+max(minDepth(root->left),minDepth(root->right)) : 1+min(minDepth(root->left),minDepth(root->right)); 
}

Node* createTree(){
    Node* root;
    char data;
    cout << "Enter Data : " <<endl;
    cin >> data;

    if(data == '#') return NULL;

    root = new Node(data - '0');
    
    cout << "Enter left for "<<data<<endl;
    root->left = createTree();

    cout <<"Enter right for "<<data<<endl;
    root->right = createTree();

    return root;


}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data <<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

/* HEIGHT OF A TREE*/
int height(Node* root){
    if(root == NULL) return 0;

    return max(height(root->left),height(root->right))+1;
}

/* DIAMETER OF A TREE*/
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int dia_left = diameter(root -> left);
    int dia_right = diameter(root -> right);
    int cur = height(root -> left) + height(root ->right) + 1;
    
    return max(cur, max(dia_left,dia_right));
}


/* LOWEST COMMON ANCESTOR */
Node* LCA(Node* root, int n1, int n2){
    if (root == NULL){
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2){
        return root;
    }

    Node* left = LCA(root -> left, n1, n2);
    Node* right = LCA(root -> right, n1, n2);

    if(left == NULL) return right;
    if(right == NULL) return left;

    return root; 
}

/* CHECK TREE EQUIVALENCE*/
bool isSameTree(Node* rootA, Node* rootB){
    if(!rootA && !rootB){
        return true;
    }
    if((!rootA && rootB ) || (rootA && !rootB)){
        return false;
    }
    if(rootA -> data != rootB -> data){
        return false;
    }

    return isSameTree(rootA -> left, rootB -> left) && isSameTree(rootA -> right, rootB -> right);
}

/* MIRROR OF A TREE*/
void mirror(Node* root){
    if(!root)
        return;

    mirror(root -> left);
    mirror(root -> right);

    Node* temp;
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

}

/* CREATING A COPY OF A TREE*/

Node* copy(Node* root){
    if(!root){
        return NULL;
    }
    Node* temp = new Node(root -> data);
    temp -> left = copy(root -> left);
    temp -> right = copy(root -> right);

    return temp;
}

int main(){
    Node* root;
    

    root = createTree();
    //iter_preOrder(root);
    //iter_postOrder(root);
    //inOrder(root);



    lvl_order(root);
    mirror(root);
    lvl_order(root);

    /*
    cout << endl;
    cout << nodeCount(root) - leaf(root);
    cout <<endl;
    cout << twoDegreeNode(root);*/

    return 0;
}