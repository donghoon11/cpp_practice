// 프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 heap
// 컴파일러에 어느 정도 안정성이 보장되는 stack 과 달리 heap은 사용자가 제어해야함.
// new 는 melloc과 대응되는 것으로 메모리를 할당하고,
// delete 은 free에 대응되는 것으로 메모리를 해제한다.

#include <iostream>

using namespace std;

/*
int main(){
    int* p = new int;   // int 크기의 공간을 할당하여 그 주소값을 p에 집어 넣음.
    *p = 10;

    cout << *p << endl;

    delete p;       // p 에 할당도니 공간이 해제된다.
    return 0;
}
*/

// new로 배열 할당하기
int main(){
    int arr_size;
    cout << "array size : ";
    cin >> arr_size;
    int *list = new int[arr_size];      // 크기가 arr_size 인 int 배열을 생성.

    for (int i = 0; i < arr_size; i++){
        list[i] = i;
    }
    
    for (int i=0; i < arr_size; i++){
        cout << i << " element of list : " << list[i] << endl;
    }

    delete[] list;      // delete[] 를 통해서 list 메모리 해제.
    return 0;
}