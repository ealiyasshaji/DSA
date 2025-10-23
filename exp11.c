#include<stdio.h>
int create(int r,int c,int t[10][3]) {
int m[r][c],i,j,k=0;
for(i=0; i<r; i++) {
for(j=0; j<c; j++) {
scanf("%d",&m[i][j]);
}
}
t[0][0]=r;
t[0][1]=c;
for(i=0; i<r; i++) {
for(j=0; j<c; j++) {
if(m[i][j]!=0) {
k++;
t[k][0]=i;
t[k][1]=j;
t[k][2]=m[i][j];
}
}
}
t[0][2]=k;
return k;
}
void display(int k,int t[10][3]) {
for(int i=0; i<=k; i++) {
printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
}
}
int addmatrix(int r,int c,int k1,int k2,int t1[10][3],int t2[10][3],int t3[10][3]) {
int i=1,j=1,k=0;
t3[0][0]=r;
t3[0][1]=c;
while(i<=k1 && j<=k2) {
if(t1[i][0]==t2[j][0]) {
if(t1[i][1]==t2[j][1]) {
k++;
t3[k][0]=t1[i][0];
t3[k][1]=t1[i][1];
t3[k][2]=t1[i][2]+t2[j][2];
i++,j++;
}
else if(t1[i][1]<t2[j][1]) {
k++;
t3[k][0]=t1[i][0];
t3[k][1]=t1[i][1];
t3[k][2]=t1[i][2];
i++;
}
else {
k++;
t3[k][0]=t2[j][0];
t3[k][1]=t2[j][1];
t3[k][2]=t2[j][2];
j++;
}
}
else if(t1[i][0]<t2[j][0]) {
k++;
t3[k][0]=t1[i][0];
t3[k][1]=t1[i][1];
t3[k][2]=t1[i][2];
i++;
}
else {
k++;
t3[k][0]=t2[j][0];
t3[k][1]=t2[j][1];
t3[k][2]=t2[j][2];
j++;
}
}
while(i<=k1) {
k++;
t3[k][0]=t1[i][0];
t3[k][1]=t1[i][1];
t3[k][2]=t1[i][2];
i++;
}
while(j<=k2) {
k++;
t3[k][0]=t2[j][0];
t3[k][1]=t2[j][1];
t3[k][2]=t2[j][2];
j++;
}
t3[0][2]=k;
return k;
}
void main() {
int r1,c1,r2,c2,k1,k2,k,t1[10][10],t2[10][10],t3[10][10];
printf("Enter the no of row and colume of matrix 1: ");
scanf("%d%d",&r1,&c1);
printf("Enter the row and colume of matrix 2: ");
scanf("%d%d",&r2,&c2);
if(r1!=r2 || c1!=c2) {
printf("Addition is not possible ");
}
else {
printf("Enter the matrix 1: \n");
k1=create(r1,c1,t1);
printf("Display Matrix 1:\n");
display(k1,t1);
printf("Enter the matrix 2: \n");
k2=create(r2,c2,t2);
printf("Display Matrix 2:\n");
display(k2,t2);
k = addmatrix(r1,c2,k1,k2,t1,t2,t3);
printf("Resultant Matrix:\n");
display(k,t3);
}
}