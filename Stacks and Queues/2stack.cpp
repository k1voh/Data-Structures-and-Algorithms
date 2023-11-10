/*Write a C++ program to implement two stacks in a single array such that the space is used
efficiently.  Do not read the size of each stack in advance from the user.  Do not make equal
partition*/

#include<iostream>
#define MAX 100
using namespace std;

class Stk{
    int arr[MAX];
    int top1, top2;

    public:
        Stk(){
            top1 = -1;
            top2 = MAX;
        }

        void push1(int n){
            if(top1 == top2){
                cout << "STACK OVERFLOW";
                return;
            }
            arr[top1++] = n;
        }

        void push2(int n){
            if(top1 == top2){
                cout << "STACK OVERFLOW";
                return;
            }
            arr[top2--] = n;
        }

        int pop1(){
            if(top1 == -1){
                cout << "STACK UNDERFLOW";
                return -9999;
            }
            return arr[top1--];
        }

        int pop2(){
            if(top2 == MAX){
                cout << "STACK UNDERFLOW";
                return -9999;
            }
            return arr[top2++];
        }

        void display1(){
            int i;
            for(i = top1; i > -1; i--){
                cout << arr[i] <<" ";
            }
            cout << endl;
        }

        void display2(){
            int i;
            for(i = top2; i < MAX; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Stk s;
    s.push1(5);
    s.push1(10);
    s.push1(15);
    s.push2(24);
    s.push2(48);
    cout << s.pop1();
    cout << s.pop2();
    s.display1();
    s.display2();
    return 0;
}