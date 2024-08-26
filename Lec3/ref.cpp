// pointer.cpp 내용을 참조자 활용으로 변경.
#include <iostream>

using namespace std;

int main(){
    int a = 3;
    int& another_a = a;     // 앰퍼샌드를 사용하여 a의 참조자를 another_a 로 정의.
    // int* 과 같은 포인터 타입의 참조자를 만드려면 int*& 로 쓴다.

    another_a = 5;      // 참조자의 값이 변경.
    
    cout << "a : " << a << endl;
    cout << "another_a : " << another_a << endl;
    
    return 0;
}
// 결과를 보면 변수 a 의 값도 5로 변경됨을 확인.
// 참조자의 값을 수정하면 참조자에 대한 원래의 변수의 값 또한 수정된다.
// 참조자 = 별명의 역할. 변수명을 2 개로 활용할 수 있는 것.

// 참조자는 굳이 메모리 공간을 차지하지 않는다.

// 레퍼런스가 한 번 별명이 되면 절대로 다른 변수의 별명이 될 수 없다.
// 반면 포인터는 누구를 가리키는지 자유롭게 바꿀 수 있다.
/*
int a = 10;
int* p = &a;

int b = 20;
p = &b;     // p는 이제 변수 b를 가리킨다.
*/