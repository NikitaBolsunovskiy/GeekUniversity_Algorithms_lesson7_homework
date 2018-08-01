#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void solution1();
void solution2();
void solution3();

int main() {

    //solution1();
    solution2();
    solution3();

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

void initIntArray(int count, int a[]){
    for (int i = 0; i < count; ++i) {
        a[i] = 0;
    }
}

void initIntArrayCount(int count, int a[]){
    for (int i = 0; i < count; ++i) {
        a[i] = i;
    }
}

void printIntArray(int count, const int a[]){
    for (int i = 0; i < count; ++i) {
        printf("%d   ",a[i]);
    }
    printf("\n");
}

void graphInDepthRec(int count, int visited[count], int path[count], int matrix[count][count], int current);

void fillInPath(int count, int path[count], int current){
    for (int i = 0; i < count; ++i) {
        if(path[i]==0){
            path[i]=current+1;
            break;
        }
    }
}

void solution2(){

    // для навписания алгоритма нам надо
    // 1 - получить матрицу смежности.
    // 2.1 - получить/создать массив непройденных вершин...
    // 2.2 - создать массив пройденных вершин...
    // 2.3 - написать функцию поиска в массиве значения... (возвращающую 1,0)...
    // 3 - написать рекурсивную функцию, которая пробует пройти внутрь...


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

    printf("Считана матрица смежности: \n");
    printMatrix(count,matrix);

    int visited[count]; //массив посещенных, от 0 до (размер матрицы - 1).
    int path[count]; //массив пути

    initIntArray(count,visited);
    initIntArray(count,path);

    // начинаем с нулевой...
    for (int k = 0; k < count; ++k) {
        printf("Наинаем из точки:%d\n",k);
        graphInDepthRec(count,visited,path,matrix,2);
        printf("Помсещенные точки:\n");
        printIntArray(count, visited);
        printf("Путь:\n");
        printIntArray(count, path);
    }

}

void graphInDepthRec(int count, int visited[count], int path[count], int matrix[count][count], int current) {

    visited[current] = 1;
    fillInPath(count,path,current);
    for (int i = 0; i < count; ++i) {
        if(i!= current && matrix[current][i]!=0){
            graphInDepthRec(count,visited,path,matrix,i);
            break;
        }
    }
}

void solution3(){

}