#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    while (true){
        cin >> t;
        cout << "입력 : " << t << endl;
        if (cin.fail()){
            cout << "다시 입력해주세요" << endl;
            cin.clear();        // 플래그들 초기화
            cin.ignore(100, '\n');      // 개행문자가 나올 때까지 무시한다.
        }
        if (t==1) break;
    }
} 