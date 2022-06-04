#include <gtest/gtest.h>
#include <iostream>

#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
     //   auto min1 = q1::gradient_descent(0.01, 0.1, cos);
       auto min = q1::gradient_descent(0.01, 0.01, [](double a){return sin(a)+cos(a);});
        std::cout<<min<<std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}