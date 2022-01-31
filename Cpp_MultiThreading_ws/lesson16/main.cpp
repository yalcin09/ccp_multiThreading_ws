#include "threadLibrary.hpp"

#define MULTI 1
#define ROW 1920
#define COLUMN 1080
#define PROCESS_NUMBER 1000

int main(){

    int **ArrayMatrices;
    int **BrrayMatrices;
    int **CrrayMatrices;
    int **DrrayMatrices;
    int **ErrayMatrices;
    int **FrrayMatrices;
    int **GrrayMatrices;
    int **HrrayMatrices;
    int **IrrayMatrices;

    ArrayMatrices = initializeMatrices(ROW, COLUMN);
    BrrayMatrices = initializeMatrices(ROW, COLUMN);
    CrrayMatrices = initializeMatrices(ROW, COLUMN);
    DrrayMatrices = initializeMatrices(ROW, COLUMN);
    ErrayMatrices = initializeMatrices(ROW, COLUMN);
    FrrayMatrices = initializeMatrices(ROW, COLUMN);
    GrrayMatrices = initializeMatrices(ROW, COLUMN);
    HrrayMatrices = initializeMatrices(ROW, COLUMN);
    IrrayMatrices = initializeMatrices(ROW, COLUMN);

    #if MULTI == 1

        clock_t t = clock();

        fill(ArrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(BrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(CrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(DrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(ErrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(FrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(GrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(HrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        fill(IrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);

        t = clock() - t;

        showPerformanceOfOperation(t, "Normal Mod");

        deleteMemory(ArrayMatrices, ROW, COLUMN);
        deleteMemory(BrrayMatrices, ROW, COLUMN);
        deleteMemory(CrrayMatrices, ROW, COLUMN);
        deleteMemory(DrrayMatrices, ROW, COLUMN);
        deleteMemory(ErrayMatrices, ROW, COLUMN);
        deleteMemory(FrrayMatrices, ROW, COLUMN);
        deleteMemory(GrrayMatrices, ROW, COLUMN);
        deleteMemory(HrrayMatrices, ROW, COLUMN);
        deleteMemory(IrrayMatrices, ROW, COLUMN);

    #else

        clock_t t = clock();

        std::thread first(fill, ArrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread second(fill, BrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread third(fill, CrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread fourth(fill, DrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread fifth(fill, ErrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread sixth(fill, FrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread seventh(fill, GrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread eighth(fill, HrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
        std::thread nineth(fill, IrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);

        first.join();
        second.join();
        third.join();
        fourth.join();
        fifth.join();
        sixth.join();
        seventh.join();
        eighth.join();
        nineth.join();

        t = clock() - t;

        showPerformanceOfOperation(t, "Thread Mod");

        deleteMemory(ArrayMatrices, ROW, COLUMN);
        deleteMemory(BrrayMatrices, ROW, COLUMN);
        deleteMemory(CrrayMatrices, ROW, COLUMN);
        deleteMemory(DrrayMatrices, ROW, COLUMN);
        deleteMemory(ErrayMatrices, ROW, COLUMN);
        deleteMemory(FrrayMatrices, ROW, COLUMN);
        deleteMemory(GrrayMatrices, ROW, COLUMN);
        deleteMemory(HrrayMatrices, ROW, COLUMN);
        deleteMemory(IrrayMatrices, ROW, COLUMN);

    #endif

    return 0;
}