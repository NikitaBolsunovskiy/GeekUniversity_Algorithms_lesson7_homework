#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void solution1();

int main() {

    solution1();

    return 0;
}


void printMatrix(int N, int*a){
    int i;
    for (i=0; i<N*N; i++) {
        printf("%d   ", a[i]);
        if ((i+1)%N==0) printf("\n");
    }
    printf("\n");
}

void solution1(){

    FILE * file = fopen("D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\07\\homework7\\matrix.txt", "r");
    if(file==NULL){
        printf("Не удалось прочитать файл с матрицей смежности.\n");
        exit(1);
    }
    int count;
    fscanf(file,"%d",&count);

    int matrix[count][count];

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            fscanf(file,"%d",&matrix[i][j]);
        }
    }

    printf("Считана матрица: \n");
    printMatrix(count,matrix);

}