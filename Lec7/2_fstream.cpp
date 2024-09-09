// 파일 스트림은 기본적으로 istream 이나 ostream 클래스보다 더 지원하는 기능이 많다.
// 각각을 상속 받은 것이 ifstream, ofstream 이다.
// 이들 클래스를 모두 포함하는 라이브러리로 fstream 을 사용하면 된다.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    // 파일 읽기 준비
    ifstream in("test.txt");
    string s;

    if (in.is_open()){
        in >> s;
        cout << "입력 받은 문자열 : " << s << endl;
    } else{
        cout << "파일을 찾을 수 없습니다." << endl;
    }

    in.close();
    in.open("other.txt");

    if (in.is_open()){
        in >> s;
        cout << "입력 받은 문자열 : " << s << endl;
    } else{
        cout << "파일을 찾을 수 없습니다." << endl;
    }
    return 0;
}