#include "LogSvc.hpp"


#define DEFAULT_MODULE "Simulation"

#define LOG_DEBUG(msg, ...)   LOGSVC_DEBUG(DEFAULT_MODULE, msg, ##__VA_ARGS__)
#define LOG_INFO(msg, ...)    LOGSVC_INFO(DEFAULT_MODULE, msg, ##__VA_ARGS__)
#define LOG_WARNING(msg, ...) LOGSVC_WARNING(DEFAULT_MODULE, msg, ##__VA_ARGS__)
#define LOG_ERROR(msg, ...)   LOGSVC_ERROR(DEFAULT_MODULE, msg, ##__VA_ARGS__)
#define LOG_FATAL(msg, ...)   LOGSVC_FATAL(DEFAULT_MODULE, msg, ##__VA_ARGS__)