// operator []
// char& operator[](const int index);

#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;  // 문자열 길이

    int memory_capacity;        // 현재 할당된 용량

    public:
    MyString(char c);       // 문자 하나로 생성
    MyString(const char* str);  // 미리 지정한 포인터 활요, 문자열로부터 생성
    MyString(const MyString& str);  // 복사 생성자
    ~MyString();    // 소멸자

    int length();

    void print() const;
    void println() const;

    char& operator[](const int index);
};

// 생성자
MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;        // c 문자 하나에 대한 메모리 할당
    string_length = 1;
}

MyString::MyString(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}


MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];
    
    for (int i = 0; i != string_length; i++){
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString(){
    delete[] string_content;
}

// class method 정의
int MyString::length(){return string_length; }
void MyString::print()const{
    for (int i = 0; i != string_length; i++){
        cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++){
        cout << string_content[i];
    }
    cout << endl;
}

char& MyString::operator[](const int index) { return string_content[index]; }


int main(){
    MyString str("abcdef");
    str[3] = 'c';       // d 를 c 로 바꾼다.

    str.println();
}

