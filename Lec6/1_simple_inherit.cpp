#include <iostream>

class Base {
  std::string s;

 public:
  Base() : s("기반") {  std::cout << "기반 클래스" <<  std::endl; }

  void what() {  std::cout << s <<  std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
    Derived() : Base(), s("파생") {         // 상속받는 기반 클래스의 생성자 먼저 호출, 다음으로 자신의 생성자 실행.
        std::cout << "파생 클래스" << std::endl;
        what();
    }
    // Base 클래스의 what 메서드와 다른 함수로 컴파일 상에서 인식된다. 
    // Derived 에 what 함수가 정의되어 있기 때문에 Derived 의 생성자에서 what 을 호출 할 때 (굳이) 멀리 Base 의 함수들 까지 뒤지지 않고, 
    // 바로 앞에 있는 Derived 의 what 함수를 호출하게 됩니다.
    void what() {  std::cout << s <<  std::endl; }
};

int main() {
   std::cout << " === 기반 클래스 생성 ===" <<  std::endl;
  Base p;

   std::cout << " === 파생 클래스 생성 ===" <<  std::endl;
  Derived c;

  return 0;
}
