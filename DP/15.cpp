#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* createarr(int size){
    int* arr = new int [size];
    int num;
    for(int i = 0; i < size; i++){
        num = 1 + rand() % 100;
        arr[i] = num;
    }
    return arr;
}

void printarr(int size, int* arr){
    for(int size_t = 0; size_t < size ; size_t ++){
        cout << arr[size_t] << " ";
    }
}

int amount(int size, int* arr){
    int amount = 0;
    for(int size_t = 0; size_t < size ; size_t ++){
        amount += arr[size_t];
    }
    return amount;
}

double average(int size, int* arr){
    int amount = 0;
    for(int size_t = 0; size_t < size ; size_t ++){
        amount += arr[size_t];
    }
    return static_cast<double>(amount) / size;
}

int main(){
    int size, n;
    int* arr = nullptr;
    srand(time(NULL));
    do{

        system("clear");
        cout << "1. Создать массив\n";
        cout << "2. Показать массив\n";
        cout << "3. Найти сумму\n";
        cout << "4. Найти среднее\n";
        cout << "5. Удалить массив\n";
        cout << "6. Выход\n";

        cin >> n;

        switch (n){
        case 1:
        if(arr != nullptr) {
            cout << "Массив уже существует. Удалите его сначала.\n";
        } else {
            cout << "Введите размер массива: ";
            cin >> size;
            arr = createarr(size);
            cout << "Массив создан\n";
        }
        cin.ignore();
        cin.get();
    break;
        
        case 2:
            cout << "Massive: ";
            printarr(size, arr);
            cout << endl; 
            cin.ignore();
            cin.get();
            break;

        case 3:
            cout << "Amount: " << amount(size, arr);
            cin.ignore();
            cin.get();
            break;

        case 4:
            cout << "Average value: " << average(size, arr);
            cin.ignore();     
            cin.get();
            break;
        case 5:
            if(arr != nullptr){
                delete[] arr;
                arr = nullptr;
                cout << "Massaive deleted\n";
            }else{
                cout << "Massive doesn't exist\n ";
            }
            cin.ignore();
            cin.get();
            break;
        
        
        default:
            cout << "ERROR/n" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }while(n != 6);

    return 0;
}