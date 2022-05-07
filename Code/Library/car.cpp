#include "car.h"

#include <iostream>
#include <mutex>

#include "constants.h"
#include "gas_station.h"

Car::Car(std::size_t id, GasStation* gasStation) : mId(id), mGasStation(gasStation) {}

void Car::fillUp()
{
    auto simulationStart = std::chrono::steady_clock::now();
    double elapsedSimulationTime{0.0};

    while (elapsedSimulationTime < Constants::SIMULATION_DURATION)
    {
        if (mIsFilledUp)
        {
            mIsFilledUp = false;
        }

        if (mGasStation->canFillUp(mId))
        {
            // Check which gas pump is free and initiate the fill up.
            // It can only fill up on ONE gas pump at any given time.
            for (auto& gasPump : mGasStation->getGasPumps())
            {
                if (gasPump->fillUpMutex.try_lock() && !mIsFilledUp)
                {
                    // After the car has initiated the fill up, remove it from queue
                    mGasStation->removeCarFromQueue();
                    std::this_thread::sleep_for(std::chrono::milliseconds(Constants::FILLUP_DURATION_MS));
                    gasPump->fillUps++;
                    mFillUps++;
                    // After the car has been filled up, add it to the back of the queue and wait in line
                    mGasStation->addCarToLine(mId);
                    gasPump->fillUpMutex.unlock();
                    mIsFilledUp = true;
                }
            }
        }

        elapsedSimulationTime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - simulationStart).count();
    }
}

std::size_t Car::getId() const
{
    return mId;
}

std::size_t Car::getFillUps() const
{
    return mFillUps;
}
