#include "../exercise.h"

// 函数模板
template<class k,class v>
k plus(k a, v b) {
    return a + b;
}

// 辅助函数，用于比较两个浮点数是否足够接近
bool nearly_equal(double x, double y, double epsilon = 1e-9) {
    return std::abs(x - y) <= epsilon;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    
    // 使用辅助函数来比较浮点数
    ASSERT(nearly_equal(plus(0.1, 0.2), 0.3), "How to make this pass?");
    
    return 0;
}
