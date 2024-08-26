/*
1.
동물(struct Animal) 이라는 구조체를 정의해서 이름(char name[30]), 
나이(int age),체력(int health), 배부른 정도(int food), 깨끗한 정도의(int clean) 값을 가진다.

2.
처음에 동물 구조체의 포인터 배열(struct Animal* list[10])을 만들어서 
사용자가 동물을 추가할 때 마다 하나씩 생성한다.

3. 
play 라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는 동물의 상태를 출력한다.

4.
1 턴이 지날 때 마다 동물의 상태를 변경한다.
*/ 

#include <iostream>

using namespace std;

typedef struct Animal
{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}Animal;

void create_animal(Animal *animal){
    cout << "name of animal : ";
    cin >> animal -> name;          

    cout << "age of animal : ";
    cin >> animal -> age;

    animal->health = 100;       // default
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  // 하루가 지나면
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}

void show_state(Animal *animal){
    cout << animal->name << endl;
    cout << "health : "<<animal->health << endl;
    cout << "food : " << animal->food << endl;
    cout << "clean : "<< animal->clean << endl;
}

int main(){
    Animal *list[10];
    int animal_num = 0;

    for (;;){
        cout << "1. Add animal" << endl;
        cout << "2. PLAY" << endl;
        cout << "3. Show state" << endl;

        int input;
        cin >> input;
        
        switch (input)
        {
        int play_with;
        case 1:
            list[animal_num] = new Animal;
            create_animal(list[animal_num]);
            animal_num ++;
            break;
        case 2:
            cout << "choose";
            cin >> play_with;

            if (play_with < animal_num) play(list[play_with]);
            break;
        
        case 3:
            std::cout << "누구껄 보게? : ";
            std::cin >> play_with;
            if (play_with < animal_num) show_state(list[play_with]);
            break;
        }

        for (int i=0; i!=animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    for (int i=0; i != animal_num; i++){
        delete list[i];
    }

}