#include<stdio.h>
int main(){
    int r,c,i,j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[10][10],b[10][10],;
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d ", &a[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d ", &b[i][j]);
        }
    }
    int sparse1[3][10], n1=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]!=0){
                sparse1[0][n1]=i;
                sparse1[1][n1]=j;
                sparse1[2][n1]=a[i][j];
                n1++;
            }
        }
    
    int sparse2[3][10], n2=0;
    for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(b[i][j]!=0){
                    sparse2[0][n2]=i;
                    sparse2[1][n2]=j;
                    sparse2[2][n2]=b[i][j];
                    n2++;
                }
            }
        }
        int res[3][200];
    int i1 = 0, i2 = 0, k = 0;

    while(i1 < n1 && i2 < n2) {
        int r1 = sparse1[0][i1], c1 = sparse1[1][i1];
        int r2 = sparse2[0][i2], c2 = sparse2[1][i2];
        if (r1 < r2 || (r1 == r2 && c1 < c2)) {
            res[0][k] = r1;
            res[1][k] = c1;
            res[2][k] = sparse1[2][i1];
            i1++; k++;
        } else if (r2 < r1 || (r1 == r2 && c2 < c1)) {
            res[0][k] = r2;
            res[1][k] = c2;
            res[2][k] = sparse2[2][i2];
            i2++; k++;
        } else {
            int sum = sparse1[2][i1] + sparse2[2][i2];
            if(sum != 0) {
                res[0][k] = r1;
                res[1][k] = c1;
                res[2][k] = sum;
                k++;
            }
            i1++; i2++;
        }
    }
    while(i1 < n1) {
        res[0][k] = sparse1[0][i1];
        res[1][k] = sparse1[1][i1];
        res[2][k] = sparse1[2][i1];
        i1++; k++;
    }
    while(i2 < n2) {
        res[0][k] = sparse2[0][i2];
        res[1][k] = sparse2[1][i2];
        res[2][k] = sparse2[2][i2];
        i2++; k++;
    }
    printf("\nSum of Sparse Matrices (row column value):\n");
    for(i = 0; i < k; i++)
        printf("%d %d %d\n", res[0][i], res[1][i], res[2][i]);
    int trans[3][200];
    for(i = 0; i < k; i++) {
        trans[0][i] = res[1][i]; 
        trans[1][i] = res[0][i]; 
        trans[2][i] = res[2][i]; 
    }
    for(i = 0; i < k - 1; i++) {
        for(j = i + 1; j < k; j++) {
            if(trans[0][i] > trans[0][j] ||
               (trans[0][i] == trans[0][j] && trans[1][i] > trans[1][j])) {
                
                int temp;
                temp = trans[0][i]; trans[0][i] = trans[0][j]; trans[0][j] = temp;
                temp = trans[1][i]; trans[1][i] = trans[1][j]; trans[1][j] = temp;
                temp = trans[2][i]; trans[2][i] = trans[2][j]; trans[2][j] = temp;
            }
        }
    }

    printf("\nTranspose of Sum :\n");
    for(i = 0; i < k; i++)
        printf("%d %d %d\n", trans[0][i], trans[1][i], trans[2][i]);

    return 0;
}
    }


