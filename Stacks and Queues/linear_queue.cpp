#include<iostream>
#define MAX 100
using namespace std;

class Que{
    int que[MAX];
    int f,r;

public:
    Que(){
        f = r = -1;
    }

    void Enq(){
        if(r == MAX-1){
            cout << "Queue full"<<endl;
            return;
        }

        cout << "enter element";
        cin >> que[++r];

        if(f == -1){
            f = 0;
        }
    }

    void Deq(){
        if(f == r+1 || f == -1){
            cout << "Queue Empty"<<endl;
            return;
        }

        f++;
    }

    void disp(){
        if(f == r+1 || f == -1){
            cout << "Queue Empty" <<endl;
            return;
        }
        int i;
        for(i = f; i <= r; i++){
            cout << que[i] <<" ";
        }
    }

};


int main()
{
    int choice;
    char brk = 'Y';
    Que s;

    do
    {
        cout << "Enter your choice\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            s.Enq();
            break;
        }
        case 2:
        {
            s.Deq();
            break;
        }
        case 3:
        {
            s.disp();
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

    return 0;
}
