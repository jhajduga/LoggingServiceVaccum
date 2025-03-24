#pragma once
#include "LogSvc.hpp"

#define PHYSIC_DEBUG(msg, ...) LOGSVC_DEBUG("Physic", msg, ##__VA_ARGS__)
#define PHYSIC_INFO(msg, ...) LOGSVC_INFO("Physic", msg, ##__VA_ARGS__)
#define PHYSIC_WARN(msg, ...) LOGSVC_WARNING("Physic", msg, ##__VA_ARGS__)
#define PHYSIC_ERROR(msg, ...) LOGSVC_ERROR("Physic", msg, ##__VA_ARGS__)

class Physic {
public:
    void run_experiment();
};
