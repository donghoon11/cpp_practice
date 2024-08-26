// cpp 에서는 같은 이름으 함수를 호출했을 때 구분을 어떻게 하는 것일까.
// 함수를 호출했을 때의 사용하는 인자를 보고 결정.
#include <iostream>

using namespace std;

void print(int x) {cout << x << endl;}
void print(char x) {cout << x << endl;}
void print(double x) {cout << x << endl;}

int main(){
    int a = 1;
    char b = '1';       // 작은 따옴표 사용 권장.
    double c = 1.0f;

    print(a);
    print(b);
    print(c);
}