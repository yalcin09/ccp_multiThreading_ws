#include "threadLibrary.hpp"

void showPerformanceOfOperation(clock_t t, std::string s){

    std::cout << s << " result : " <<std::setprecision(12) << float(t) / CLOCKS_PER_SEC << std::endl;
}

int **initializeMatrices(int row, int column){

    int **arr = new int *[row];

    for(int i = 0; i < row; i++){
        arr[i] = new int[column];
    }

    return arr;

}

void fill(int **arr, int row, int column, int processNumber){

    for(int i = 0; i < row; i++){
        for(int k = 0; k < column; k++){
            int sum = 0;
            for(int c = 0; c < processNumber; c++){
                sum += i*k;
            }
            arr[i][k] = sum;
        }
    }

}

void display(int **arr, int row, int column){

    for(int i = 0; i < row; i++){
        for(int k = 0; k < column; k++){
            std::cout << arr[i][k] << "\t";
        }
        std::cout << std::endl;
    }
}

void deleteMemory(int **arr, int row, int column){
    
    for(int i = 0; i < row; i++){
        delete[] arr[i];
    }

    delete[] arr;
}