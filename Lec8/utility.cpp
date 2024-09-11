#include "utils.h"

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

}