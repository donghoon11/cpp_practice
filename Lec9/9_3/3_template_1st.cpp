/*
 템플릿을 통해서 타입이 마치 인자 인것 처럼 사용하는 것을 바로 일반화 프로그래밍 (generic programming) 혹은 그냥 제너릭 프로그래밍 이라고 부릅니다.
*/
# include <iostream>

template <typename T, unsigned int N>
class Array{
    T data[N];

    public :
    Array(T (&arr)[N]){
        for (int i = 0; i < N; i++){
            data[i] = arr[i];
        }
    }

    T* get_array(){return data;}

    unsigned int size(){return N;}

    void print_all(){
        for (int i = 0; i < N; i++){
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
  int arr[3] = {1, 2, 3};

  // 배열 wrapper 클래스
  Array<int, 3> arr_w(arr);

  arr_w.print_all();
}
