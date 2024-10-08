#include "utils.h"
#include <iostream>

namespace MyExcel{
Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}
void Vector::push_back(string s){
    if (capacity <= length){
        string* temp = new string[capacity * 2];        // 배열이 다 차면 그냥 공간을 두 배 늘려준다.
        for (int i=0; i<length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }

    data[length] = s;
    length++;
}

string Vector::operator[](int i) {return data[i];}

void Vector::remove(int x){
    for (int i = x+1; i<length; i++){
        data[i-1] = data[i];
    }
    length--;
}

int Vector::size(){return length;}

Vector::~Vector(){
    if (data){
        delete[] data;
    }
}

// Stack
Stack::Stack() : start(NULL, "") {current = &start;}

void Stack::push(string s){
    Node* n = new Node(current, s);
    current = n;
}

string Stack::pop(){
    if (current == &start) return "";

    string s = current -> s;
    Node* prev = current;
    current = current -> prev;

    // pop 된 노드 제거
    delete prev;
    return s;
}

string Stack::peek() {return current->s;}

bool Stack::is_empty(){
    if (current == &start) return true;
    return false;
}

Stack::~Stack(){
    while (current != &start){
        // 최상단 원소에서 바닥까지 메모리를 해제시켜야 완전히 stack 객체 소멸.
        Node* prev = current;
        current = current -> prev;
        delete prev;
    }
}

// NumStack
NumStack::NumStack() : start(NULL, 0) { current = &start; }
void NumStack::push(double s) {
  Node* n = new Node(current, s);
  current = n;
}
double NumStack::pop() {
  if (current == &start) return 0;

  double s = current->s;
  Node* prev = current;
  current = current->prev;

  // Delete popped node
  delete prev;
  return s;
}
double NumStack::peek() { return current->s; }
bool NumStack::is_empty() {
  if (current == &start) return true;
  return false;
}
NumStack::~NumStack() {
  while (current != &start) {
    Node* prev = current;
    current = current->prev;
    delete prev;
  }
}

// Cell
Cell::Cell(string data, int x, int y, Table* table) : data(data), x(x), y(y), table(table) {}
string Cell::stringify() {return data;}
int Cell::to_numeric() {return 0;}

// Table
Table::Table(int max_row_size, int max_col_size) 
    : max_row_size(max_row_size), max_col_size(max_col_size) {
        data_table = new Cell**[max_row_size];

        for (int i = 0; i < max_row_size; i++){
            data_table[i] = new Cell*[max_col_size];
            for (int j = 0; j < max_col_size; j++){
                data_table[i][j] = NULL;
            }
        }
    }
Table::~Table() {
    for (int i = 0; i < max_row_size; i++) {
        for (int j = 0; j < max_col_size; j++) {
            if (data_table[i][j]) delete data_table[i][j];
        }
    }
    for (int i = 0; i < max_row_size; i++) {
        delete[] data_table[i];
    }
    delete[] data_table;
}
void Table::reg_cell(Cell* c, int row, int col){
    if (!(row < max_row_size && col < max_col_size)) return;

    if (data_table[row][col]){  // 등록하고자 하는 위치에 이미 다른 셀이 있다면 해당 객체 삭제
        delete data_table[row][col];
    }
    data_table[row][col] = c;       // table 의 셀을 등록하는 함수.
}

int Table::to_numeric(const string& s){
    // cell 이름으로 받는다.
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size){
        if (data_table[row][col]){
            return data_table[row][col] -> to_numeric();
        }
    }
    return 0;
}

int Table::to_numeric(int row, int col){
    if (row < max_row_size && col < max_col_size && data_table[row][col]){
        return data_table[row][col] -> to_numeric();
    }
    return 0;
}

string Table::stringify(const string& s){
    // Cell 이름으로 받는다.
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size){
        if (data_table[row][col]){
            return data_table[row][col] -> stringify();
        }
    }
    return 0;
}

string Table::stringify(int row, int col){
    if (row < max_row_size && col < max_col_size && data_table[row][col]){
        return data_table[row][col] -> stringify();
    }
    return "";
}

std::ostream& operator<<(std::ostream& o, Table& table) {
    o << table.print_table();
    return o;
}

// TxtTable
TxtTable::TxtTable(int row, int col) : Table(row, col) {}

// 텍스트로 표를 깨끗하게 출력해준다.
string TxtTable::print_table() {
  string total_table;

  int* col_max_wide = new int[max_col_size];
  for (int i = 0; i < max_col_size; i++) {
    unsigned int max_wide = 2;
    for (int j = 0; j < max_row_size; j++) {
      if (data_table[j][i] &&
          data_table[j][i]->stringify().length() > max_wide) {
        max_wide = data_table[j][i]->stringify().length();
      }
    }
    col_max_wide[i] = max_wide;
  }
  // 맨 상단에 열 정보 표시
  total_table += "    ";
  int total_wide = 4;
  for (int i = 0; i < max_col_size; i++) {
    if (col_max_wide[i]) {
      int max_len = max(2, col_max_wide[i]);
      total_table += " | " + col_num_to_str(i);
      total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

      total_wide += (max_len + 3);
    }
  }

  total_table += "\n";
  // 일단 기본적으로 최대 9999 번째 행 까지 지원한다고 생각한다.
  for (int i = 0; i < max_row_size; i++) {
    total_table += repeat_char(total_wide, '-');
    total_table += "\n" + to_string(i + 1);
    total_table += repeat_char(4 - to_string(i + 1).length(), ' ');

    for (int j = 0; j < max_col_size; j++) {
      if (col_max_wide[j]) {
        int max_len = max(2, col_max_wide[j]);

        string s = "";
        if (data_table[i][j]) {
          s = data_table[i][j]->stringify();
        }
        total_table += " | " + s;
        total_table += repeat_char(max_len - s.length(), ' ');
      }
    }
    total_table += "\n";
  }

  return total_table;
}

string TxtTable::repeat_char(int n, char c) {
    string s = "";
    for (int i = 0; i < n; i++) s.push_back(c);

    return s;
}
// 숫자로 된 열 번호를 A, B, .... Z, AA, AB, ...  이런 순으로 매겨준다.
string TxtTable::col_num_to_str(int n) {
    string s = "";
    if (n < 26) {
        s.push_back('A' + n);
    } else {
        char first = 'A' + n / 26 - 1;
        char second = 'A' + n % 26;

        s.push_back(first);
        s.push_back(second);
    }

    return s;
}
}

int main() {
  MyExcel::TxtTable table(5, 5);
  std::ofstream out("test.txt");

  table.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);
  table.reg_cell(new Cell("C++", 0, 1, &table), 0, 1);

  table.reg_cell(new Cell("Programming", 1, 1, &table), 1, 1);
  std::cout << std::endl << table;
  out << table;
}