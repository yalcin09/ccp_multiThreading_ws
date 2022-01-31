/**********************************************************
 * 
 * Lambda
 * 
 * Main içinde Inline fonksiyon oluşturmak için kullanılır.
 * 
 * Derleyici lambda ifadesini;
 *      - bir sınıf tanımlayarak,
 *      - sınıf içerisinde operator() fonksiyonu yazılır,
 *      - geçici nesne oluşturularak,
 * oluşturulur.
 * 
 * closure type:
 *      Derleyicinin lambda karşılığı oluşturduğu sınıf.
 * closure object:
 *      Lambda
 * 
 * Syntax kuralları:
 * 
 *  [] -> lambda introducer
 *  () -> function calling operator
 *  {} -> area that can be coded
 *  
 *  () ?? {code} => int, mutable, noexcept, constexpr
 *  [] ?? () => <typename T>
 * 
 *         [] <typename T> () int,  constexpr, double {code}
 * 
 * 
 *********************************************************/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Example 1
/*
#include <iostream>
#include <cstdio>

using namespace std;

class lambda_1_1{

    public:
    void operator()(){ // operator overloading
        cout << "Lambda_1_1" << endl;
    }

};

int main(){

    []() {
        cout << "Merhaba dostum" << endl;
    }();
    lambda_1_1 a;
    a();

    class lambda1_2{
        public:
        void operator()(){
            cout << "lambda_1_2" << endl;
        }
    };

    lambda1_2()();

    return 0;
}
*/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Example 1

#include <iostream>
#include <cstdio>

using namespace std;

class lambda_1_1{

    public:
    void operator()(){ // operator overloading
        cout << "Lambda_1_1" << endl;
    }

};

int main(){

    // lambda versiyon 1
    []() {
        cout << "lambda_1_0" << endl;
    }();

    // lambda versiyon 2
    lambda_1_1()();

    // lambda versiyon 3
    class lambda1_2{
        public:
        void operator()(){
            cout << "lambda_1_2" << endl;
        }
    };

    lambda1_2()();

    return 0;
}