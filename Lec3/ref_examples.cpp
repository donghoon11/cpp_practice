#include <iostream>

using namespace std;

// example 1
/*
// 파일 빌드 시 change_val 함수를 최상단에 작성해줘야 오류가 안났음.
int change_val(int &p){     // 특정 변수 name 을 함수 인자로 전달받는다.
    p = 3;
    return 0;
}

int main(){
    int number = 5;
    cout << number << endl;

    change_val(number);     // number는 3 이라는 값으로 변경된다.
    cout << number << endl;

    return 0;
}
*/

// example 2
int main(){
    int x;
    int& y = x;
    int& z = y;
    x = 1;
  x = 1;
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

  y = 2;
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

  z = 3;
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    
    return 0;
}

// 사실 x = y = z 라는 관계가 유지되는 것.