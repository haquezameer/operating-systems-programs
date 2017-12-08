#include<stdio.h>

enum {thinking,hungry,eating} state[5];
int self[5];

int signal()
{
    return eating;
}

int wait(){
    return hungry;
}

void init(n){
    int i;
    for(i=0;i<n;i++)
        state[i]=thinking;
}

void test(int i,int n){
    if(state[(i+n-1)%n]!=eating && state[i]==hungry && state[(i+1)%n]!=eating){
        state[i]=eating;
        self[i]=signal();
    }
}

void pickup(int i,int n){
    state[i]=hungry;
    test(i,n);
    if(state[i]!=eating){
        self[i]=wait();
        printf("Philosopher %d went to waiting i.e hungry\n",i+1);
    }
    else
        printf("Philosopher %d is eating\n",i+1);
}

void putdown(int i,int n){
    state[i]=thinking;
    printf("Philosopher %d went to thinking state\n",i+1);
    test((i+n-1)%n,n);
    test((i+1)%n,n);
}

void showstate(n){
    int i;
    for(i=0;i<n;i++){
        if(state[i]==eating)
            printf("Philosopher %d is eating\n",i+1);
        else if(state[i]==hungry)
            printf("Philosopher %d is hungry\n",i+1);
        else
            printf("Philosopher %d is thinking\n",i+1);
    }
}

int main()
{
    int n,i,ch;
    printf("Enter no. of philosophers\n");
    scanf("%d",&n);
    init(n);
    while(1){
        printf("Enter choice 1.Pickup\t 2.Putdown\t 3.Showstate\t 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the philosopher no.\n");
                scanf("%d",&i);
                pickup(i-1,n);
                break;
            case 2:
                printf("Enter the philosopher no.\n");
                scanf("%d",&i);
                putdown(i-1,n);
                break;
            case 3:
                showstate(n);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}