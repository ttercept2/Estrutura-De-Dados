#include <iostream>
#include <cmath>
using namespace std;

class biorritmo{
    private:
    int dias[30];
    double amor;
    public:
        biorritmo(){
            for(int i=0;i<30;i++){
                dias[i]=i+1;
            }
        }
        int amorIntenso(){
            int maisInteso = dias[0];
            for(int i=1;i<30;i++){
                if(calculaAmor(dias[i])>calculaAmor(maisInteso)){
                    maisInteso = dias[i];
                }
            }
            return maisInteso;
        }
        double calculaAmor(int i){
            return sin(0.126*i - 1.6);
        }
};