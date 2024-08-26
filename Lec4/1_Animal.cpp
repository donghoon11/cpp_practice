#include <iostream>

using namespace std;

class Animal {
    private:        // 접근 지시자, 아래 내용은 객체 내에서 보호되고 있다.
    int food;       // 멤버 변수
    int weight;     // 멤버 변수

    public:
    void set_animal(int _food, int _weight){        // 멤버 함수
        food = _food;
        weight = _weight;
    }

    void increase_food(int inc){        // 멤버 함수
        food += inc;                    // 클래스 멤버 변수에 접근할 수 있다.
        weight += (inc / 3);            // 클래스 멤버 변수에 접근할 수 있다.
    }

    void view_stat(){       // 멤버 함수
        cout << "food : " << food << endl;
        cout << "weight : " << weight << endl;
    }
};

int main(){
    Animal animal;      // 구조체에서 구조체 변수를 생성할 때와 동일. 다만 구조체는 struct 를 명시한다.
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();

    return 0;
}