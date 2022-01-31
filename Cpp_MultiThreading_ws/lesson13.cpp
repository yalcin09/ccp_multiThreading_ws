/***************************************
****************************************
*Move sematic ile thread
*   - Hafıza optimizasyonu için thread'in içindeki bütün mekanizmayı oluşturulan bir nesneden
*   diğer nesneye (vector veya list) aktarmak için kullanılırır.
*****************************************
****************************************/

// Example 1
/*
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main(){

    vector<thread> workers;

    for(int i=0;i<5;i++){

        auto t = thread(
            [i]() {
                cout << "Thread function : " << i << "\n";
            }
        );

        workers.push_back(move(t));
    }

    // algorithm -> for_each()
    // belirtilen başlangıçtan - bitişe kadar
    // bütün thread'leri join edilir.
    // En büyük avantajı içerisine lambda ifadesi yazılabilir.
    
//    for_each(workers.begin(), workers.end(), 
//        [](thread &t) {
//           assert(t.joinable());
//            t.join();
//        }
//    );
    

    // VEYA

    // vector yapısı
    for(auto iter = workers.begin(); iter != workers.end(); iter++){
        assert(iter->joinable());
        iter->join();
    }



    return 0;
}
*/

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void task(int i){
    cout << " Worker : " << i << "\n";
}

int main(){

    vector<thread> workers;

    for(int i=0;i<5;i++){
        auto t = thread(&task, i);
        workers.push_back(move(t));
    }

    cout << "Main thread\n";

    for(auto iter = workers.begin(); iter != workers.end(); iter++){
        assert(iter->joinable());
        iter->join();
    }

    return 0;
}