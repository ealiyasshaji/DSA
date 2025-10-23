#include <stdio.h>
#include <string.h>
int prec(char c) {
if(c=='^')
return 3;
else if(c=='/'||c=='*')
return 2;
else if(c=='+'||c=='-')
return 1;
else
return -1;
}
char associativity(char c) {
if(c=='^')
return 'r';
return 'l';
}
void infixToPostfix(char s[]) {
char result[100];
int k=0;
int len=strlen(s);
char stack[100];
int j=-1;
for(int i=0; i<len; i++) {
char c=s[i];
if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'& c<='9')) {
result[k] = c;
k++;
}
else if(c=='(') {
j++;
stack[j] = c;
}
else if(c==')') {
while(j>= 0&&stack[j]!='(') {
result[k]=stack[j];
k++;
j--;
}
j--;
}
else {
while(j>=0&&(prec(s[i])<prec(stack[j])||prec(s[i])==prec(stack[j])
&&associativity(s[i])=='l')) {
result[k] = stack[j];
k++;
j--;
}
j++;
stack[j] = c;
}
}
while(j>=0) {
result[k] = stack[j];
k++;
j--;
}
result[k]='\0';
printf("%s\n",result);
}
void main() {
char exp[100];
printf("Enter infix expression: ");
scanf("%s",exp);
printf("Postfix expression is: ");
infixToPostfix(exp);
}