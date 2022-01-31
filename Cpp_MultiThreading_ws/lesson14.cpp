/**********************************************************
 **********************************************************
 *
 * Thread With Shared Memory And Mutex
 *
 * 
 **********************************************************
 **********************************************************/

// Example 1
/*
#include <iostream>
#include <thread>

using namespace std;

void callFunction(){
    cout << "callFunction" << endl;
}

int main(){

    thread t(&callFunction);

    cout << "Main Thread\n";

    t.join();

    return 0;
}
*/

// Example 2
/*
#include <iostream>
#include <thread>

using namespace std;

void callFunction(){
    for(int i=-10; i<0; i++){
        cout << "callFunction : " << i << endl;
    }
}

int main(){

    thread t(&callFunction);

    for(int i=0; i<10; i++){
        cout << "Main Thread : " << i << endl;
    }

    t.join();

    return 0;
}
*/

// Example 3
/*
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;

void callFunction(){
    mu.lock();
    for(int i=0; i<1000; i++){
        //mu.lock();
        cout << "Call Function : " << i << "\n";
        //mu.unlock();
    }
    mu.unlock();
}

int main(){

    thread t(&callFunction);

    mu.lock();
    for(int i=-1000; i<0; i++){
        //mu.lock();
        cout << "Main Function : " << i << "\n";
        //mu.unlock();
    }
    mu.unlock();

    t.join();

    return 0;
}
*/

// Example 4

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mu;

void callFunction(){
    //mu.lock();
    for(int i=0; i<100; i++){
        mu.lock();
        cout << "Call Function : " << i << "\n";
        mu.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    //mu.unlock();
}

int main(){

    thread t(&callFunction);

    //mu.lock();
    for(int i=-100; i<0; i++){
        mu.lock();
        cout << "Main Function : " << i << "\n";
        mu.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    //mu.unlock();

    t.join();

    return 0;
}
