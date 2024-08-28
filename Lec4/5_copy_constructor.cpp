#include <iostream>
#include <string.h>

using namespace std;

class Marine{
    private:
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
    Marine();    // default constructor
    Marine(int x, int y);

    Marine(int x, int y, const char* marine_name);
    ~Marine();      // destructor

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x, coord_y = 0, 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

// 생성자 초기화
// Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

// 생성자 초기화
// Marine::Marine(int x, int y) : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

// 소멸자 정의
Marine::~Marine() {
    cout << name << "의 소멸자 호출" << endl;
    if (name != NULL){
        delete[] name;
    }
}




int Marine::attack(){
    return damage;
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp<=0){
        is_dead = true;
    }
}

void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
/*
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
*/
    Marine* marines[100];

    // new 의 경우 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출해준다.
    marines[0] = new Marine(2,3);
    marines[1] = new Marine(3,5);

    // Marine 들의 포인터를 가리키는 배열이기 때문에 
    // 메소드를 호출할 때 -> 를 사용해줘야 된다.
    marines[0] -> show_status();
    marines[1] -> show_status();

    marines[0] -> be_attacked(marines[1]->attack());

    marines[0] -> show_status();
    marines[1] -> show_status();

    // 동적으로 할당한 메모리는 항상 해제.
    delete marines[0];
    delete marines[1];
}