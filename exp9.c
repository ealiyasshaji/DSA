#include <stdio.h>

struct poly {
    float coeff;
    int exp;
};
int ReadPoly(struct poly p[]) {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &p[i].coeff, &p[i].exp);
    }
    return n;
}
int AddPoly(struct poly p1[], int n1, struct poly p2[], int n2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++; j++; k++;
        } else if (p1[i].exp > p2[j].exp) {
            p3[k++] = p1[i++];
        } else {
            p3[k++] = p2[j++];
        }
    }
    while (i < n1) p3[k++] = p1[i++];
    while (j < n2) p3[k++] = p2[j++];

    return k;
}
void DisplayPoly(struct poly p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%0.2f(x^%d)", p[i].coeff, p[i].exp);
        if (i < n - 1) printf(" + ");
    }
    printf("\n");
}
int main() {
    struct poly p1[10], p2[10], p3[20];
    int n1 = ReadPoly(p1);
    int n2 = ReadPoly(p2);

    int n3 = AddPoly(p1, n1, p2, n2, p3);

    printf("\nSum of the polynomials: ");
    DisplayPoly(p3, n3);

    return 0;
}
