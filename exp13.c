#include <stdio.h>
#define size 7
int queue[size];
int front=-1;
int rear=-1;
void enqueue(int x){
 if((rear+1)%size==front){
 printf("Overflow");
 }
 else if(front==-1 && rear==-1){
 front=0,rear=0;
 queue[rear]=x;
 }
 else{
 rear=(rear+1)%size;
 queue[rear]=x;
 }
}
void dequeue(){
 if(front==-1){
 printf("underflow");
 }
 else if(front==rear){
 printf("Deleted elements:%d\n",queue[front]);
 front=-1,rear=-1;
 }
 else{
 printf("Deleted elements:%d\n",queue[front]);
 front=(front+1)%size;
 }
}
void display(){
 if (front==-1){
 printf("Queue is empty\n");
 }
 else{
 int i=front;
 printf("Queue elements:");
 while(1){
printf("%d",queue[i]);
 if(i==rear)
 break;
 i=(i+1)%size;
 }
 printf("\n");
}
}
int main(){
 int choice ,x;
 char y;
 do{
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
 printf("\nEnter the choice (1-4): ");
 scanf("%d", &choice);
 switch (choice){
 case 1:
 printf("Enter the element:");
 scanf("%d",&x);
 enqueue(x);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 break;
 default:
 printf("invalid choice \n");
 }
 }
while(y=='Y'||y =='y');
return 0;
}