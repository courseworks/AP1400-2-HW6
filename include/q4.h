#ifndef Q4_H
#define Q4_H

#include <iostream>
#include <numeric>

namespace q4 {

struct Vector2D {
    Vector2D(const double& _x, const double& _y)
        : x(_x)
        , y(_y)
    {
    }
    double x {};
    double y {};
};

struct Sensor {
    Sensor(const Vector2D& _pos, const double& _accuracy)
        : pos(_pos)
        , accuracy(_accuracy)
    {
    }

    Vector2D pos;
    double accuracy;
};

inline Vector2D kalman_filter(std::vector<Sensor> sensors)
{
    double sum_accuracies {
        std::accumulate(sensors.begin(),
            sensors.end(),
            0.0,
            [](const double& sum, const Sensor& sensor) {
                return sum + sensor.accuracy;
            })
    };

    double filteredx {
        std::accumulate(sensors.begin(), sensors.end(), 0.0,
            [](double sum, Sensor& sensor) {
                return sum + sensor.pos.x * sensor.accuracy;
            })
        / sum_accuracies
    };

    double filteredy {
        std::accumulate(sensors.begin(), sensors.end(), 0.0,
            [](double sum, Sensor& sensor) {
                return sum + sensor.pos.y * sensor.accuracy;
            })
        / sum_accuracies
    };

    return Vector2D { filteredx, filteredy };
}

}

#endif // Q4_H