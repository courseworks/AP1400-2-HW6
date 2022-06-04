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
        std::string a { "abcdfgplvvcx12 3456" };
        // std::cout << *std::remove(a.begin(), a.end(), ' ') << std::endl;
        // std::cout << a << std::endl;
        // a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
        // std::cout << a << std::endl;
        q3::gather_flights("flights.txt");
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