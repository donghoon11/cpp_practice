## template
### template 에 대한 설명
```cpp
template <typename T> 
template <class T>
```

위의 코드는 정확히 같은 의미를 같지만 되도록 typename 키워드를 사용하기를 권장한다. C++ 을 처음 나들었던 Bjarne Stroustrup 은 처음에 template 인자로 class 키워드를 사용했는데, 굳이 새로운 키워드를 만들고 싶지 않았다고 한다. 하지만 시간이 흘러서 혼동을 막기 위해 (class T 라 하며 T 자리에 꼭 클래스만 와야 할 것 같은 느낌) typename 이라는 키워드를 사용하기로 하였다.

<br/></br>

```cpp
Vector<int> int_vec;
```

위 코드는 Vector 의 T 가 int 로 치환된 클래스 객체 int_vec 을 생성하게 되는 것이다. 이와 같이 클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것을 클래스 템플릿 인스턴스화 라고 한다. 템플릿은 반드시 인스턴스화 되어야지만 컴파일러가 실제 코드를 생성하게 된다.

<br/></br>

```cpp
Vector<bool> int_vec;
```

bool 데이터 형은 1비트 만으로도 저장할 수 있지만, C++ 에서 기본으로 처리하는 단위가 1 byte 라는 점을 고려하면 8비트를 사용해서 1개 bool 값을 저장해야 한다. 이는 메모리 낭비이며, Vector<bool> 에 대해서는 특별히 따로 처리해줘야 한다.

<br/></br>

### 템플릿 특수화

일부 템플릿에 대해서 따로 처리하는 것을 템플릿 특수화 라고 한다.

```cpp
template <typename A, typename B, typename C>
class test {};

// 만약 A 가 int 이고 C가 double 로 처리하고 싶다면,
class test<int, B, double> {};
```
<br/></br>

Vector<bool> 을 구현하기 위해서 평범한 int 배열을 이용할 수 있다 1개의 int 는 4개의 byte 이므로 32 비트로 이루어지며, 32개의 bool 데이터를 저장할 수 있다. N 번째 bool 데이터는 N/32 번째 int 안에 저장되어 있게 된다. 이를 구현하면 다음의 코드와 같다.

<br/></br>

```cpp
#include <iostream>
#include <string>

template <typename T>
class Vector {
  T* data;
  int capacity;
  int length;

 public:
  // 어떤 타입을 보관하는지

  typedef T value_type;

  // 생성자
  Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(T s) {
    if (capacity <= length) {
      T* temp = new T[capacity * 2];
      for (int i = 0; i < length; i++) {
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      capacity *= 2;
    }

    data[length] = s;
    length++;
  }

  // 임의의 위치의 원소에 접근한다.
  T operator[](int i) { return data[i]; }

  // x 번째 위치한 원소를 제거한다.
  void remove(int x) {
    for (int i = x + 1; i < length; i++) {
      data[i - 1] = data[i];
    }
    length--;
  }

  // 현재 벡터의 크기를 구한다.
  int size() { return length; }

  ~Vector() {
    if (data) {
      delete[] data;
    }
  }
};

template <>
class Vector<bool> {
  unsigned int* data;
  int capacity;
  int length;

 public:
  typedef bool value_type;

  // 생성자
  Vector(int n = 1)
      : data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {
    for (int i = 0; i < capacity; i++) {
      data[i] = 0;
    }
  }

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(bool s) {
    if (capacity * 32 <= length) {
      unsigned int* temp = new unsigned int[capacity * 2];
      for (int i = 0; i < capacity; i++) {
        temp[i] = data[i];
      }
      for (int i = capacity; i < 2 * capacity; i++) {
        temp[i] = 0;
      }

      delete[] data;
      data = temp;
      capacity *= 2;
    }

    if (s) {
      data[length / 32] |= (1 << (length % 32));
    }

    length++;
  }

  // 임의의 위치의 원소에 접근한다.
  bool operator[](int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }

  // x 번째 위치한 원소를 제거한다.
  void remove(int x) {
    for (int i = x + 1; i < length; i++) {
      int prev = i - 1;
      int curr = i;

      // 만일 curr 위치에 있는 비트가 1 이라면
      // prev 위치에 있는 비트를 1 로 만든다.
      if (data[curr / 32] & (1 << (curr % 32))) {
        data[prev / 32] |= (1 << (prev % 32));
      }
      // 아니면 prev 위치에 있는 비트를 0 으로 지운다.
      else {
        unsigned int all_ones_except_prev = 0xFFFFFFFF;
        all_ones_except_prev ^= (1 << (prev % 32));
        data[prev / 32] &= all_ones_except_prev;
      }
    }
    length--;
  }

  // 현재 벡터의 크기를 구한다.
  int size() { return length; }
  ~Vector() {
    if (data) {
      delete[] data;
    }
  }
};

int main() {
  // int 를 보관하는 벡터를 만든다.
  Vector<int> int_vec;
  int_vec.push_back(3);
  int_vec.push_back(2);

  std::cout << "-------- int vector ----------" << std::endl;
  std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

  Vector<std::string> str_vec;
  str_vec.push_back("hello");
  str_vec.push_back("world");
  std::cout << "-------- std::string vector -------" << std::endl;
  std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

  Vector<bool> bool_vec;
  bool_vec.push_back(true);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(false);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);

  std::cout << "-------- bool vector ---------" << std::endl;
  for (int i = 0; i < bool_vec.size(); i++) {
    std::cout << bool_vec[i];
  }
  std::cout << std::endl;
}
```

