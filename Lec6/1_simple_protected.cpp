// protected : 상속 관계에서 자식 클래스는 부모 클래스의 변수에 접근 가능.
#include <iostream>
#include <string>

class Base {
    protected:
    std::string parent_string;

    public:
    Base() : parent_string("기반") {  std::cout << "기반 클래스" <<  std::endl; }

    void what() {  std::cout << parent_string <<  std::endl; }
};

class Derived : public Base {
    std::string child_string;

    public:
    Derived() : Base(), child_string("파생") {         // 상속받는 기반 클래스의 생성자 먼저 호출, 다음으로 자신의 생성자 실행.
        std::cout << "파생 클래스" << std::endl;
        what();
        // 부모 클래스의 변수에 접근
        // parent_string = "바꾸기";
    }
    // Base 클래스의 what 메서드와 다른 s함수로 컴파일 상에서 인식된다. 
    // Derived 에 what 함수가 정의되어 있기 때문에 Derived 의 생성자에서 what 을 호출 할 때 (굳이) 멀리 Base 의 함수들 까지 뒤지지 않고, 
    // 바로 앞에 있는 Derived 의 what 함수를 호출하게 됩니다.
    void what() {  std::cout << child_string <<  std::endl; }
};

int main() {
  std::cout << " === 기반 클래스 생성 ===" <<  std::endl;
  Base p;
  std::cout << p.parent_string << std::endl;

  std::cout << " === 파생 클래스 생성 ===" <<  std::endl;
  Derived c;
//   std::cout << c.parent_string << std::endl;

  return 0;
}
