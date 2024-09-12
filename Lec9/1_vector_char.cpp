#include <iostream>
// #include <string>

// char 을 담는 Vector 
class Vector {
    char* data;
    int capacity;
    int length;

    public:
    Vector(int n =1) : data(new char[n]), capacity(n), length(0) {}
    ~Vector(){
        if (data){
            delete[] data;
        }
    }

    // 배열 맨 뒤에 새로운 원소를 추가한다.
    void push_back(char s){
        if (capacity <= length){
            char* temp = new char[capacity * 2];
            for (int i = 0; i < length; i++){
                temp[i] = data[i];
            }
            
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    char operator[](int i) {return data[i];}

    // x 번째 위치한 원소를 제거한다.
    void remove(int x){
        for (int i = x+1; i < length; i++){
            data[i - 1] = data[i];
        }
        length--;
    }

    int size() {return length;}
};

int main(){
    return 0;
}