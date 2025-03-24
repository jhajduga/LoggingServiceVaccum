#include "LogSvc.hpp"
#include "Pizza.hpp"
#include "Physic.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, const char *argv[]) {
    LogSvc::Init(argc, argv, "initial.log", loguru::Verbosity_MAX);
    LogSvc::SetTerminalLogLevel(loguru::Verbosity_MAX);

    std::string output_dir = "output/session_1";
    std::filesystem::create_directories(output_dir + "/logs");

    LogSvc::ReconfigureMainLog(output_dir + "/logs/main.log");
    LogSvc::AddModuleLogFile("Pizza", output_dir + "/logs/pizza.log", loguru::Verbosity_MAX);
    LogSvc::AddModuleLogFile("Physic", output_dir + "/logs/physic.log", loguru::Verbosity_INFO);

    LOGSVC_INFO("Main", "Application started");

    Pizza pizza;
    pizza.bake();

    Physic physic;
    physic.run_experiment();


    // Callback, który wypisuje alerty (warning i niżej) na stderr
    loguru::add_callback(
        "simple_alert_callback",
        [](void* user_data, const loguru::Message& message) {
            if (message.verbosity <= loguru::Verbosity_WARNING)
                std::cout << "[ALERT CALLBACK] " << message.message << "\n";
        },
        nullptr,
        loguru::Verbosity_WARNING
    );


    LOGSVC_INFO("Main", "Application finished");

    return 0;
}
