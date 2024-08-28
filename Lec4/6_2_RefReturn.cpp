// 레퍼런스를 리턴하는 함수
#include <iostream>

using namespace std;

class A{
    private:
    int x;

    public:
    A(int c) : x(c) {}      // 생성자

    int& access_x() {return x;}     // x 의 레퍼런스를 리턴
    int get_x() {return x;}

    void show_x(){cout<< x << endl;}
};

int main(){
    A a(5);
    a.show_x();     // 5

    int& c = a.access_x();      // 변수 C 는 클래스 변수의 별명
    c = 4;      // 클래스 변수 5->4 변경
    a.show_x(); // 4

    int d = a.access_x(); // d가 그냥 int 변수이다. 
    d = 3;      // 
    a.show_x(); // 클래스 변수는 앞서 4로 변경했기에 4로 출력

    int f = a.get_x();
    f = 1;
    a.show_x();     // 클래스 변수는 앞서 4로 변경했기에 4로 출력

//    아래는 오류
//    int& e = a.get_x(); // 임시로 생성된 int 는 문장이 끝나면 소멸. 레퍼런스를 가질 수 없다.
//    e = 2;
//   a.show_x();

}