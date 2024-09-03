// friend 로 정의된 클래스나 함수들은 원래 클래스의 private 로 정의되나 벼수나 함수들에 접근할 수 있다.
#include <iostream>

using namespace std;

class A {
    private:
    void private_func() {};
    int private_num;

    // B는 A의 친구이므로 B는 A의 변수 및 메서드에 접근할 수 있다.
    // 다만 A 는 B에 접근할 수 없다.
    friend class B;

    // func 함수는 A의 친구이므로 A 의 private 변수에 접근할 수 있다.
    friend void func();
};

class B{
    public:
    void b(){
        A a;
        a.private_func();
        a.private_num = 2;
    }
};

void func(){
    A a;
    a.private_func();
    a.private_num = 2;   
}

int main(){}