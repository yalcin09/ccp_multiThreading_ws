// Example 1
/*
#include <iostream>
#include <thread>

using namespace std;

void inCrementFunction(){
    for(;;)
        cout << "Increment" << endl;

}

class A{


    public:

    A(){
        cout << "Default constructors" << endl;
    }

    A(const A &p){
        cout << "Copy constructors" << endl;
    }

    ~A(){
        cout << "destructor" << endl;
    }

    void operator()(){
        cout << "A calls" << endl;
    }
};

int main(){

    
    //A a;         // Default constructor
    //A a1 = a;    // Copy constructor
    //a();
    //a1();
    

   thread t1(&inCrementFunction);
   //thread t2 = t1;                  // Bu şekilde atama yapılamaz. Çünkü copy constructor mantığı burada geçerli değildir.
   thread t2 = move(t1);              // Thread atama işlemlerinde move() fonksiyonu kullanılır.

    t2.join();
    t1.detach();

    return 0;
}
*/

// Example 2
#include <iostream>
#include <thread>

using namespace std;

void myFunc(){
    //cout << "MyFunc" << endl;
}

int main(){

    thread t1(&myFunc);
    thread t2(&myFunc);

    // Main thread id bilgisini alma
    cout << "Main thread ID : " << this_thread::get_id() << endl;

    // thread id bilgisini alma (name_thread.get_id())
    cout << "Our thread ID : " << t1.get_id() << endl;
    cout << "Our thread ID : " << t2.get_id() << endl;

    t1.join();
    t2.join();

    return 0;
}