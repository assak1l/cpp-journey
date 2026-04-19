#include <iostream>
#include <cmath>

using namespace std;

class Calculator{
    public:

    double amount;

    Calculator (){
        amount = 0;
}

    Calculator (double amount){
    this->amount = amount;
}

    Calculator operator+(const Calculator &other) const {
        return Calculator(amount + other.amount);
    }

    Calculator operator-(const Calculator &other) const {
        return Calculator(amount - other.amount);
    }

    Calculator operator*(const Calculator &other) const {
        return Calculator(amount * other.amount);
    }

    Calculator operator/(const Calculator &other) const {
        return Calculator(amount / other.amount);
    }

    bool operator == (const Calculator &other) const{
        return amount == other.amount;
    }
    bool operator != (const Calculator &other) const{
        return amount != other.amount;
    }
    bool operator > (const Calculator &other) const{
        return amount > other.amount;
    }
    bool operator < (const Calculator &other) const{
        return amount < other.amount;
    }

    Calculator &operator += (const Calculator &other){
        amount += other.amount;
        return *this;
    }
    Calculator &operator -= (const Calculator &other){
        amount -= other.amount;
        return *this;
    }
    Calculator &operator *= (const Calculator &other){
        amount *= other.amount;
        return *this;
    }
    Calculator &operator /= (const Calculator &other){
        amount /= other.amount;
        return *this;
    }
    Calculator &operator%=(const Calculator &other) {
        amount = fmod(amount, other.amount);
        return *this;
    }

    Calculator operator/(double value){
        return Calculator(amount/value);
    }

    Calculator operator*(double value){
        return Calculator(amount* value);
    }
    Calculator &operator ++ (){
        amount++;
        return *this;
    }
    Calculator &operator -- (){
        amount--;
        return *this;
    }
    Calculator operator ++(int){
        Calculator old = *this;
        ++amount;
        return old;
    }
    Calculator operator -- (int){
        Calculator old = *this;
        --amount;
        return old;
    }


    double operator[](int index){
        if(index == 0) return amount;
        if(index == 1) return (amount - int(amount))*100;
        return 0;
    }
    
};

int main(){
    Calculator a(100);
    Calculator b(50);
    Calculator c;

    c = a + b;
    
    c = a - b;
    
    c = a * 2;
    
    c = a / 2;
    
    a += b;
    
    cout << (a > b) << endl; 
    cout << (a == b) << endl; 
    
    ++a;
    
    a++;
    
    cout << a[0] << endl;   
    cout << a[1] << endl;   
    
    
    return 0;

}