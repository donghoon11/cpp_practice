// 디폴트 템플릿 인자
#include <iostream>
#include <string>
// //  '= (디폴트 값)' 을 입력.
// template <typename T, int num = 5>
// T add_num(T t){
//     return t + num;
// }

// int main(){
//     int x = 3;
//     std::cout << "x : "<< add_num(x) << std::endl;
// }

template <typename T>
struct Compare {
  bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
  Comp comp;
  if (comp(a, b)) {
    return a;
  }
  return b;
}

int main() {
  int a = 3, b = 5;
  std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

  std::string s1 = "abc", s2 = "def";
  std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2)
            << std::endl;
}