// 함수 템플릿
#include <iostream>
#include <string>

template <typename T>
// T 라는 템플릿은 함수를 의미한다.
T max(T& a, T& b){
    return a > b ? a : b;
}

int main(){
    int a = 1, b = 2;
    // 클래스를 인스턴스화 했을 때 와는 다르게 <> 하는 부분이 없다.
    // 컴파일러가 알아서 max<int>(a,b) 로 인스턴스화 해준다.
    std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

    std::string s = "hello", t = "world";
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}