#include <stdio.h>
void merge(int A[], int lb, int mid, int ub) {
int temp[100];
int i = lb;
int j = mid + 1;
int k = lb;
while (i <= mid && j <= ub) {
if (A[i] <= A[j]) {
temp[k] = A[i];
i = i + 1;
} else {
temp[k] = A[j];
j = j + 1;
}
k = k + 1;
}
while (i <= mid) {
temp[k] = A[i];
i = i + 1;
k = k + 1;
}
while (j <= ub) {
temp[k] = A[j];
j = j + 1;
k = k + 1;
}
for (int x = lb; x <= ub; x++) {
A[x] = temp[x];
}
}
void merge_sort(int A[], int lb, int ub) {
if (lb < ub) {
int mid = (lb + ub) / 2;
merge_sort(A, lb, mid);
merge_sort(A, mid + 1, ub);
merge(A, lb, mid, ub);
}
}
int main() {
int A[100], n;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &A[i]);
}
printf("Original Array: ");
for (int i = 0; i < n; i++)
printf("%d ", A[i]);
merge_sort(A, 0, n - 1);
printf("\nSorted Array: ");
for (int i = 0; i < n; i++)
printf("%d ", A[i]);
}