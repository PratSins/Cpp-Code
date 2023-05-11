#include <stdio.h>


void reverse(char *p, int n, int x, int z) {
    if(n == x) {

    } else {
        char c = *p;
        *p = *(p+n-1-z);
        *(p+n-1-z) = c;
        p++;
        n--;
        z++;
        reverse(p, n, x, z);
    }
}
int main() {
    int n;
    printf("Enter the number of characters of string: ");
    scanf("%d", &n);
    int x = n/2;
    char ch[n];
    printf("Enter a string of %d character: ", n);
    scanf("%s", ch);
    int *p = ch;
    reverse(p, n, x, 0);
    printf("The reversed string is: ");
    printf("%s\n", ch);
}