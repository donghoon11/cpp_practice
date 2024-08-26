#include <iostream>

using namespace std;

class Date{
    int year_;
    int month_;
    int day_;

    public:
    void showdate();

    Date(){
        cout << "기본 생성자 호출" << endl;
        year_ = 2021;
        month_ = 2;
        day_ = 12;
    }
    Date(int year, int month, int day){
        cout << "새로운 생성자 호출" << endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::showdate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day = Date();        // 디폴트 생성자
  Date day2(2012, 10, 31);      // 새로운 생성자

  day.showdate();
  day2.showdate();

  return 0;
}