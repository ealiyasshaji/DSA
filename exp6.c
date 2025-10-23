#include <stdio.h>
int partition(int A[], int low, int high) {
int pivot = A[low];
int start = low;
int end = high;
while (start < end){
while (A[start] <= pivot)
start++;
while (A[end] > pivot)
end--;
if (start < end) {
int temp=A[start];
A[start]=A[end];
A[end]=temp;
}
}
A[low] = A[end];
A[end] = pivot;
return end;
}
void quicksort(int A[], int low, int high) {
if (high > low) {
int pivot = partition(A, low, high);
quicksort(A, low, pivot - 1);
quicksort(A, pivot + 1, high);
}
}
int main() {
int A[100], n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d elements:\n", n);
for (i = 0; i < n; i++) {
scanf("%d", &A[i]);
}
quicksort(A, 0, n - 1);
printf("Sorted array:\n");
for (i = 0; i < n; i++) {
printf("%d ", A[i]); 