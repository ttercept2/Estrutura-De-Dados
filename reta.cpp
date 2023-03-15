#include <iostream>

using namespace std;

class reta {
    private:
        double a,b;
    public:
        reta(){
            reta(0,0);
        }

        reta(double a, double b){
            this->a = a;
            this->b = b;
        }

        reta (double a,double b, double c){
            reta(a/c,b/c);
        }

        bool horizontal(){
            bool resultado = false;
            if(this->a==0){
                resultado = true;
            }
            return resultado;
        }

        bool vertical(){
            bool resultado = false;
            if(this->b==0){
                resultado = true;
            }
            return resultado;
        }

        bool paralela(reta r){
            bool resultado = false;
            if(this->a == r.a == 0){
                resultado = true;
            }
            else
            if(this->b == r.b == 0){
                resultado = true;
            }
            else
            if(this->a/this->b == r.a/r.b){
                resultado = true;
            }
            return resultado;
        }
};
/*int main(){
    reta r1(10,5);
    reta r2(10,5);
    cout << "Horizontal: " << r1.horizontal() << endl;
    cout << "Vertical: " << r1.vertical() << endl;
    cout << "Paralela: " << r1.paralela(r2) << endl;
}*/
