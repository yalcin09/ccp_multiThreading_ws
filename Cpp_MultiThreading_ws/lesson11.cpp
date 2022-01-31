/*******************************************************************************
********************************************************************************
 * 
 * L value ve R value
 * 
 * L value : cpp'da bir değer ve hafızada (heap/stack) tutuluyor ve bu tutulan
 * değer adresi alınan bir değer.
 * 
 * R value : cpp'da sol taraf değeri olmayan herşeye denir.
 * 
 * Yani, bir ifadenin adresi alınabiliyor ve kullanılabiliyorsa bu L value'dir.
 * 
 * Bu ifadelerin kullanılmasının nedeni;
 *      - Gereksiz kopyalanma yapmamak
 *      - Geçici değerler için hafızada yer ayırmamak
 *için kullanılır. (memory optimization)
 * 
********************************************************************************
*******************************************************************************/

// Example 1
/*
#include <iostream>

using namespace std;

int main(){

    int i = 16; // i: L value, 16: R value
    int *iptr = &i; // i değerinin adresi alındı.

    i = 5;

    int k = i + 55; // k: L value, i+55: R value
    
    // int *kiptr = &(i+55); -> error
    // 12 = k; -> error


    return 0;
}
*/

// Example 2
/*
#include <iostream>
using namespace std;

int main(){

    int x = 5;          // Adres bölgesine sahip
    int &r1 = x;         // r1: L value, x: L value, 5: R value

    r1++;
    r1++;
    cout << "r1 : " << r1 << endl;

    //int &r2 = 7; // -> error
    const int &r3 = 7;

    // r3++; // -> error

    cout << "r3 : " << &r3 << endl;
    cout << "r3 : " << *(&r3) << endl;

    return 0;
}
*/

//Example 3
/*
#include <iostream>

using namespace std;

int callFunction1(int &a){
    return a;
}

int callFunction2(int a){
    return a;
}

int main(){

    int i = 15;
    callFunction1(i);  
    //callFunction1(15); // syntax hatası: L value değerine R value değeri atanıyor.

    callFunction2(i);  
    callFunction2(15); 
    return 0;
}
*/

// Example 4
/*
#include <iostream>
using namespace std;

int main(){

    int x;
    int &r = x;
    const int &r1 = 15;

    //int &r2 = 111; -> error

    int &&r2 = 111; // 111: initialization value, r2: içerisinde int türünden değer tutan referans 
    r2++;
    cout << "r2: " << r2 << endl;

    //int &&r3 = x; -> error
    //int &&r3 = r; -> error
    //int &&r3 = r2; -> error
    // r2: L value bir ifade olduğu için hata alınmıştır.

    //const int &&r3 = r2; -> error

    return 0;
}
*/

//Example 5
/*
#include <iostream>
using namespace std;

void function(int &r){
    cout << "L value referans : " << r << endl;
}

void function(int &&r){
    cout << "R value referans : " << r << endl;
}

int main(){

    int a = 5;

    function(a);
    function(15);

    return 0;
}
*/

//Example 6
#include <iostream>
using namespace std;

int sum(int a, int b){
    return a+b; // constant or literal
}

int &sum1(int &a, int &b){
    // int &s = a+b; -> error
    int &s = a;
    return s; // constant or literal
}

int main(){

    int a=4, b=15;
    cout << "R value : " << sum(a,b) << endl;

    a = 5;
    b = 6;

    int result = sum(a,b); // returns R value
    cout << "Result : " << result << endl;
    
    a = 15;
    b = 12;

    //int &resultptr = sum(a,b); -> error : geri dönüş değeri R value
    //cout << "resultptr : " << sum << endl;
    
    int &&resultptr = sum(a,b);
    cout << "resultptr : " << resultptr << endl;
    
    a = 2;
    b = 3;

    const int &result3 = sum(a,b);
    cout << "Result3 : " << result3 << endl;
    
    a = 45;
    b = 55;
    const int &&result4 = sum(a,b);
    cout << "Result4 : " << result4 << endl;

    a = 50;
    b = 55;

    int &result5 = sum1(a,b);
    cout << "Result5 : " << result5 << endl;


    
    return 0;
}