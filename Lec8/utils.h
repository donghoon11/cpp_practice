#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

namespace MyExcel{
class Vector{
    private:
    string* data;
    int capacity;
    int length;

    public:
    // 생성자
    Vector(int n = 1);

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(string s);

    // 임의의 위치의 원소에 접근한다.
    string operator[](int i);

    // remove the index 'x' element
    void remove(int x);

    // Calculate size of current vector
    int size();

    ~Vector();
};

// Stack
// linked list 를 사용하기 대문에 데이터를 보관하기 위해서 하나의 노드를 만들어서 노드들을 체인처럼 엮을 것.
class Stack {
    struct Node{
        Node* prev;
        string s;

        Node(Node* prev, string s) : prev(prev), s(s) {}
    };

    Node* current;
    Node start;

    public:
    Stack();

    // 최상단에 새로운 원소를 추가한다.
    void push(string s);

    // 최상단의 원소를제거하고 반환한다.
    string pop();

    // 최상단의 원소를 제거하지 않고 반환한다.
    string peek();

    // 스택이 비어있는지의 유무를 반환한다.
    bool is_empty();

    ~Stack();
};

class NumStack {
  struct Node {
    Node* prev;
    double s;

    Node(Node* prev, double s) : prev(prev), s(s) {}
  };

  Node* current;
  Node start;

 public:
  NumStack();
  void push(double s);
  double pop();
  double peek();
  bool is_empty();

  ~NumStack();
};


class Cell{
  protected:
  int x, y;
  Table* table;

  string data;

  public:
  virtual string stringify();
  virtual int to_numeric();

  Cell(string data, int x, int y, Table* table);
};

class Table{
  protected:
  // 행 및 열의 최대 크기
  int max_row_size, max_col_size;

  // 데이터를 보관하는 테이블
  // Cell* dmf qhrhksgksms 2ckdnjs qoduf
  Cell*** data_table;

  public:
  Table(int max_row_size, int max_col_size);
  ~Table();
  
  // 새로운 셀을 row 행 col 열에 등록한다.
  void reg_cell(Cell* c, int row, int col);

  //해당 셀의 정수값을 반환한다.
  // s : 셀 이름
  int to_numeric(const string& s);

  // 행 및 열 번호로 셀을 호출한다.
  int to_numeric(int row, int col);

  // 해당 셀의 문자열을 반환한다.
  string stringify(const string& s);
  string stringify(int row, int col);

  // 순수 가상 함수가 포함되어 있기 때문에 Table 클래스의 객체는 생성할 수 없다.
  virtual string print_table() = 0;
};

// Table 클래스를 상속 받는 TxtTable 클래스
class TxtTable : public Table{
  string repeat_char(int n, char);

  // 숫자로 된 열 번호를 A, B, ..., Z, AA, AB, ... 이런 순으로 넘버링
  string col_num_to_str(int n);

  public:
  TxtTable(int row, int col);

  // 텍스트로 표를 출력
  string print_table();
};
}
#endif