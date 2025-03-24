#pragma once
#include "LogSvc.hpp"

#define PIZZA_DEBUG(msg, ...) LOGSVC_DEBUG("Pizza", msg, ##__VA_ARGS__)
#define PIZZA_INFO(msg, ...) LOGSVC_INFO("Pizza", msg, ##__VA_ARGS__)
#define PIZZA_WARN(msg, ...) LOGSVC_WARNING("Pizza", msg, ##__VA_ARGS__)
#define PIZZA_ERROR(msg, ...) LOGSVC_ERROR("Pizza", msg, ##__VA_ARGS__)

class Pizza {
public:
    void bake();
};
