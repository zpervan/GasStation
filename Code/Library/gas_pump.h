#pragma once

#include <atomic>
#include <mutex>

/// @brief Represent a single gas pump on the gas station on which cars can fill up.
struct GasPump
{
    // RAII
    explicit GasPump(std::size_t id) : id(id), fillUps(0){};
    GasPump() = delete;
    GasPump(const GasPump& gasPump) = delete;
    GasPump(GasPump&& gasPump) = delete;
    GasPump& operator=(const GasPump& gasPump) = delete;
    GasPump& operator=(GasPump&& gasPump) = delete;

    // Data members
    std::size_t id;
    std::size_t fillUps;
    std::mutex fillUpMutex;
};
