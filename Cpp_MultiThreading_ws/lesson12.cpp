/***************************************
 ***************************************
 * Move Sematic
 *      - Temel olarak class ve struct içerisindeki bilgilerin biryerden alınıp,
 *      başka bir bölgeye taşınmasına imkan verir.
 * 
 *      - Geçici nesnelerle çalışırken gereksiz kopyalama işleminden kurtarır.
 * 
 ***************************************
 **************************************/

// Example 1
/*
#include <iostream>

using namespace std;

class A{
    private:

    public:

        int i;

        A(){
            cout << "default constructot" << endl;
        }

        A(const A &other){
            cout << "copy constructor"  << endl;
        }

        ~A(){
            cout << "destructor" << endl;
        }

        A &operator=(const A &other){
            this->i = other.i;
            cout << "copy assigment operator" << endl;
            return *this;
        }

        void writeInteger(){
            cout << "İnteger value : " << i << endl;
        }
};

int main(){

    A a;        // Default constructor
    A b = a;    // Copy constructor (farklı değişkenler oluşturuluyor)

    a.i = 5;

    b = a;

    a.writeInteger();
    b.writeInteger();

    return 0;
}
*/

// Example 2
/*
#include <iostream>

using namespace std;

class A{
    private:

    public:

        int i;
        string s;

        A(){
            cout << "default constructot" << endl;
        }

        A(string s){
            this->s = s;
        }

        A(const A &other){
            cout << "copy constructor"  << endl;
        }

        ~A(){
            cout << "destructor" << endl;
        }

        A &operator=(const A &other){
            this->i = other.i;
            cout << "copy assigment operator" << endl;
            return *this;
        }

        // move objects/methods
        A(A &&other){   // Sadece R value değerler alır.
            this->i = other.i;
            cout << "Move constructor" << endl;
        }

        A &operator=(A &&other){
            this->s = other.s;
            cout << "Move assigment operator" << endl;
            return *this;
        }

        void writeInteger(){
            cout << "İnteger value : " << i << endl;
        }

        void writeString(){
            cout << "String value : " << this->s << endl;
        }
};

int main(){

   // A a;        // Default constructor
   // A b = a;    // Copy constructor (farklı değişkenler oluşturuluyor)
    A a;

   //  a.i = 5;

   // A b = move(a); // Move constructor

   // b = move(a);   // Move assigment operator

   // a.writeInteger();
   // b.writeInteger();

    A c = a;    // Copy constructor
    c = a;      // Copy assigment operator

    c = move(a); // Move assigment operator

    A d("Mehmet");
    c = move(d);

    d.writeString();
    c.writeString();


    return 0;
}
*/


// Example 3
/*
#include <iostream>

using namespace std;

class A{

    private:

    public:
        int i;
        string s;

        A() : s("Default"), i(5) {
            cout << "Default constructor" << endl;
        }

        A(const A &other) : s(other.s), i(other.i){
            cout << "Copy constructer" << endl;
        }

        ~A(){
            cout << "Destructor" << endl;
        }

        ////////////////////////
        // move operator
        A(A &&other) : s(move(other.s)), i(move(other.i)){
            cout << "move constructor" << endl;
        }

        ////////////////////////
        //Additional code
        void printStringValue(){
            cout << "String Value : " << s << endl;
            cout << "Integer Value : " << i << endl;
        }

        void printIntegerValue(){
            cout << "Integer Value : " << i << endl;
        }

};

A internalFunction(A a){
    return a;
}

int main(){

    // A a;                      // Default constructor
    // a.printStringValue();
    // A b = a;                  // Copy constructor
    // b.printStringValue();


    A a1 = internalFunction(A());  // a1  : copy constructor ile dolduruluyor.
                                   // A() : default constructor
                                   // A() : yok edildi (destructor)
    a1.printStringValue();

    A a2 = move(a1);
    a1.printStringValue();         // a1 boş.
    a2.printStringValue();

    string s1 = "Mehmet";
    string s2 = move(s1);

    cout << "S1 : " << s1 << endl; // s1 boş.
    cout << "S2 : " << s2 << endl; 
    return 0;
}
*/

// Example 4
/*
#include <iostream>
#include <string>

using namespace std;

class A{

    private:
        
    public:

        string s;

        A() : s("Yalçın"){
            cout << "A default constructer" << endl;
        }
        
        A(const A &other) : s(other.s){
            cout << "A copy constructor" << endl;
        } 

        ~A(){
            cout << "A destructor" << endl;
        }

        ///////////////////////////////
        // Move
        A(A &&other) : s(move(other.s)){
            cout << "A move constructor" << endl;
        }
};

class B : public A{

    private:

    public:
        B(){
            cout << "B default constructor" << endl;
        }

        B(const B &other){
            cout << "B copy constructor" << endl;
        }

        ~B(){
            cout << "B destructor" << endl;
        }

        ///////////////////////////////
        // Move
        B(B &&other){
            cout << "B move constructor" << endl;
        }
};

int main(){

    //B x1;
    //B x2 = x1;

    B x1;
    B x2 = x1;
    B x3 = move(x2);
    
    cout << "X1 : " << x1.s << endl;
    cout << "X2 : " << x2.s << endl;
    cout << "X3 : " << x3.s << endl;
    return 0;
}
*/

// Example 5
#include <iostream>
#include <string>

using namespace std;

class A{

    private:
        
    public:

        string s;

        A() : s("Yalçın"){
            cout << "A default constructer" << endl;
        }
        
        A(const A &other) : s(other.s){
            cout << "A copy constructor" << endl;
        } 

        ~A(){
            cout << "A destructor" << endl;
        }

        ///////////////////////////////
        // Move
        A(A &&other) : s(move(other.s)){
            cout << "A move constructor" << endl;
        }
};

class B : public A{

    private:

    public:
};

int main(){

    //B x1;
    //B x2 = x1;

    B x1;
    B x2 = x1;
    B x3 = move(x2);
    
    cout << "X1 : " << x1.s << endl;
    cout << "X2 : " << x2.s << endl;
    cout << "X3 : " << x3.s << endl;
    return 0;
}