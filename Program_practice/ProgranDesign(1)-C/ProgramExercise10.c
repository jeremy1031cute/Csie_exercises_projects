#include<stdio.h>

int main(){
    //query--1
    int M;
    //printf("What is the size of the matrix: ");
    scanf("%d", &M);
    int array[M][M];
    int new_array[M][M];
    //printf("Please enter the matrix: ");
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            scanf(" %d", &array[i][j]);
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            new_array[i][j]=array[M-1-j][i];
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            printf("%d ", new_array[i][j]);
        }
    }
    printf("\n");

    //query--2
    int t, M2, flag=0;//flag:標計負數用
    int arr[3][3];
    //printf("Enter the number of input data: ");
    scanf("%d", &t);
    for(int k=0; k<t; k++){
        //printf("What is the size of the matrix: ");
        scanf("%d", &M2);
        M2=3;//此題目陣列size內定為3，較好對齊
        //printf("Please enter the matrix: ");
        for(int i=0; i<M2; i++){
            for(int j=0; j<M2; j++){
                scanf(" %d", &arr[i][j]);
                if(arr[i][j]<0)
                    flag=1;
            }
        }
        if(flag == 1)
            printf("The matrix is not symmetric!\n");
        else if(arr[0][0] != arr[2][2] || arr[0][1] != arr[2][1] || arr[0][2] != arr[2][0] || arr[1][0] != arr[1][2])
            printf("The matrix is not symmetric!\n");
        else
            printf("The matrix is symmetric!\n");
    }

    //query--3
    //printf("Enter the number of input data: ");
    scanf("%d", &t);
    for(int k=0; k<t; k++){
        //printf("What is the size of the matrix: ");
        scanf("%d", &M2);
        int f_arr[M2][M2];
        int s_arr[M2][M2];
        int fin[M2][M2];
        //printf("the first matrix: ");
        for(int i=0; i<M2; i++){
            for(int j=0; j<M2; j++){
                scanf(" %d", &f_arr[i][j]);
            }
        }
        //printf("the second matrix: ");
        for(int i=0; i<M2; i++){
            for(int j=0; j<M2; j++){
                scanf(" %d", &s_arr[i][j]);
            }
        }

        for (int i=0; i<M2; i++){
            for (int j=0; j<M2; j++){
                fin[i][j] = 0;
                for (int e = 0; e<M2; e++){
                    fin[i][j] += f_arr[i][e] * s_arr[e][j];//(注意!!)若無使用第三個變數(e)，便只有行與列最前面的結果互乘
                }
            }
        }
        for (int i=0; i<M2; i++){
            for (int j=0; j<M2; j++){
                printf("%d ", fin[i][j]);
            }
        }
    }
    return 0;
}
