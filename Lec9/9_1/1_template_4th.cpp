// 타입이 아닌 템플릿 인자를 활용하는 예시. 대표적으로 배열.
#include <iostream>
#include <array>

int main(){
    // 마치 C 에서의 배열처럼 {} 을 통해 배열을 정의할 수 있다.
    // 배열들의 원소들의 타입과 int 크기를 템플릿 인자로 명시한 뒤에 초기화 해주면 된다.
    std::array<int, 5> arr = {1,2,3,4,5};
    // int arr[5] = {1,2,3,4,5}; 와 동일

    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// template <typename T>
// void print_array(const T& arr) {
//   for (int i = 0; i < arr.size(); i++) {
//     std::cout << arr[i] << " ";
//   }
//   std::cout << std::endl;
// }

// int main() {
//   std::array<int, 5> arr = {1, 2, 3, 4, 5};
//   std::array<int, 7> arr2 = {1, 2, 3, 4, 5, 6, 7};
//   std::array<int, 3> arr3 = {1, 2, 3};

//   print_array(arr);
//   print_array(arr2);
//   print_array(arr3);
// }
