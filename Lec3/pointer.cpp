#include <iostream>

using namespace std;

int change_val(int *p){     // 함수 인자로 주소값을 전달.
    *p = 3;
    return 0;
}

int main(){
    int number = 5; // number 변수명의 새로운 메모리에 5 라는 정수 기록
    cout << number << endl;

    change_val(&number); // number 의 주소값 전달하여 해당 메모리에 기록된 값을 변경함.
    cout << number << endl;
    return 0;
}