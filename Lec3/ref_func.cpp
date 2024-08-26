#include <iostream>

using namespace std;

int& function(int& a) {
  a = 5;
  return a;
}

int main() {
  int b = 2;

  int c = function(b);

  cout << "b : " << b << endl;
  // 변수의 주소값을 확인하고 싶다면 &변수명 을 사용한다.
  cout << "b 주소값 : " << &b << endl;
  cout << "c : " << c << endl;
  cout << "c 주소값 : " << &c << endl;
  return 0;
}
// 위 결과를 확인해보면 c는 b와 다른 메모리에 저장된 변수이고, 동일한 값을 저장하고 있음을 확인.
