#ifndef Q3_H
#define Q3_H
#include <iostream>
#include <queue>
#include <string>
namespace q3 {
struct Flight {
    Flight(const std::string& _flight_number, const size_t& _duration, const size_t& _connections, const size_t& _connection_times, const size_t& _price)
        : flight_number { _flight_number }
        , duration { _duration }
        , connections { _connections }
        , connection_times { _connection_times }
        , price { _price }
    {
    }
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};
template <typename T>
void gather_flights(const T& filename)
{
    std::ifstream file;
    file.open(filename);
    std::string line, flight_number, duration, connections, connection_times, price;
    while (std::getline(file, line, '\n')) {
        flight_number = line.substr(line.find(':', 0), 6);
        duration = line.substr(line.find(":", 10));
        std::cout << flight_number << std::endl;
    }
}
}
#endif // Q3_H