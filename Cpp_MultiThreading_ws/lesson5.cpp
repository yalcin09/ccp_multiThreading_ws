///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example1
/*
#include <iostream>
#include <thread>

using namespace std;

void hesapla1(int i, int bitisDegeri){
    int sum = 0;
    for(int j=i; j<bitisDegeri;j++){
        sum =+ j;
    }
    cout << "hesapla1 : " << sum << endl;
}

void hesapla2(int i, int bitisDegeri){
    int sum = 0;
    for(int j=i; j<bitisDegeri;j++){
        sum =+ j;
    }
    cout << "hesapla2 : " << sum << endl;
}

int main(){

    thread t1(&hesapla1, 1, 10);
    thread t2(&hesapla2, 10, 100);


    t1.join();
    t2.join();

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example2

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void fncSecond(){
    for(;;){
        cout << "fncSecond\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void fncFirst(){
    thread t2(&fncSecond);

    for(;;){
        cout << "fncFirst\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    
    t2.join();
}

int main(){

    thread t1(&fncFirst);


    t1.join();

    return 0;
}