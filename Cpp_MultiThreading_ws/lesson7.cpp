/*********************************************************
 * 
 * Referans Kavramı
 * 
 * *******************************************************/
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Example 1
/*
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void myThreadFunction(string s){
    cout << "myThreadFunction" << endl;
    cout << "Gelen veri : " << s << endl;
    s = "Değiştirildim";
}

int main(){

    string s = "Merhaba Dünyalı";
    
    thread t(&myThreadFunction, s);

    cout << "Main thread : " << s << endl;

    t.join();

    cout << "Main thread end: " << s << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Example 2
/*
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void myThreadFunction(string &s){
    cout << "myThreadFunction" << endl;
    cout << "Incoming data : " << s << endl;
    s = "Değiştirildim";
}

int main(){

    string s = "Merhaba Dünyalı";
    
    // thread oluşturma, çalıştırma ve referans değeri gönderme
    thread t(&myThreadFunction, std::ref(s));

    cout << "Main thread : " << s << endl;

    t.join();

    cout << "Main thread end: " << s << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Example 3
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void inCrementFunction(int i){
    for(int j=i; j<100; i++){
        cout << "J : " << j << endl;
    }
}

int main(){

    thread t(&inCrementFunction, 10);

    cout << "Main Thread" << endl;
    t.join();

    return 0;
}