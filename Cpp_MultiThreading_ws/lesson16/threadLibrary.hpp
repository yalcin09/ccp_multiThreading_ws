#ifndef __THREAD_LIB_HPP__
#define __THREAD_LIB_HPP__

#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <string>

void showPerformanceOfOperation(clock_t t, std::string s);
int **initializeMatrices(int row, int column);
void fill(int **arr, int row, int column, int processNumber);
void display(int **arr, int row, int column);
void deleteMemory(int **arr, int row, int column);

#endif
