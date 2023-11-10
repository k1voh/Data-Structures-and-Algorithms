#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;


    Node* insertAtHead(Node* head){
        Node* temp = new Node;
        cout << "Enter the value to be inserted : " <<endl;
        cin >> temp -> value;
        temp->next = head;
        head = temp;
        return head;
    }

    Node* insertAtTail(Node* head){
        Node* temp = new Node;
        cout << "Enter the value to be appended : " <<endl;
        cin >> temp -> value;
        temp -> next = NULL;

        if(head == NULL){
            temp -> next = head;
            head = temp;
            return head;
        }

        Node* current = head;

        while(current->next != NULL){
            current = current->next;
        }

        current -> next = temp;
        return head;
    }

    Node* insertAfter(Node* head){
        Node* temp = new Node;
        Node* current;
        current = head;

        cout << "Enter key to insert after : " <<endl;
        int key;
        cin >> key;

        cout << "Enter value to be inserted : "<<endl;
        cin >> temp -> value;
        temp -> next = NULL;

        while(current != NULL && current -> value != key){
            current = current -> next;
        }
        if(current == NULL){
            cout << "Key not present" <<endl;
        }
        if(current -> value == key){
            temp -> next = current -> next;
            current -> next = temp;
        }
        return head;
    }


    Node* insertBefore(Node* head){
        Node* temp = new Node;
        Node* current;
        current = head;

        cout << "Enter key to insert before : " <<endl;
        int key;
        cin >> key;

        cout << "Enter value to be inserted : "<<endl;
        cin >> temp -> value;
        temp -> next = NULL;

        while( current != NULL && (current -> next -> value != key)){
            current = current -> next;
        }
        if(current == NULL){
            cout << "Key not present" <<endl;
        }
        if(current -> next -> value == key){
            temp -> next = current -> next;
            current -> next = temp;
        }
        return head;
    }

    Node* deleteValue(Node* head){
        cout << "enter value to be deleted" <<endl;
        int key;
        cin >> key;

        Node* memory;
        Node* current;
        current = head;

        while(current -> next != NULL){
            if(current -> next -> value == key){
                memory = current -> next;
                current -> next = current -> next -> next;
                delete memory;
                break;
            }
            current = current -> next;
        }
        return head;
    }

    Node* Traverse(Node* head){
        Node* current;
        current = head;

        while(current != NULL){
            cout << current -> value << " ";
            current = current -> next;
        }
        cout << endl;
        return head;
    }

    Node* reverseList(Node* head){
        Node *current, *prev, *temp;
        current = head;
        prev = NULL;
        temp = NULL;

        if(head == NULL){
            cout << "Empty list" <<endl;
            return head;
        }

        while(current != NULL){
            temp = current -> next;
            current -> next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
        return head;
    }

    //SORTING OF LINKED LIST

    Node* Sort(Node* head){
        Node *current = head;
        Node *current_next;
        Node *low;
        int temp;

        if(head == NULL){
            cout << "Empty List" << endl;
            return head;
        }
        //sorting
        while(current){
            low = current;
            current_next = current -> next;
            while(current_next){
                if(current_next -> value < low -> value){
                    low = current_next;
                }
                current_next = current_next -> next;
            }
            if(low != current){
                temp = current -> value;
                current -> value = low -> value;
                low -> value = temp;
            }
            current = current -> next;
        }
        return head;
    }

    Node* deleteAlternate(Node* head){
        Node *current = head, *temp;

        while(current != NULL && current -> next != NULL){
            temp = current -> next;
            current -> next = current -> next -> next;
            current = current -> next;
            delete temp;
        }

        return head;
    }

    Node* insertInOrder(Node* head){
        Node* temp = new Node;
        cout << "Enter value to be inserted : "<<endl;
        cin >> temp -> value;
        temp -> next = NULL;

        Node *current = head, *prev = NULL;

        if(head -> value > temp -> value){
            temp -> next = head;
            head = temp;
            return head;
        }

        while(current != NULL){
            if(current -> value > temp -> value){
                prev -> next = temp;
                temp -> next = current;
                break;
            }
            prev = current;
            current = current -> next;
        }

        if(current == NULL){
            prev -> next = temp;
        }

        return head;
    }

    Node* unionOf(Node* head){
        Node* head2 = NULL;
        int n;
        cout << "Number of elements in 2nd list : ";
        cin >> n;
        int i;
        for(i = 0; i < n; i++){
            head2 = insertAtTail(head2);
        }

        Node *cur = head, *cur2 = head2;

        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = head2;

        cur = head;
        Node* cur_next = head -> next;

        Node* prev = head;

        //delete duplicates
        while(cur && cur -> next){
            cur_next = cur;
            while(cur_next -> next){
                if(cur_next -> next -> value == cur -> value){
                    Node* temp = cur_next -> next;
                    cur_next -> next = cur_next -> next -> next;
                    delete temp;
                }
                else{
                    cur_next = cur_next -> next;
                }
            }
            cur = cur -> next;
        }

        return head;
    }

    Node* intersection(Node* head){
        Node* head2 = NULL;
        int n;
        cout << "Number of elements in 2nd list : ";
        cin >> n;
        int i;

        for(i = 0; i < n; i++){
            head2 = insertAtTail(head2);
        }

        Node* cur = head;
        Node* cur_next = head2;

        Node* inter_head = NULL;

        while(cur){
            cur_next = head2;
            while(cur_next){
                if(cur -> value == cur_next -> value){
                    inter_head = insertAtTail(inter_head);
                }
                cur_next = cur_next -> next;
            }
            cur = cur -> next;
        }

        return inter_head;
    }

};

int main(){
    Node obj;
    Node* head;
    head = NULL;
    int choice;

    cout << "Actions to be performed : "<<endl;
    cout << "1. Insert at head"<<endl;
    cout << "2. Insert at tail "<<endl;
    cout << "3. Insert before any element"<<endl;
    cout << "4. Insert after any element"<<endl;
    cout << "5. Delete a given element"<<endl;
    cout << "6. Traverse the list"<<endl;
    cout << "7. Reverse the list"<<endl;
    cout << "8. Sort the list"<<endl;
    cout << "9. Delete every alternate node in the list"<<endl;
    cout << "10. Insert an element in Sorted order"<<endl;
    cout << "11. Union of TWO linked lists"<<endl;
    cout << "12. Intersection of TWO linked lists" <<endl;

    while(true){
        cout << "Enter Choice" <<endl;
        cin >> choice;
        switch(choice){
        case 1:
            head = obj.insertAtHead(head);
            break;
        case 2:
            head = obj.insertAtTail(head);
            break;
        case 3:
            head = obj.insertBefore(head);
            break;
        case 4:
            head = obj.insertAfter(head);
            break;
        case 5:
            head = obj.deleteValue(head);
            break;
        case 6:
            head = obj.Traverse(head);
            break;
        case 7:
            head = obj.reverseList(head);
            break;
        case 8:
            head = obj.Sort(head);
            //cout << "WORK IN PROGRESS" <<endl;
            break;
        case 9:
            head = obj.deleteAlternate(head);
            break;
        case 10:
            head = obj.insertInOrder(head);
            break;
        case 11:
            head = obj.unionOf(head);
            break;
        case 12:
            head = obj.intersection(head);
            break;
        default:
            cout << "Invalid Input" <<endl;
            break;
        }
    }

}
