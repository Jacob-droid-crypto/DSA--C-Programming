#include <stdio.h>

int main() {
    int n, key, flag = 0, count = 2;
    
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    count++;

    int sortedarr[n];
    printf("Enter the numbers in sorted way\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &sortedarr[i]);
        count++;
    }
    printf("Enter the number to be searched\n");
    scanf("%d", &key);
    count++;
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        count++;
        if (sortedarr[m] == key) {
            count++;
            printf("Element found in index %d\n", m);
            flag = 1;
            break;
        }
        else if (sortedarr[m] > key) {
            e = m - 1;
            count++;
        }
        else {
            s = m + 1;
            count++;
        }
    }
    if (flag == 0) {
        printf("Number not found\n");
    }
    int space = 8 + 4 + n * 4;  
    printf("Space complexity = %d bytes\n", space);
    printf("Time complexity = %d units\n", count);
    return 0;
}
