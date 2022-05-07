#include "gas_station.h"

#include <iostream>
#include <mutex>

GasStation::GasStation(std::size_t numberOfGasPumps, std::size_t numberOfCars)
{
    createGasPumps(numberOfGasPumps);
    createCars(numberOfCars);
}

void GasStation::simulate()
{
    for (auto& car : mCars)
    {
        mThreads.emplace_back(std::thread(&Car::fillUp, &car));
    }

    // Wait for all threads to finish
    for (auto& thread : mThreads)
    {
        thread.join();
    }

    printStatistics();
}

bool GasStation::canFillUp(std::size_t carId)
{
    return mCarQueue.front() == carId;
}

void GasStation::addCarToLine(std::size_t carId)
{
    std::mutex carLineMutex;

    while (!carLineMutex.try_lock());
    mCarQueue.push(carId);
    carLineMutex.unlock();
}

void GasStation::removeCarFromQueue()
{
    std::mutex carLineMutex;

    while (!carLineMutex.try_lock());
    mCarQueue.pop();
    carLineMutex.unlock();
}

std::vector<std::unique_ptr<GasPump>>& GasStation::getGasPumps()
{
    return mGasPumps;
}

void GasStation::createGasPumps(std::size_t numberOfGasPumps)
{
    std::cout << "Creating " << numberOfGasPumps << " gas pumps." << std::endl;
    mGasPumps.reserve(numberOfGasPumps);

    for (std::size_t i{0}; i < numberOfGasPumps; ++i)
    {
        mGasPumps.emplace_back(std::make_unique<GasPump>(i));
    }
}

void GasStation::createCars(std::size_t numberOfCars)
{
    std::cout << "Creating " << numberOfCars << " cars and assigning them to the fill up queue." << std::endl;

    mCars.reserve(numberOfCars);

    for (std::size_t i{0}; i < numberOfCars; ++i)
    {
        mCars.emplace_back(i, this);
        mCarQueue.push(i);
    }
}

void GasStation::printStatistics()
{
    for (const auto& car : mCars)
    {
        std::cout << "Car with ID " << car.getId() << " has " << car.getFillUps() << " fill ups.\n";
    }

    for (const auto& gasPump : mGasPumps)
    {
        std::cout << "Gas pump with ID " << gasPump->id << " has " << gasPump->fillUps << " fill ups.\n";
    }
}
