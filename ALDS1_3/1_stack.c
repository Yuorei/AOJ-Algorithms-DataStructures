#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void push(int);
int pop(void);
int top=0;
char s[100];
int calculation_array[100];

int main(){
    int x,a,b,n=0;
    while(scanf("%s", s) != EOF){
        if ( s[0] == '+' ){
            a=pop();
            b=pop();
            n=a+b;
            push(n);
    } else if ( s[0] == '-' ){
        a=pop();
        b=pop();
        n=b-a;
        push(n);
    } else if ( s[0] == '*' ){
        a=pop();
        b=pop();
        n=a*b;
        push(n);
    } else {
        x=atoi(s);
        push(x);
    }
    }
    printf("%d\n",calculation_array[top]);

    return 0;
}

void push(x){
    top++;
    calculation_array[top]=x;
}
int pop(){
    top--;
    return calculation_array[top+1];
}