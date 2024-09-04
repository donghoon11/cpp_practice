#include <iostream>
#include <string>

// 사원 정보 클래스로 만들어서 보관.; {이름, 나이, 직책, 직책의 순위}
// 평사원 : 1, 대리 : 2, 오름차순으로
class Employee {
    private:
    std::string name;
    int age;

    std::string position;
    int rank;

    public:
    // 생성자
    Employee(std::string name, int age, std::string position, int rank)
        : name(name), age(age), position(position), rank(rank) {}
    // 복사 생성자
    Employee(const Employee& employee){
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }
    // 디폴트 생성자
    Employee() {}

    // 클래스 안에서 메서드 내용 완전 정의
    void print_info() {
        std::cout << name << " (" << position << " , " << age << ") ==> "
                << calculate_pay() << "만원" << std::endl;
    }
    // 클래스 안에서 메서드 내용 정의
    int calculate_pay() { return 200 + rank * 50; } // 직급에 따라 50씩 더 받는다.
};

// 근속 년수를 포함시키는 Manager class
class Manager {
    private:
    std::string name;
    int age;

    std::string position;
    int rank;
    int year_of_service;

    public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
    : name(name), age(age), position(position), rank(rank), year_of_service(year_of_service) {}

    //  복사 생성자
    Manager(Manager& manager){
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }

    //디폴트 생성자
    Manager(){}

    int calculate_pay(){ return 200 + rank*50 + 5*year_of_service; }
    void print_info() {
        std::cout << name << " (" << position << " , " << age << ", "
                << year_of_service << "년차) ==> " << calculate_pay() << "만원"
                << std::endl;
    }
};

class EmployeeList {

    private:
    int alloc_employee;     // 할당된 배열 크기
    int current_employee; // 현재 배열안에 들어가 있는 양
    int current_manager;

    Employee **employee_list;       // 직원 데이터, Employee 클래스 접근
    Manager **manager_list;

    public:
    // 생성자
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
        employee_list = new Employee*[alloc_employee];  // 추가해야할 사원 수 만큼 Employee 클래스 생성
        manager_list = new Manager*[alloc_employee];
        current_employee = 0;
        current_manager = 0;
    }
    // 소멸자
    ~EmployeeList(){
        for (int i=0; i < current_employee; i++){
            delete employee_list[i];        // 리스트 데이터에 할당한 메모리 해제
        }
        for (int i=0; i < current_manager; i++){
            delete manager_list[i];        // 리스트 데이터에 할당한 메모리 해제
        }        
        delete[] employee_list;     // 리스트 클래스 생성에 할당한 메모리 해제. 
        delete[] manager_list;
    }

    // 사원을 추가하는 메서드
    void add_employee(Employee* employee){
        // alloc_employee >= current_employee 가정.
        employee_list[current_employee] = employee;
        current_employee++;
    }
    // 현재까지 만들어진 사원 클래스 
    int current_employee_num(){return current_employee;}

    void add_manager(Manager* manager){
        manager_list[current_manager] = manager;
        current_manager++;
    }

    void print_employee_info(){
        int total_pay = 0;
        for (int i = 0; i != current_employee; i++){
            employee_list[i] -> print_info();       // Employee 클래스 메서드 접근.
            total_pay += employee_list[i] -> calculate_pay();
        }
        for (int i = 0; i != current_manager; i++){
            manager_list[i] -> print_info();       // Employee 클래스 메서드 접근.
            total_pay += manager_list[i] -> calculate_pay();
        }
        std::cout << "총 비용 : " << total_pay << std::endl;
    }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
    
    emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();
    return 0;
}