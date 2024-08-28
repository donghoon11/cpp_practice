#include <iostream>
using namespace std;

class MyString{
    private:
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;

    public:
    // capacity 만큼 미리 할당. (explicit 키워드 사용)
    explicit MyString(int capacity);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
};

MyString::MyString(int capacity){
    string_content = new char[capacity];        // 미리 정한 크기만큼 문자열 생성
    string_length = 0;
    memory_capacity = capacity;
    cout << "capacity : "<< memory_capacity << endl;
}

// 문자열로부터 생성
MyString::MyString(const char* str){
    string_length = 0;
    while (str[string_length++]){}

    string_content = new char[string_length];
    memory_capacity = string_length;
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

// 복사 생성자
MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];
    
    for (int i = 0; i != string_length; i++){
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

// explicit 관련
void DoSomethingWithString(MyString s) {
  // Do something...
}

int main(){
    // MyString s(3);
    DoSomethingWithString(3);
}