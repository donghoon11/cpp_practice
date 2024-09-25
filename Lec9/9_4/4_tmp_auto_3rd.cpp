// 컴파일러가 타입을 정확히 알아낼 수 있는 경우 굳이 그 길고 긴 타입을 적지 않고 간단히 auto 로 표현할 수 있다.
#include <iostream>
#include <typeinfo>

int sum(int a, int b) {return a + b;}

class SomeClass{
    int data;

    public:
    SomeClass(int d) : data(d) {}
    SomeClass(const SomeClass& s) : data(s.data) {}
};

int main(){
    auto c = sum(1, 2);     // 리턴 타입이 정수라고 추측.
    auto num = 1.0 + 2.0;        // double 로 추측
    
    SomeClass some(10);
    auto some2 = some;

    auto some3(10);     // 컴파일러는 SomeClass 객체가 아닌 int 로 인식


    std::cout << "c 의 타입은? :: " << typeid(c).name() << std::endl;
    std::cout << "num 의 타입은? :: " << typeid(num).name() << std::endl;
    std::cout << "some2 의 타입은? :: " << typeid(some2).name() << std::endl;
    std::cout << "some3 의 타입은? :: " << typeid(some3).name() << std::endl;
}