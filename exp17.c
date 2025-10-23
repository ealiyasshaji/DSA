#include<stdio.h>
#include<stdlib.h>
struct Node{
int coeff;
int exp;
struct Node *next;
};
struct Node *createNode(int coeff,int exp){
struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
newNode->coeff=coeff;
newNode->exp=exp;
newNode->next=NULL;
return newNode;
}
struct Node *insertNode(struct Node *head,int coeff,int exp){
struct Node *newNode = createNode(coeff,exp);
if(head ==NULL){
head =newNode;
}
else {
struct Node *temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newNode;
}
return head;
}
void display(struct Node *head){
struct Node *temp=head;
if(temp==NULL){
printf("0\n");
return;
}
while(temp!=NULL){
printf("%dx^%d",temp->coeff,temp->exp);
if(temp->next!=NULL)
printf("+");
temp=temp->next;
}
printf("\n");
}
struct Node *addPolynomials(struct Node *P1,struct Node *P2){
struct Node *result=NULL;
while(P1!=NULL&&P2!=NULL){
if(P1->exp>P2->exp){
result = insertNode(result,P1->coeff,P1->exp);
P1=P1->next;
}
else if(P2->exp>P1->exp){
result =insertNode(result,P2->coeff,P2->exp);
P2=P2->next;
}
else{
int sum= P1->coeff+P2->coeff;
if(sum!=0)
result =insertNode(result,sum,P1->exp);
P1=P1->next;
P2=P2->next;
}}
while(P1!=NULL){
result=insertNode(result,P1->coeff,P1->exp);
P1=P1->next;
}
while(P2!=NULL){
result=insertNode(result,P2->coeff,P2->exp);
P2=P2->next;
}
return result;
}
void main()
{
struct Node *P1=NULL,*P2=NULL,*sum=NULL;
int n,m,coeff,exp,i;
printf("Enter number of terms in first polynomial");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter coefficient and exponent for the term %d",i+1);
scanf("%d%d",&coeff,&exp);
P1=insertNode(P1,coeff,exp);
}
printf("\nenter number of terms in second polynomial");
scanf("%d",&m);
for(i=0;i<m;i++){
printf("Enter coefficient and exponent for the term %d",i+1);
scanf("%d%d",&coeff,&exp);
P2=insertNode(P2,coeff,exp);
}
printf("\nFirst polynomial");
display(P1);
printf("\nsecond polynomial");
display(P2);
sum=addPolynomials(P1,P2);
printf("sum of two polynomials");
display(sum);
}