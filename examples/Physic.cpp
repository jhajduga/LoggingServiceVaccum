#include "Physic.hpp"
#include "LogSvc.hpp"
#include <thread>
#include <chrono>

void Physic::run_experiment() {
    PHYSIC_INFO("Experiment initialization...");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    PHYSIC_WARN("Strange particle detected!");
    PHYSIC_INFO("Experiment finished successfully.");
}
