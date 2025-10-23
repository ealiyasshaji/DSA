#include <stdio.h>
int getmax(int a[], int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
void CountSort(int a[], int n, int pos) {
    int op[n];
    int count[10] = {0};
      for(int i = 0; i < n; i++) {
        count[(a[i] / pos) % 10]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        int d = (a[i] / pos) % 10;
        op[--count[d]] = a[i];
    }
    for(int i = 0; i < n; i++) {
        a[i] = op[i];
    }
}
void RadixSort(int a[], int n) {
    int max = getmax(a, n);
    for(int pos = 1; max / pos > 0; pos *= 10) {
        CountSort(a, n, pos);
    }
}
void PrintArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void ReadArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}
int main() {
    int a[50], n;
    printf("Enter the number of elements (max 50): ");
    scanf("%d", &n);
    if(n <= 0 || n > 50) {
        printf("Invalid array size. Please enter a number between 1 and 50.\n");
        return 1;
    }
    printf("Enter the array elements: ");
    ReadArray(a, n);
    printf("Original array: ");
    PrintArray(a, n);
    RadixSort(a, n);
    printf("Sorted array: ");
    PrintArray(a, n);
    return 0;
}

