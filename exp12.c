#include <stdio.h>
#define size 5
int main() {
int item, op, front = -1, rear = -1;
int q[5];
while (1) {
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
printf("\nEnter the choice (1-4): ");
scanf("%d", &op);
switch (op) {
 case 1:
 if (rear == size - 1) {
 printf("Overflow\n");
 } else {
 printf("Enter the element: ");
 scanf("%d", &item);
 if (front == -1&& rear==-1) {
 front = 0;
 rear=0;
 q[rear]=item;
 }
 else{
 rear++;
 q[rear] = item;
 printf("%d inserted into the queue.\n", item);
 }
 }
 break;
 case 2:
 if (front == -1) {
 printf("Underflow\n");
 } else {
 item = q[front];
 printf("%d deleted from the queue.\n", item);
 if (front == rear) {
 front = rear = -1;
 }
 else{
 front++;
 }
}
 break;
 case 3:
 if (front == -1) {
 printf("Queue is empty.\n");
 } else {
 printf("Queue elements: ");
 for (int i = front; i <= rear; i++) {
 printf("%d ", q[i]);
 }
 printf("\n");
 }
 break;
 case 4:
 return 0;
 default:
 printf("Invalid choice!\n");
 }
 }
}