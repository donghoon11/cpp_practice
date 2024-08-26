#include <iostream>

using namespace std;

// for 문
/*
int main(){
    int i;
    for (i=0; i<10; i++){
     cout << i << endl;   
    }
    return 0;
}
*/

/*
// 1~10 까지 더하는 프로그램
int main(){
    int i;
    int sum = 0;
    for (i=1; i<=10; i++){
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
*/

// while 문
/*
int main(){
    int i = 1;
    int sum = 0;
    while (i <= 10){
        sum += i;
        i++;    // i 는 1씩 증가.
    }
    cout << "합 : " << sum << endl;
    
    return 0;
}
*/

// while 문 활용 행운의 숫자 맞추기
int main(){
    int lucky_number = 3;   // hidden number
    cout << "숫자 맞추기" << endl;
    
    int user_input;

    while (1){
        cout << "input : ";
        cin >> user_input;  // cin 은 변수를 보고 int, char 을 구분.
        if (lucky_number == user_input){
            cout << "correct!" << endl;
            break;
        }
        else{
            cout << "wrong!" << endl;
        }
    }
    return 0;
}