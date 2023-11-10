#include <iostream>
#define MAX 100
using namespace std;

class Stk{
    int top,arr[MAX];

    public:

    Stk(){
        top = -1;
    }
    
    void push()
    {
    int x;
    if(top == MAX-1){
        printf("Overflow\n");
    }
    else
    {
        printf("Enter element to be pushed\n");
        scanf("%d",&x);
        arr[++top]=x;
    }
    }

    void pop()
    {
    int x;
    if(top == -1){
        printf("Underflow\n");
    }
    else{
      top--;
    
    }
    }

    void show()
    {
    int i;

    for(i=top;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }
    } 
};

int main(){
    int choice;

    Stk s_obj;

        while(1)
        {
            printf("Operations that can be performed\n");
            printf("1.push\n2.pop\n3.display\n4.exit\n");
            scanf("%d",&choice);
            
            switch(choice)
            {
                case 1: s_obj.push();
                break;
                case 2: s_obj.pop();
                break;
                case 3: s_obj.show();
                break;
                case 4: exit(0);
                
                default: printf("Invalid\n");
            }
    }

    return 0;
}