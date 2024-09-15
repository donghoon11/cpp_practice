#include <iostream>
#include <typeinfo>

template <int N>
struct Int
{
    static const int num = N;
};

template <typename T, typename U>
struct add
{
    typedef Int<T::num + U::num> result;
};

// 위 add 클래스의 템플릿은 인자로 두 개의 타입을 받아서 그 타입의 num 멤버를 더해서 
// 새로운 타입인 result 를 만들어 내게 됩니다.

int main() {
  typedef Int<1> one;
  typedef Int<2> two;

  typedef add<one, two>::result three;

  std::cout << "Addtion result : " << three::num << std::endl;
}