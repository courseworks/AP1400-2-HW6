#ifndef Q2_H
#define Q2_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
namespace q2 {
struct Patient {
    Patient(const std::string& _name, const size_t& _age, const size_t& _smokes, const size_t& _area_q, const size_t& _alkhol)
        : name { _name }
        , age { _age }
        , smokes { _smokes }
        , area_q { _area_q }
        , alkhol { _alkhol }
    {
    }
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
template <typename T>
std::vector<Patient> read_file(const T& filename)
{
    std::vector<Patient> patients;
    std::ifstream file;
    std::string firstname, lastname;
    std::string age, smokes, area_q, alkhol;
    file.open("lung_cancer.csv");
    // just bring cursor of file to the third line
    getline(file, firstname, '\n');
    getline(file, firstname, '\n');
    while (!file.eof()) {
        std::getline(file, firstname, ',');
        firstname.erase(std::remove(firstname.begin(), firstname.end(), ' '), firstname.end());
        std::getline(file, lastname, ',');
        lastname.erase(std::remove(lastname.begin(), lastname.end(), ' '), lastname.end());
        std::string name1 { firstname + " " + lastname };
        // std::cout << name1 << std::endl;
        std::getline(file, age, ',');
        std::getline(file, smokes, ',');
        std::getline(file, area_q, ',');
        std::getline(file, alkhol, '\n');
        // std::cout << name1 << "|" << age << "|" << smokes << "|" << area_q << "|" << alkhol << std::endl;
        patients.push_back(Patient(name1, std::stoi(age), std::stoi(smokes), std::stoi(area_q), std::stoi(alkhol)));
    }
    return patients;
};
template <typename T>
void sort(T& patients)
{
    std::sort(patients.begin(), patients.end(), [](Patient& a, Patient& b) { return 3 * (a.age) + 5 * (a.smokes) + 2 * (a.area_q) + 4 * (a.alkhol) > 3 * (b.age) + 5 * (b.smokes) + 2 * (b.area_q) + 4 * (b.alkhol); });
}
}
#endif // Q2_H