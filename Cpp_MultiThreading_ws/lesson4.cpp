///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example1
/*
#include <iostream>
#include <thread>

using namespace std;

void myThread(){
    cout << "My Thread" << endl;
}

int main(){

    // Thread tanımlama ve başlatma
    thread t(&myThread);

    cout << "Main Fonksiyonu" << endl;

    t.join();     // Thread'din tamamlanmasını bekle. Main fonksiyonunun işlemi biterse thread sonlandırılır.
    //t.detact()  // Main fonksiyonundan bağımsız olarak thread sonlandılır.
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example2
/*
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void myThread(){
    for(;;){
        cout << "My Thread" << endl;
        // 1 sn bekleme
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main(){

    // Thread tanımlama ve başlatma
    thread t(&myThread);

    for(;;){
        cout << "Main Fonksiyonu" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t.join();
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example3
/*
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void myThread(){
    for(;;){
        cout << "My Thread" << endl;
        // 1 sn bekleme
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main(){

    // Thread tanımlama ve başlatma
    thread t(&myThread);
    t.join();

    // Burada hiç bir zaman alttaki for döngüsüne girilmez.
    // Eğer main içerisinde bir işlem yapmak istiyorsak, bu işlemi thread oluşturma fonksiyonu ile
    // join() fonksiyonu arasında yapmalıyız.

    for(;;){
        cout << "Main Fonksiyonu" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example4
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void myThread1(){
    for(;;){
        cout << "Thread1" << endl;
        // 1 sn bekleme
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void myThread2(){
    for(;;){
        cout << "Thread2" << endl;
        // 1 sn bekleme
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main(){

    // Thread tanımlama ve başlatma
    thread t1(&myThread1);
    thread t2(&myThread2);
    
    for(;;){
        cout << "Main Fonksiyonu" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t1.join();
    t2.join();

    return 0;
}