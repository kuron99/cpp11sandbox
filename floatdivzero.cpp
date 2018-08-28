// fenv is not approved standard in C++11, but clang/g++ on x86_64 seems working fine
#include <cfenv>
#include <iostream>
#include <cmath>
#include <limits>

#pragma STDC FENV_ACCESS ON  // warned as gcc, clang are not supporting this

volatile double zero = 0.0;  // volatile not needed where FENV_ACCESS is supported
volatile double one = 1.0;  // volatile not needed where FENV_ACCESS is supported

int main() {
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "1.0/0.0 = " << 1.0 / zero << '\n';
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "division by zero reported\n";
    } else {
        std::cout << "divsion by zero not reported\n";
    }

    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "1.0/10 = " << one / 10 << '\n';
    if (std::fetestexcept(FE_INEXACT)) {
        std::cout << "inexact result reported\n";
    } else {
        std::cout << "inexact result not reported\n";
    }

    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "sqrt(-1) = " << std::sqrt(-1) << '\n';
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "invalid result reported\n";
    } else {
        std::cout << "invalid result not reported\n";
    }

    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "infinity() = " << std::numeric_limits<double>::infinity() << '\n';
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "division by zero reported\n";
    } else {
        std::cout << "divsion by zero not reported\n";
    }
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "nan() = " << std::nan("") << '\n';
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "invalid result reported\n";
    } else {
        std::cout << "invalid result not reported\n";
    }
}