/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// Functor


#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void myThreadFunc1(){
    for(;;){
        cout << "MyThreadFunc1 is calling\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void myThreadFunc2(){
    for(;;){
        cout << "MyThreadFunc2 is calling\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

class myFuncObject{
    public:
    void operator()(){
        thread t1(myThreadFunc1);
        thread t2(myThreadFunc2);

        int count = 0;

        for(;;){
            count ++;
            mySumation(count);
            cout << "MyFuncObject is calling\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        t1.join();
        t2.join();
    }

    void mySumation(int value){
        int sum=0;
        for(int i=0;i<value;i++){
            sum += i;
        }
        cout << "Sum is : " << sum << endl;
    }

};


int main(){

    myFuncObject mfunc;
    //mfunc();           // -->> mfunc.operator()();

    thread t(mfunc);

    for(;;){
        cout << "my main thread\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t.join(); 

    return 0;
}

