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
        // std::string a { "abcdi - fgplvvcx12:3qw456 " };
        // std::stringstream b {a};
        // std::string c,d,e;
        // b>>c;
        // b.ignore(1,'-');
        // b.ignore(15,':');
        // b>>d;
        // std::cout <<c <<"   "<<d<<std::endl;
        // std::cout << *std::remove(a.begin(), a.end(), ' ') << std::endl;
        // std::cout << a << std::endl;
        // a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
        // auto flights = q3::gather_flights("flights.txt");
        // std::vector<size_t> flight_numbers;
        std::string a{"1h,3h50min"};
        std::cout<<q3::timetomin(a)<<std::endl;
        // while (!flights.empty()) {
        //     // flight_numbers.push_back(q3::timetomin(flights.top().connection_times));
        //     flights.pop();
        // }

        //  q3::gather_flights("flights.txt");

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