#include "LogSvc.hpp"

// Deklaracje funkcji modułów
void runPhysicsModule();
void runSimulationModule();

int main(int argc, const char *argv[]) {
    LogSvc::Init(argc, argv, "logs/app_main.log", loguru::Verbosity_MAX, 100);
    LogSvc::SetTerminalLogLevel(loguru::Verbosity_MAX);
    LogSvc::AddModuleLogFile("Physics", "logs/physics.log", loguru::Verbosity_ERROR);
    LogSvc::AddModuleLogFile("Simulation", "logs/simulation.log", loguru::Verbosity_INFO);
    LogSvc::AddModuleLogFile("MainModule", "logs/main.log", loguru::Verbosity_MAX);

    LOGSVC_INFO("MainModule", "Program główny uruchomiony. Nie zapomnij o ręczniku!");  
    LOGSVC_DEBUG("MainModule", "Odczyt argumentów startowych zakończony sukcesem. Możemy śmiało podążać dalej.");


    runPhysicsModule();
    runSimulationModule();

    LOGSVC_INFO("MainModule", "Program główny zakończony. Do zobaczenia w następnej symulacji kosmicznej!");

    return 0;
}
