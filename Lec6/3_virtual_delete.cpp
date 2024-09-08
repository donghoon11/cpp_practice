// 상속 시에 소멸자를 가상함수로 만들어야 한다.
#include <iostream>

using namespace std;

class Parent{
    public:
    Parent() { cout << "Parent 생성자 호출" << endl;}
    // ~Parent() { cout << "Parent 소멸자 호출" << endl;}
    virtual ~Parent() { cout << "Parent 소멸자 호출" << endl;}
};

class Child : public Parent
{
    public:
    Child() : Parent() { cout << "Child 생성자 호출" << endl; }
    ~Child() { cout << "Child 소멸자 호출" << endl; }
};

int main(){
    cout << "=== 평범한 Child 생성 ===" << endl;
    Child c;

    cout << "=== Parent 포인터로 Child 가리킬때 ===" << endl;
    Parent *p = new Child();        // p 는 결국 자식 객체이다.
    delete p;
    // 자식 소멸자가 호출되면서 자식 소멸자가 알아서 부모 소멸자도 호출해준다. 
}