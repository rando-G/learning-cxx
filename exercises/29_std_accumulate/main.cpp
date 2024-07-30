#include "../exercise.h"
#include <numeric>
#include <cstddef> // 用于 std::size_t

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // 计算张量的总字节数
    int size = std::accumulate(shape, shape + sizeof(shape)/sizeof(shape[0]), 
                               1, std::multiplies<int>());

    size *= sizeof(DataType);

    // 检查计算结果是否正确
    ASSERT(size == 602112, "1x3x224x224 float tensor = 602112 bytes");
    return 0;
}
