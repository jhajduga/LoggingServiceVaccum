#include "Pizza.hpp"
#include "LogSvc.hpp"
#include <thread>
#include <chrono>

void Pizza::bake() {
    PIZZA_INFO("Starting pizza baking");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    PIZZA_DEBUG("Pizza is being baked at 230°C");
    PIZZA_INFO("Pizza is ready!");
}
