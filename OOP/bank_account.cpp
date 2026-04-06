#include <iostream>

using namespace std;

class BankAccount{
    private:
        string accountNumber;
        double balance;
        string ownerName;
        static double interestRate;
        static int totalAccounts;
    
    public:
        BankAccount(){
            accountNumber = "1234567890";   
            balance = 0;
            ownerName = "John Doe";
            totalAccounts++;
        }

        BankAccount(string number, double bal, string name){
            accountNumber = number;
            balance = bal;
            ownerName = name;
            totalAccounts++;
        }

        BankAccount(string number, string name){
            accountNumber = number;
            balance = 0;
            ownerName = name;
            totalAccounts++;
        }

        BankAccount(const BankAccount &other){
            this->accountNumber = other.accountNumber;
            this->balance = other.balance;
            this->ownerName = other.ownerName;
            totalAccounts++;
        }

        ~BankAccount(){
            totalAccounts--;
            cout << "Account number " << accountNumber << " is being destroyed" << endl;
        }

        void deposit(double amount){
            balance += amount;
        }

        bool withdraw(double amount){
            if(balance >=amount){
                balance -= amount;
                return true;
            }
            else{
                return false;
            }
        }

        void applyInterest(){
            balance += balance * interestRate;
        }

        void displayAccountInfo(){
            cout << "Account number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << "Owner name: " << ownerName << endl;
            cout << "Total accounts: " << totalAccounts << endl;
        }

        string getAccountNumber(){
            return accountNumber;
        }

        double getBalance(){
            return balance;
        }

        string getOwnerName(){
            return ownerName;
        }

        void setAccountNumber(string number) {
            this->accountNumber = number;
        }

        void setBalance(double bal){
            this->balance = bal;
        }

        void setOwnerName(string name){
            this->ownerName = name;
        }

        static double getInterestRate(){
            return interestRate;
        }

        static void setInterestRate(double rate){
            interestRate = rate;
        }

        static int getTotalAccounts(){
            return totalAccounts;
        }
        
        



};

double BankAccount::interestRate = 0.05;
int BankAccount::totalAccounts = 0;

int main(){
    // 1. СОЗДАНИЕ ОБЪЕКТОВ
    BankAccount account1("1234567890", 1000, "John Doe");
    BankAccount account2("9876543210", "Jane Smith");  // баланс 0
    BankAccount account3;  // по умолчанию
    
    cout << "=== ПОСЛЕ СОЗДАНИЯ ===\n";
    account1.displayAccountInfo();
    account2.displayAccountInfo();
    account3.displayAccountInfo();
    cout << "Всего счетов: " << BankAccount::getTotalAccounts() << "\n\n";
    
    // 2. ПРОВЕРКА ГЕТТЕРОВ
    cout << "=== ГЕТТЕРЫ ===\n";
    cout << "Номер счета 1: " << account1.getAccountNumber() << endl;
    cout << "Баланс счета 1: " << account1.getBalance() << endl;
    cout << "Владелец счета 1: " << account1.getOwnerName() << endl << endl;
    
    // 3. ПРОВЕРКА СЕТТЕРОВ
    cout << "=== СЕТТЕРЫ ===\n";
    account1.setAccountNumber("1111111111");
    account1.setBalance(2000);
    account1.setOwnerName("John Smith");
    cout << "После изменения:\n";
    account1.displayAccountInfo();
    cout << endl;
    
    // 4. ПРОВЕРКА DEPOSIT
    cout << "=== DEPOSIT ===\n";
    cout << "Баланс account2 до пополнения: " << account2.getBalance() << endl;
    account2.deposit(500);
    cout << "Баланс account2 после пополнения на 500: " << account2.getBalance() << endl << endl;
    
    // 5. ПРОВЕРКА WITHDRAW
    cout << "=== WITHDRAW ===\n";
    cout << "Баланс account1: " << account1.getBalance() << endl;
    
    if(account1.withdraw(500)) {
        cout << "Снято 500, новый баланс: " << account1.getBalance() << endl;
    } else {
        cout << "Недостаточно средств!\n";
    }
    
    if(account1.withdraw(2000)) {
        cout << "Снято 2000, новый баланс: " << account1.getBalance() << endl;
    } else {
        cout << "Недостаточно средств для снятия 2000!\n";
    }
    cout << endl;
    
    // 6. ПРОВЕРКА APPLY INTEREST
    cout << "=== APPLY INTEREST ===\n";
    cout << "Текущая ставка: " << BankAccount::getInterestRate() * 100 << "%\n";
    cout << "Баланс account1 до начисления процентов: " << account1.getBalance() << endl;
    account1.applyInterest();
    cout << "Баланс account1 после начисления процентов: " << account1.getBalance() << endl << endl;
    
    // 7. ПРОВЕРКА СТАТИЧЕСКИХ МЕТОДОВ
    cout << "=== СТАТИЧЕСКИЕ МЕТОДЫ ===\n";
    cout << "Текущая процентная ставка: " << BankAccount::getInterestRate() * 100 << "%\n";
    BankAccount::setInterestRate(0.10);
    cout << "Новая процентная ставка: " << BankAccount::getInterestRate() * 100 << "%\n";
    cout << "Всего создано счетов: " << BankAccount::getTotalAccounts() << endl << endl;
    
    // 8. ПРОВЕРКА КОНСТРУКТОРА КОПИРОВАНИЯ
    cout << "=== КОНСТРУКТОР КОПИРОВАНИЯ ===\n";
    BankAccount account4(account1);  // копия account1
    cout << "Оригинал (account1): " << account1.getAccountNumber() << ", " << account1.getOwnerName() << endl;
    cout << "Копия (account4): " << account4.getAccountNumber() << ", " << account4.getOwnerName() << endl;
    cout << "Всего счетов: " << BankAccount::getTotalAccounts() << endl << endl;
    
    // 9. ИЗМЕНЕНИЕ КОПИИ (проверка, что это независимый объект)
    cout << "=== ИЗМЕНЕНИЕ КОПИИ ===\n";
    account4.setOwnerName("Copy Owner");
    account4.setBalance(999);
    cout << "Оригинал: " << account1.getOwnerName() << ", баланс: " << account1.getBalance() << endl;
    cout << "Копия: " << account4.getOwnerName() << ", баланс: " << account4.getBalance() << endl;
    cout << "Всего счетов: " << BankAccount::getTotalAccounts() << endl << endl;
    
    cout << "=== ПРОГРАММА ЗАВЕРШАЕТ РАБОТУ ===\n";
    
    return 0;
}  // здесь вызовутся деструкторы для всех объектов