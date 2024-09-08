#include <iostream>

using namespace std;

class Base{
    public:
    Base() {cout << "기반 클래스"<<endl;}
    virtual void what(){cout << "기반 클래스의 what()" << endl;}
    // 가상 함수는 파생 클래스의 함수가 기반 클래스의 함수를 오버라이드 하기 위해서는 두 함수의 꼴이 정확히 같아야 한다.
};

class Derived : public Base{
    string s;
    public :
    Derived(): Base() {cout << "파생 클래스"<<endl;}
    void what(){cout << "파생 클래스의 what()" <<endl;}
};



int main(){
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    cout << "실제 객체는 Base == " << endl;
    p_p -> what();

    cout << "실제 객체는 Derived == " << endl;
    p_c -> what();      // Base 포인터이지만 컴파일러 시 어떤 함수가 실행될지 정해지지 않고 런타임 시에 정해진다. 이를 dynamic binding 이라고 한다.
   
    return 0;
}