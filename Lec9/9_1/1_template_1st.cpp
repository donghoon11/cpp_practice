#include <iostream>
#include <string>

template <typename T>   // 템플릿 인자로 T 를 받게 되며, T 는 반드시 어떠한 타입의 이름임을 명시하고 있다.
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    Vector(int n =1) : data(new T[n]), capacity(n), length(0) {}
    ~Vector(){
        if (data){
            delete[] data;
        }
    }

    // 배열 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s){
        if (capacity <= length){
            T* temp = new T[capacity * 2];
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
    T operator[](int i) {return data[i];}

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
    // int 를 보관하는 벡터를 만든다.
    // <> 안에 전달하려는 것을 명시해준다. ex) Vector<std::string>
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;    
}