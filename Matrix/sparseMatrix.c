#include <stdio.h>
#include <stdlib.h>

int nonZero;

void sparseMatrix(int arr[100][100],int rows,int columns){

    int crr[rows][nonZero],p=0,q=0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){

            if (arr[i][j]>0){
                crr[p][q]=i;
                crr[p+1][q]=j;
                crr[p+2][q]=arr[i][j];
                q++;

            }
            }
        }

    for(int f=0; f<rows;f++){
        for(int g=0;g<nonZero;g++){
            printf("%d   ", crr[f][g]);
        }
        printf("\n");
    }

}

int main()
{
    int rows,columns,arr[100][100],flag=0;
    printf("Enter rows of matrix: ");
    scanf("%d",&rows);
    printf("\nEnter columns of matrix: ");
    scanf("%d",&columns);
    printf("\nEnter elements of matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                flag++;
            }
        }
    }

    nonZero = (rows*columns)- flag;
    if (flag>=nonZero){
     printf("\nSparse Matrix:\n");
        sparseMatrix(arr,rows,columns);
    }else{
    printf("\nNot a sparse matrix");
    }







    return 0;
}
