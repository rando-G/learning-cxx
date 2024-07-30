#include "../exercise.h"

struct A {
    static int num_a; // 静态字段声明

    A() {
        ++num_a;
    }
    virtual ~A() { // 虚析构函数
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};
int A::num_a = 0; // 静态字段初始化

struct B final : public A {
    static int num_b; // 静态字段声明

    B() {
        ++num_b;
    }
    ~B() override { // 虚析构函数
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};
int B::num_b = 0; // 静态字段初始化

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    // ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;
    ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    // dynamic_cast 用于将基类指针安全地转换为派生类指针
    B &bb = dynamic_cast<B&>(*ab);
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    // TODO: ---- 以下代码不要修改，通过改正类定义解决编译问题 ----
    delete ab;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
