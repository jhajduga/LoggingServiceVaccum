#include "LogSvc.hpp"
#include "simulation.hpp"

void runSimulationModule() {

    LOG_INFO("Symulacja krok 1: Wszystko pod kontrolą. Ale to dopiero początek...");
    LOG_WARNING("Krok 42: Napotkano niestabilność rzeczywistości symulacyjnej. Douglas Adams miał rację!");
    LOG_DEBUG("Tworzenie nowej iteracji: rzeczywistość wirtualna jest bardziej kapryśna niż Matrix.");
    // LOG_FATAL("Krytyczny błąd! Czerwona pigułka zażyta, ale kod nadal nie działa."); // Przykładowy błąd krytyczny - przerwanie aplikacji.
}
