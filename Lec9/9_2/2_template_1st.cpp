// 가변 템플릿 
#include <iostream>

template <typename T>
void print(T arg){
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>
// ...은 template parameter pack 이라고 한다.
void print(T arg, Types... args){
    std::cout << arg << ", ";
    print(args...);
}
/* 위의 가변 템플릿을 활용한 print 함수는 아래의 함수와 동일하다.
void print(int arg, double arg2, const char* arg3) {
  std::cout << arg << ", ";
  print(arg2, arg3);
}
*/


int main(){
    print(1,3.1,"abc");
    print(1,2,3,4,5,6,7);
}