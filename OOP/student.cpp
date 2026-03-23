#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
    string name;
    int age;
    double grade;

    public:
    Student(): name("Unknown"), age(0), grade(0.0){}
    
    Student(string name, int age, double grade): name(name), age(age), grade(grade){}

    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }

    string getName(){ return name; }

    int getAge(){return age;}

    double getGrade(){return grade;}

    void setName(string name){
        if (name.length() > 0)
            this->name = name;
            else cout << "Name is invalid" << endl;}

    void setAge(int age){
        if (age > 0 && age < 120)
            this->age = age;
            else cout << "Age is invalid" << endl;}

    void setGrade(double grade){
        if (grade > 0 && grade < 5.0)
            this->grade = grade;
            else cout << "Grade is invalid" << endl;}

    bool isExellent(){
        if (grade >= 4.5)return true;
        else return false;
    }
};


int main() {

    Student student1("John", 20, 4.5);
    Student student2("Jane", 21, 3.8);
    Student student3("Jim", 22, 2.2);
    Student student9;

    student1.display();
    student2.display();
    student3.display();
    student9.display();

    cout << "Student 1 is exellent: " << student1.isExellent() << endl;
    cout << "Student 2 is exellent: " << student2.isExellent() << endl;
    cout << "Student 3 is exellent: " << student3.isExellent() << endl;
    cout << "Student 9 is exellent: " << student9.isExellent() << endl;

    return 0;
}