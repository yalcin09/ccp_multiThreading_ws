// Example 1
/*
#include <iostream>

using namespace std;

class lambda_1_1{
    public:
    // constexpr : derleme aşamasında işleme almak için bir operator başında kullanılır.
    int i = 0;
    constexpr void operator()(){
        i++;
    }
};

int main(){

    [](){
        cout << "Yalçın OLGAÇ" << endl;
    }();



    lambda_1_1()();

    return 0;
}
*/

// Example 2
/*
#include <iostream>

using namespace std;

int main(){

    // Lambda ifadesinde geri dönüş değeri ve parametre yollama
    auto f = [](int x) {
        cout << "Hesaplama : " << x << endl;
        return x;
    };

    f(5);

    return 0;
}
*/

//Example 3
/*
#include <iostream>

using namespace std;

int main(){

    // Lambda ifadesinde geri dönüş değeri ve parametre yollama
    auto f = [](int x) {
        cout << "Hesaplama : " << x << endl;
        return x;
    };

    f(5);

    class lambdaExp{
        public:
        lambdaExp(int y){
            cout << "LambdaExp constructor : " << y << endl;
        }

        int operator()(int x){
            cout << "Hesaplanan : " << x << endl;
            return x;
        }
    };
    auto g = lambdaExp(10)(20);
    cout << "G : " << g << endl;

    return 0;
}
*/

// Example 4
/*
#include <iostream>

using namespace std;

int main(){

    // -> typename : geri dönüş değeri belirleme
    auto f = [](double x, double y, double z) -> double {
        cout << "Yalçın OLGAÇ" << endl;
        return x+y+z;
    };

    class lambdaExp{
        public:
        double operator()(double x, double y, double z) const{
            cout << "lambdaExpression" << endl;
            return x+y+z;
        }
    };

    cout << f(1.2, 5.2, 4.8) << endl;
    cout << lambdaExp()(2.4,5.8,6.7) << endl;

    return 0;
}
*/

//Example 5

#include <iostream>

using namespace std;

int main(){

    cout << [](double x) { return x+x;}(2.5) << endl;

    class lambdaExp{
        public:
        lambdaExp(){
            cout << "default constructor" << endl;
        }
        double operator()(double x, double y, double z) const{
            cout << "operator" << endl;
            return x+y+z;
        }
    };

    cout << lambdaExp()(1,2,3) << endl;


    return 0;
}