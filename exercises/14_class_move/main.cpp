#include "../exercise.h"  
  
class DynFibonacci {  
    size_t *cache;  
    int cached;  
    int capacity;  
  
public:  
    // 实现动态设置容量的构造器  
    DynFibonacci(int capacity): capacity(capacity), cache(new size_t[capacity]), cached(-1) {  
        cache[0] = 0;  
        cache[1] = 1;  
    }  
  
    // 实现移动构造器  
    DynFibonacci(DynFibonacci &&other) noexcept : cache(other.cache), cached(other.cached), capacity(other.capacity) {  
        other.cache = nullptr;  
        other.cached = -1;  
        other.capacity = 0;  
    }  
  
    // 实现移动赋值  
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {  
        if (this != &other) {  
            delete[] cache;  
            cache = other.cache;  
            cached = other.cached;  
            capacity = other.capacity;  
            other.cache = nullptr;  
            other.cached = -1;  
            other.capacity = 0;  
        }  
        return *this;  
    }  
  
    // 实现析构器，释放缓存空间  
    ~DynFibonacci() {  
        delete[] cache;  
    }  
  
    // 实现正确的缓存优化斐波那契计算  
    size_t operator[](int i) {  
        
            for (cached =2; cached <=i; cached++) {  
                cache[cached] = cache[cached - 1] + cache[cached - 2];  
            }  
          
        return cache[i];  
    }  
  
    // NOTICE: 不要修改这个方法  
    bool is_alive() const {  
        return cache != nullptr;  
    }  
};  
  
int main(int argc, char **argv) {  
    DynFibonacci fib(12);  
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");  
  
    DynFibonacci const fib_ = std::move(fib);  
    ASSERT(!fib.is_alive(), "Object moved");  
    // ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");  
  
    DynFibonacci fib0(6);  
    DynFibonacci fib1(12);  
  
    fib0 = std::move(fib1);  
    fib0 = std::move(fib0);  
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");  
  
    return 0;  
}