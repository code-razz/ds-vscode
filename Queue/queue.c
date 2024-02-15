//NOTE: In both enque and dequeue we do rear++ and front++. Notice that no -- is done;


#include<stdio.h>
#define max 5
int queue[max];
int rear=-1;
int front =-1;

void enqueue(int data){
    //insert at rear
    if(rear>=max-1){
        printf("\nThe queue is full");
        return;
    }
    if(rear==-1 && front==-1){
        rear=front=0;
        queue[rear]=data;
        return;
    }
    rear++;
    queue[rear]=data;

}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nThe queue is already empty");
        return;
    }
    /*
    Mam's method:
    if(front==rear){
        front=rear=-1;   //When the last element is deleted
    }else{
        front++;
    }
    */
    front++;
    if(front>rear){
        front=rear=-1;
    }
}

void display(){
    if(rear==-1 && front==-1){
        printf("\nThe queue is empty");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d<-",queue[i]);
    }
    /*  This is also correct
    int temp=front;
    while(temp<=rear){
        printf("%d<-",queue[temp]);
        temp++;
    }
    */
}

int main(){
    int data;
    int ch;
    while(1){
        printf("\n\nMENU:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d",&data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
    
}