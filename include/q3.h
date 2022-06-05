#ifndef Q3_H
#define Q3_H
#include <iostream>
#include <queue>
#include <regex>
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

static size_t timetomin(std::string t)
{
    std::regex pattern(R"((\d+)\h(\d+)?\m?\,?)");
    std::smatch match;
    size_t sum { 0 };
    while (std::regex_search(t, match, pattern)) {
        sum += std::stoi(match[1]) * 60;
        if (static_cast<std::string>(match[2]).empty()) {
            sum += 0;
        } else {
            sum += std::stoi(match[2]);
        }
        t = match.suffix().str();
        // std::cout << sum << " ->" << t << std::endl;
    }
    return sum;
}

static auto gather_flights(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);
    auto comp {
        [](auto& a, auto& b) { return (a.duration + a.connection_times + 3 * (a.price)) > (b.duration + b.connection_times + 3 * (b.price)); }
    };
    std::priority_queue<Flight, std::vector<Flight>, decltype(comp)> flights { comp };
    std::string flight_number, duration, connections, connection_times, price;
    while (file.good()) {
        file.ignore(20, ':');
        std::getline(file, flight_number, ' ');
        file.ignore(20, ':');
        std::getline(file, duration, ' ');
        file.ignore(20, ':');
        std::getline(file, connections, ' ');
        file.ignore(20, ':');
        std::getline(file, connection_times, ' ');
        file.ignore(20, ':');
        std::getline(file, price, '\n');
        ;
        std::cout <<flight_number <<" "<< duration <<" "<<connections << " "<<timetomin(connection_times) << " "<<price <<std::endl;
        flights.push(Flight(flight_number, timetomin(duration), std::stoi(connections), timetomin(connection_times), std::stoi(price)));
    }
    return flights;
}

//---------not optimized algorithem timetomin---------------
// template <typename T>
// size_t timetomin(T t)
// {
//     auto subt { t };
//     size_t pos { 0 }, pos_h { 0 }, pos_m { 0 }, sum { 0 };
//     while (!(t.empty())) {
//         // std::cout << t << std::endl;
//         if ((pos = t.find(','))!=std::string::npos) {
//             subt = t.substr(0, pos + 1);
//             std::cout << subt << std::endl;

//             if ((pos_h = subt.find('h'))!=std::string::npos) {
//                 sum += (60 * std::stoi(subt.substr(0, pos_h)));
//                 subt.erase(0, pos_h + 1);
//                 std::cout << subt << std::endl;
//             }
//             if ((pos_m = subt.find('m'))!=std::string::npos) {
//                 sum += std::stoi(subt.substr(0, pos_m));
//                 subt.erase(0, pos_m + 1);
//                 std::cout << subt << std::endl;
//             }
//             t.erase(0, pos + 1);
//         } else {
//             // std::cout<<sum<<"beforelast "<<std::endl;
//             if ((pos_h = t.find('h'))!=std::string::npos) {
//                 sum += (60 * std::stoi(t.substr(0, pos_h)));
//                 t.erase(0, pos_h + 1);
//                 std::cout << t << std::endl;
//             }
//             if ((pos_m = t.find('m'))!=std::string::npos) {
//                 sum += std::stoi(t.substr(0, pos_m));
//                 t.erase(0, pos_m + 1);
//                 std::cout << t << std::endl;
//             }
//         }
//     }
//     return sum;
// }

}
#endif // Q3_H