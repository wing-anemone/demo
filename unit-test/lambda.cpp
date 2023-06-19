/*
   effective c++:
   - 注意避免空悬
   - lambda不捕获static，成员变量总是通过this指针捕获
*/
#include <stdio.h>
#include <vector>
int v_global = 1;
class Exp1 {
 public:
  Exp1(int v = 2) : v_member(v) {}
  auto func(int v_local1 = 3) {
    static int v_localStatic = 4;
    int v_local2 = 5;
    return [=,vm = v_member]() {
      printf("v_local1: %d, v_local2: %d\n", v_local1, v_local2);
      printf("v_localStatic: %d, v_member: %d,v_global: %d\n", v_localStatic,
             vm, v_global);
    };
  }

 private:
  int v_member;
};

// 测试三种捕获模式：不捕获/&捕获/=捕获
void test1(){
  Exp1 e1(222);
  auto f = e1.func(33);
  f();
}

class Move {
 public:
  Move(std::vector<double>&& data) : data_mem(std::move(data)) {}
  bool operator()() const {
    // bla bla
    return true;
  }
  std::vector<double> data_mem;
};
// 测试初始化捕获/c++11的两种写法：自己写类/bind函数
void test2() {
  std::vector<double> data{1, 2, 3};
  auto f = Move(std::move(data));
  // or
  auto f2 = std::bind(
      [](const std::vector<double>& data) {
        return true;
      },
      std::move(data));
  // or 去掉const
  auto fe = std::bind(
      [](std::vector<double>& data) mutable {
        return true;
      },
      std::move(data));
}

int main(){
  test2();
  return 0;
}
