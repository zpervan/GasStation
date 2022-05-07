#pragma once

#include <cstddef>

class GasStation;

class Car
{
public:
    // RAII
    Car(std::size_t id, GasStation* gasStation);
    Car() = default;
    Car(const Car& car) = default;
    Car(Car&& car) = default;
    Car& operator=(const Car& car) = default;
    Car& operator=(Car&& car) = default;

    /// @brief Initiates the fill up procedure if it's next in line and a gas pump is free.
    void fillUp();

    // Getters
    std::size_t getId() const;
    std::size_t getFillUps() const;

private:
    std::size_t mId{0};
    std::size_t mFillUps{0};
    GasStation* mGasStation{nullptr};
    bool mIsFilledUp{false};
};
