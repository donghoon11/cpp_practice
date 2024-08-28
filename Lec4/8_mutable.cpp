#include <iostream>

class A {
  private:
//   int data_;        // 클래스 내부 멤버 변수
  mutable int data_;

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const {
    data_ = x;  // 불가능!      // 클래스 내부 멤버 변수 접근 불가능.
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}