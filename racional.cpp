#include <iostream>

using namespace std;

class racional {
    private:
        int num, den;
    public:
        racional(){
            racional(0,1);
        }// 0/1

        racional(int num, int den){
            this->num = num;
            this->den = den;
            reduzir();
        } // num/den --> reduzir

        void reduzir(){
            int rMdc = mdc(num,den);
            num = num / rMdc;
            den = den / rMdc;
        } // (num/MDC(num,den)) / (den/MDC(num,dem))

        bool operator<(racional r){
            bool res = false;
            if(num/den < r.num/r.den){
                res = true;
            }
            return res;
        }; // return true se < r; false caso contr´ario

        bool operator==(racional r){
            bool res = false;
            if(num/den == r.num/r.den){
                res = true;
            }
            return res;
        }; // return true se == r; false caso contr´ario

        bool operator>(racional r){
            bool res = false;
            if(num/den > r.num/r.den){
                res = true;
            }
            return res;
        }; // return true se > r; false caso contr´ario
        
        int mdc(int a, int b) {
            int aux;
            if(a < b) { // troca se a < b
                aux = a;
                a=b;
                b=aux;
            }
            int r = a%b;
            while(r > 0) {
                a = b;
                b = r;
                r = a%b;
            }
            return b;
        }
};

int main(){
    racional r1(10,5);
    racional r2(9,5);
    cout << "Operator<: " << r1.operator<(r2) << endl;
    cout << "Operator==: " << r1.operator==(r2) << endl;
    cout << "Operator>: " << r1.operator>(r2) << endl;
}