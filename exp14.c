#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE-1];
int rear=-1;
int front=-1;
void enqueuefront(int val){
if((front==0&&rear==MAX_SIZE-1)||front==rear+1)
printf("Queue Overflow\n");
else {
if(front==-1&&rear==-1){
front=rear=0;
queue[front]=val;}
else if(front ==0){
front=MAX_SIZE-1;
queue[front]=val;}
else
front --;
queue[front]=val;}}
void enqueuerear(int val){
if((front==0&&rear==MAX_SIZE-1)||front==rear+1)
printf("Queue Overflow\n");
else {
if(front==-1&&rear==-1){
front=rear=0;
queue[rear]=val;}
else if(rear==MAX_SIZE-1){
rear=0;
queue[rear]=val;}
else
rear++;
queue[rear]=val;}}
void dequeuefront(){
if(front==-1&&rear==-1)
printf("Queue Underflow\n");
else if(front==rear){
int val=queue[front];
rear=front=-1;
printf("Value %d has been dequeued\n",val);}
else if(front==MAX_SIZE-1){
int val=queue[front];
front=0;
printf("Value %d has been dequeued\n",val);}
else{
int val=queue[front];
front++;
printf("Value %d has been dequeued\n",val);
}}
void dequeuerear(){
if(front==-1&&rear==-1)
printf("Queue Underflow\n");
else if(front==rear){
int val=queue[rear];
rear=front=-1;
printf("Value %d has been dequeued\n",val);}
else if(rear==0){
int val=queue[rear];
rear=MAX_SIZE-1;
printf("Value %d has been dequeued\n",val);}
else{
int val=queue[rear];
rear--;
printf("Value %d has been dequeued\n",val);
}}
void display() {
int i;
if (front == -1) {
printf("Queue is Empty\n");
}
else{
for(i=front;i!=rear;(i=(i+1)%MAX_SIZE)){
printf("%d\t",queue[i]);}
printf("%d\t",queue[i]);}}
int main(){
int choice,value;
while (1) {
printf("\nQueue Operations:\n");
printf("1-->ENQUEUE F;2-->ENQUEUE R;3-->DEQUEUE F;4-->DEQUEUE R;5-->DISPLAY;6--
>EXIT\n");
printf("Enter choice:");
scanf("%d",&choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueuefront(value);
break;
case 2:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueuerear(value);
break;
case 3:
dequeuefront();
break;
case 4:
dequeuerear();
break;
case 5:
display();
break;
case 6:
printf("Exiting...\n");
return 0;
break;
default:
printf("Invalid choice!\n");
break;
}
}return 0;}