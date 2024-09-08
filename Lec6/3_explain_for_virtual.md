## 가상 함수 구현 원리
#### 그냥 모든 함수를 virtual 로 만들면 안되나?
* 일단 모든 함수를 virtual로 만든다고 해서 문제될 것은 없다.
* 말이 virtual 이지 실제 존재하는 함수이고 정상적으로 호출도 된다.
* 실제 java의 경우 모든 함수들이 디폴트로 virtual 함수로 선언된다.

#### 왜 C++ 에서는 사용자가 virtual 키워드를 사용하게 했는가?
* 가상함수를 사용하게 되면 약간의 overhead 가 존재하기 때문.
* 보통의 함수를 호출하는 것보다 가상 함수를 호출하는데 걸리는 시간이 더 많다.
    * C++ 컴파일러는 가상함수가 하나라도 존재하는 클래스에 대해서 가상함수 테이블을 만들게 된다.
    * 가상함수를 호출할 때는 가상테이블을 한 단계 더 거쳐서 실제로 어떤 함수를 고를지 결정한다.
    ```cpp
    class Parent {
        public:
        virtual void func1();       // 가상 함수 테이블에 저장 
        virtual void func2{};       // 가상 함수 테이블에 저장
    };

    class Child : public Parent {
        public:
        virtual void func1();
        void func3();
    };

    int main(){
        Parent *p = Parent();
        p -> func1();       
        // p 가 Parent 를 가리키는 포인터이니까 func1() 을 Parent 클래스에서 찾아본다.
        // func1() 이 가상함수이므로 가상함수 테이블 거쳐서 함수 실행.

        Parent *c = Child();
        c -> func1();
        // c 가 Parent 를 가리키는 포인터이니까 func1() 을 Parent 클래스에서 찾아본다.
        // func1() 이 가상함수이므로 가상함수 테이블로 간다.
        // 가상함수 테이블에서 func1()에 해당하는 함수를 실행하면 Child::func1() 호출되며, 성공적으로 Parent::func1() 을 오버라이드. 
    }
    ```