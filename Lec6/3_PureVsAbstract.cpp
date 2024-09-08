// 순수 가상함수 vs 추상 클래스
#include <iostream>

using namespace std;

class Animal{
    public:
    Animal() {}     // 순수 가상함수를 한 개 이상 포함하고 있는 클래스는 객체를 생성할 수 없다. = 추상 클래스
    virtual ~Animal(){}
    virtual void speak() = 0;   // 무엇을 하는지 정의되어 있지 않은 함수 => 반드시 오버라이딩 되어야 함, 순수 가상함수
};

class Dog : public Animal{
    public:
    Dog() : Animal() {}
    void speak() {cout << "wall wall"<< endl;}

};

int main(){
    Animal* dog = new Dog();
    
    Dog d1;
    d1.speak();
    dog -> speak();
}