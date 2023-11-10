#include<iostream>
#define MAX 5
using namespace std;

class Cque{

    int que[MAX];
    int f,r;  //front,rear;//

public:
    Cque(){
        r = -1;
        f = -1;
    }

    bool isEmpty(){
        if(f == -1){
            cout << "Queue Empty" <<endl;
            return true;
        }
        return false;
    }

    bool isFull(){
        if(f == (r+1)%MAX){
            cout << "Queue Full"<<endl;
            return true;;
        }
        return false;
    }

    void Enq(){
        if(f == (r+1)%MAX){
            cout << "Queue Full"<<endl;
            return;
        }
        int n;
        cout << "Enter the number you want to insert";
        cin >> n;

        r = (r+1)%MAX;
        que[r] = n;

        if(f == -1){
            f = 0;
        }
    }

    void Deq(){
        if(f == -1){
            cout << "Queue Empty" <<endl;
            return;
        }
        if(f == r){
            f = r =-1;
            return;
        }
        f = (f+1)%MAX;
        //que[f];
    }

    void disp(){
        if (f == -1){
            cout << "Queue Empty" <<endl;
            return;
        }
        int i;
        for(i = f; i != r; i = (i+1)%MAX){
            cout << que[i] << " ";
        }
        cout << que[i] <<endl;
    }
};

int main()
{
    int choice;
    char brk = 'Y';
    Cque c;

    do
    {
        cout << "Enter your choice\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            c.Enq();
            break;
        }
        case 2:
        {
            c.Deq();
            break;
        }
        case 3:
        {
            c.disp();
            break;
        }
        default:
        {
            cout << "INVALID INPUT" << endl;
        }
        }

        cout << "Do you want to continue? (Y/N)" << endl;
        cin >> brk;

    } while (brk != 'N');

    cout << endl << c.isEmpty() << " "<< c.isFull() <<endl;


    return 0;
}
