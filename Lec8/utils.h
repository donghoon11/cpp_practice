#ifdef UTILS_H
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

  Node* current;d
  Node start;

 public:
  NumStack();
  void push(double s);
  double pop();
  double peek();
  bool is_empty();

  ~NumStack();
};
}
#endif