#ifndef Q1_H
#define Q1_H
#include <cmath>
#include <iostream>
namespace q1 {
template <typename T, typename Func>
const T& gradient_descent(const T& intit_val, const T& step_size, Func func = Func {})
{
    auto h = step_size * 1e-3; // accuracy limits to step_size/1000
    auto gradient { [&func, &h](const T& a) { return (func(a + h) - func(a)) / h; } };
    T* alpha { const_cast<T*>(&intit_val) };
    while (abs(gradient(*alpha)) > h) {
        *alpha = *alpha - step_size * gradient(*alpha);
    }
    return *alpha;
}
}

#endif