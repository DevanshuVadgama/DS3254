#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
    private:
    int static const degree=10;
    int arrcoeff[degree+1];

    public:
    Polynomial(){
        for(int i=0;i<degree+1;i++){
            arrcoeff[i]=0;
        }
    }

    void coefficients(int deg,int val){
        if(deg<0 || deg>degree){
            cout<<"invalid"<<endl;
        }
        arrcoeff[deg]=val;
    }

    int getcoefficient(int deg){
        if(deg<0 || deg>degree){
            cout<<"invalid"<<endl;
        }
        return arrcoeff[deg];
    }

    int evaluate(int x){
        int y=0;
        for(int i=0;i<degree+1;i++){
            y=y+arrcoeff[i]*static_cast<int>(pow(x,i));
        }
        return y;
    }

    Polynomial add(const Polynomial& other) const{
        Polynomial result;
        for(int i=0;i<degree+1;i++){
            result.arrcoeff[i]=arrcoeff[i]+other.arrcoeff[i];
        }
        return result;
    }

    Polynomial mult(const Polynomial& other) const{
        Polynomial m;
        for(int i=0;i<degree+1;i++){
            if(arrcoeff[i] !=0){
                for(int j=0;j<degree+1;j++){
                    if(other.arrcoeff[j] != 0 && i+j<degree+1){
                        m.arrcoeff[i+j] = arrcoeff[i]*other.arrcoeff[j];
                    }
                }
            }
        }
        return m;
    }

    void view() {
        for(int i=0;i<degree+1;i++){
            if(arrcoeff[i]!=0){
            cout<<arrcoeff[i]<<"x^"<<i<<"+";
        }
    }
}
};

int main(){
    Polynomial p1;
    p1.coefficients(0,1);
    p1.coefficients(1,3);
    p1.coefficients(2,9);
    p1.coefficients(3,-1);
    p1.coefficients(4,1);

    Polynomial p2;
    p2.coefficients(0,1);
    p2.coefficients(1,1);
    p2.coefficients(2,-5);
    p2.coefficients(3,2);
    Polynomial p;
    p=p1.add(p2);
    p.view();
    cout<<endl;
    Polynomial q;
    q=p1.mult(p2);
    q.view();

    cout<<endl;

    int result = p1.evaluate(1);
    cout << "p1 evaluated at x=1: " << result << endl;

    
}
