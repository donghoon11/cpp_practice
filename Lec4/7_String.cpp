// char 로부터 문자열 생성
// 문자열 길이를 구하는 함수
// 문자열 뒤에 다른 문자열 붙이기
// 분자열 내에 포함되어 있는 문자열 구하기
// 문자열이 같은지 비교
// 문자열 사전식 비교
#include <iostream>
#include <string.h>

using namespace std;

class MyString{
    private:
    char* string_content;       // 문자열 데이터를 가리키는 포인터
    int string_length;  // 문자열 길이

    int memory_capacity;    //capacity 를 도입함으로써 여러가지 새로운 함수들을 추가할 수 있게 되었습니다. 

    public:
    // 생성자
    // MyString 클래스에서는 실제 문자에만 해당하는 내용만을 string_content 에 보관.
    MyString(char c);
    MyString(const char* str);  // 문자열로부터 생성
    MyString(const MyString& str);      // 복사 생성자
    ~MyString();

    int length() const;
    void print() const;
    void println() const;

    // assign 함수
    MyString& assign(const MyString& str);      // 문자열 복사
    MyString& assign(const char* str);          // 문자열 포인터 사용

    // 할당할 문자열의 크기를 미리 예약해 놓는 reserve 함수
    // 현재 문자열의 할당된 메모리 크기를 나타내는 capacity 함수
    int capacity() const;
    void reserve(int size);

    // 임의의 위치의 문자를 리턴하는 함수
    // c 문자열의 경우 구조상 배열의 범위를 벗어나는 위치에 대한 문자를 요구하여도 이를 처리할 수 없다.
    // c++ 의 경우 특정 위치의 문자를 얻는 것을 함수로 만들어서 올바르지 않는 위치에 대한 문제를 처리.
    char at(int i) const;

    // 문자열 insert 함수
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

};
MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}

MyString::MyString(const char* str) {
  string_length = strlen(str);
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}
MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }


int MyString::length() const {return string_length; }

void MyString::print() const {
    for (int i=0; i != string_length; i++){
        cout << string_content[i];
    }
}
void MyString::println() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

// assign 함수 정의
MyString& MyString::assign(const MyString& str){
    if (str.string_length > memory_capacity){
        delete[] string_content;
        
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i=0; i != str.string_length; i++){
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;
    return *this;
}
MyString& MyString::assign(const char* str){
    int str_length = strlen(str);
    if (str_length > memory_capacity){
        // 다시 할당
        delete[] string_content;

        string_content = new char[string_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != string_length; i++){
        string_content[i] = str[i];
    }

    string_length = str_length;
    return *this;
}

// assign 이후 추가한 함수들.
int MyString::capacity() const {return memory_capacity; }
void MyString::reserve(int size){
    if (size > memory_capacity){
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++){
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }
    // 만일 예약하려는 size 가 현재 capacity 보다 작으면 아무것도 안해도 된다.
}

char MyString::at(int i) const{
    if (i >= string_length || i<0){     // i가 허용되는 범위 초과하면 NULL 리턴
        return NULL;
    }else{return string_content[i]; }
}
/*
자 이것으로 해서, 우리가 직접 제작한 문자열 클래스 MyString 의 기본적인 함수들은 모두 제작하였다고 볼 수 있습니다.

    문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자

    문자열의 길이를 리턴하는 함수(length)

    문자열 대입 함수(assign)

    문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)

    특정 위치의 문자를 리턴하는 함수(at)
*/

// insert 함수
MyString& MyString::insert(int loc, const MyString& str){
    // i 의 위치 바로 앞에 문자를 삽입하게 된다.
    // abc 라는 문자열에 insert(1, 'd) -> adbc

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc <0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity){
        // 새롭게 동적 할당.
        memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
        int i;
        for (i=0; i < loc; i++){
            string_content[i] = prev_string_content[i];
        }
        // 그리고 새롭게 insert 되는 문자열을 넣는다.
        for (int j=0; j!=str.string_length; j++){
            string_content[i+j] = str.string_content[j];
        }

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
        for (; i < string_length; i++){
            string_content[str.string_length + i] = prev_string_content[i];
        }
        // 동적 할당 해제
        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    } 

    // 만일 초과하지 않는 경우 굳이 동적할당을 할 피요가 없게 된다.
    // 효율적으로 insert 하기 위해 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i=string_length-1; i>=loc; i--){
        // 뒤로 밀기
        string_content[i + str.string_length] = string_content[i];
    }
    //그리고 insert 되는 무나 다시 집언허기
    for (int i=0; i<str.string_length; i++){
        string_content[i+loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str){
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c){
    MyString temp(c);
    return insert(loc, temp);
}



// Test code
int main(){
    MyString str1("very very very long string");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
}