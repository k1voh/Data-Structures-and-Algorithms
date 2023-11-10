#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

void del(char str[]){
    int i,j;

    for(i = 0, j = 0; str[i] != '\0'; i += 2, j++){
        str[j] = str[i+1];
    }
    str[j] = '\0';

    cout << str;
}

int main(){
    char str[MAX];
    cout << "Enter a String : " <<endl;
    gets(str);
    del(str);
    return 0;
}