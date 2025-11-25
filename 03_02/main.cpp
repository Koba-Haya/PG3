#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
class MyClass {
public:
    T1 data1;
    T2 data2;

    using MinType = std::common_type_t<T1, T2>;

    MyClass(T1 d1, T2 d2) : data1(d1), data2(d2) {}

    MinType Min() const {
        return (data1 < data2)
            ? static_cast<MinType>(data1)
            : static_cast<MinType>(data2);
    }
};

int main() {
    MyClass<int, int>     num1(10, 15);
    MyClass<int, float>   num2(5, 7.5f);
    MyClass<int, double>  num3(10, 4.5);
    MyClass<float, float> num4(15.3f, 7.5f);
    MyClass<float, double> num5(10.3f, 10.5);
    MyClass<double, double> num6(105.3, 207.5);

    auto min1 = num1.Min(); // 10
    auto min2 = num2.Min(); // 5
    auto min3 = num3.Min(); // 4.5
    auto min4 = num4.Min(); // 7.5f
    auto min5 = num5.Min(); // 10.3f
    auto min6 = num6.Min(); // 105.3

    std::cout << "Min of num1: " << min1 << '\n';
    std::cout << "Min of num2: " << min2 << '\n';
    std::cout << "Min of num3: " << min3 << '\n';
    std::cout << "Min of num4: " << min4 << '\n';
    std::cout << "Min of num5: " << min5 << '\n';
    std::cout << "Min of num6: " << min6 << '\n';

    return 0;
}
