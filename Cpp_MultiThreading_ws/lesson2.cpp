/*************************************************************************************************************
 * 
 * -> Peki threadler ne için kullanılır?
 * 
 * - concurrency : Multiple program run at the same time
 * Örnek 1 incelendiğinde iki farklı toplama işlemi için for döngüsü kullanılmıştır. Burada ilk toplama işlemi
 * bittikten sonra sunuç ekrana yazırıp diğer döngüye geçirilecek ve oradaki toplama işlemi yapılacaktır. Ve
 * sonuç ekrana yazdırılacak. Ancak Örnek ikiye bakacak olursak burada bir for döngüsü ile iki toplama işlemide
 * aynı anda yapılmıştır. Ve sonunda sonuçlar ekrana yazılmıştır. Buna  concurrency mantığı olarak örnek verebiliriz.
 * 
 * Bu basit bir örnek ancak buradaki gibi sum1 toplama işlemi bitmeden sum2 toplama işleminin bitmesini istiyorsanız,
 * "tread" kullanılabilir.
 * 
 * Başka bir örnek olarak server'lar verilebilir. Sunucular aynı anda birden fazla sistemle iletişim kurabilmektedirler.
 * Bu işlemleri yaparken sistemlere eş zamanlı olarak hizmet vermektedirler. Bir sistemin işinin bitmesini bekleyip
 * diğer istemleri sırada bekletmiyorlar. Her sistem için belirli veya rassal aralıklarda işlemler yaparak bütün sistemlere
 * aynı anda hizmet vermektedirler.
 * 
 * - calling periodic functional/functions:
 * Bir gömülü sistemde belirli aralıklarda portan/portlardan değer okumak veya değer göndermek için kullanılabilir.
 * 
 * Anahtar Kelimeler
 * - memory model (Hafıza modeli)
 * - threads      (Thread sınıf yapısı)
 * - mutexs and locks (kilitleme ve kilit açma)
 * - thread local data
 * - condition variables
 * - tasks
 * 
 *************************************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example1
/*
#include <iostream>

using namespace std;

void sendData(int i, string name){
    cout << "Sending data " << name << ": " << i << endl;
}



int main(){

    int sum1 = 0, sum2 = 0;

    for(int i=0;i<10;i++){
        sum1 = sum1 +i;
    }
    sendData(sum1,"Sum1");

    for(int i=0;i<10;i++){
        sum2 = sum2 +i;
    }
    sendData(sum2, "Sum2");

    return 0;
}*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example2
/*
#include <iostream>

using namespace std;

void sendData(int i, string name){
    cout << "Sending data " << name << ": " << i << endl;
}



int main(){

    int sum1 = 0, sum2 = 0;

    for(int i=0;i<10;i++){
        sum1 = sum1 +i;
        sum2 = sum2 +i;
    }
    sendData(sum1,"Sum1");
    sendData(sum2, "Sum2");

    return 0;
}
*/