#include <stdio.h>
int binarySearch (int arr[], int n, int target){
 int left=0, right=n-1, mid;
 while (left <= right){
 mid (left + right) / 2;
 if (arr[mid] == target){
 return mid;
 }
 else if (arr[mid] < target){
 left = mid + 1;
 }
 else{
 right = mid-1;
 }
 }
 return -1;
}
int main (){
 int i, n, target, result;
 printf ("Enter number of elements: ");
 scanf ("%d", &n);
 int arr[n];
 printf ("Enter %d elements in sorted order: \n", n);
 for (i=0;i<n; i++){
 scanf ("%d",&arr[i]);
 }
 printf ("Enter target value:\n");
 scanf ("%d", &target);
 result = binarySearch(arr, n, target);
 if (result != -1){
 printf ("Element %d found at index %d.\n", target, result);
}
else{
 printf ("Element %d not found in the array.\n", target);
}
}