#include <iostream>

namespace{
    // 이 함수는 이 파일 안에서만 사용할 수 있다.
    int OnlyInThisFile(){} // 파일 빌드 시에 경고 메시지 출력.

    // 이 변수 역시 static int x 와 동일하다.
    int only_in_this_file = 0;
} 

int main(){
  OnlyInThisFile();
  only_in_this_file = 3;
  std::cout << "complete" << std::endl;
  return only_in_this_file;
}
