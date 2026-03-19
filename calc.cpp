#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    if(argc != 4 ){
        cout << "Too many arguments" << endl;
        return 1;
    }

    double a = stod(argv[1]);
    double b = stod(argv[3]);
    char znac = argv[2][0];

    switch(znac){
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            cout << a / b << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    return 0;
}