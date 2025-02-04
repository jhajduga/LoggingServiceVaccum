#include "LogSvc.hpp"
#include <cassert>

int main() {
    LogSvc::Init(0, nullptr, "logs/test_log.log", loguru::Verbosity_MAX, 100);
    LogSvc::SetTerminalLogLevel(loguru::Verbosity_INFO);

    LOGSVC_INFO("TestModule", "Test logowania.");
    LOGSVC_DEBUG("TestModule", "Test debug.");
    LOGSVC_ERROR("TestModule", "Test błędu.");

    // Możesz dodać więcej testów sprawdzających działanie loggera
    assert(true);  // Przykładowy test
    return 0;
}
