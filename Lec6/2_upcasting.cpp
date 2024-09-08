#include <iostream>
#include <string>

using namespace std;

class Base{
    string s;

    public:
    Base():s("기반") {cout << "기반 클래스"<<endl;}
    void what(){cout << s << endl;}
};

class Derived : public Base{
    string s;
    public :
    Derived(): Base(), s("파생") {cout << "파생 클래스"<<endl;}
    void what(){cout << s <<endl;}
};



int main(){
    cout << "기반 클래스 생성" << endl;
    Base p;

    p.what();

    cout << "파생 클래스 생성" << endl;
    Derived c;

    c.what();

    cout << "포인터" << endl;
    Base* p_c = &c;     // c 클래스에 대한 포인터
    // 파생 클래스에서 기반 클래스로 캐스팅 하는 것을 업캐스팅이라고 한다.
    p_c -> what();

    return 0;
}