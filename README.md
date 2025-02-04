# LogSvc Logging Service

## ✨ **Podstawowe funkcje loggera LogSvc**
LogSvc to rozbudowany serwis logowania oparty na bibliotece [Loguru](https://github.com/emilk/loguru). Pozwala na elastyczne zarządzanie logami dla różnych modułów aplikacji, łącząc funkcje takie jak zapisywanie do oddzielnych plików dla modułów, zarządzanie poziomami logów i automatyczne flushowanie.

---

## 📁 **Instalacja i konfiguracja**

### **1. Inicjalizacja loggera**
```cpp
#include "LogSvc.hpp"

int main(int argc, char* argv[]) {
    LogSvc::Init(argc, argv, "logs/app.log", loguru::Verbosity_INFO, 100);
    return 0;
}
```
- **Init()** – inicjuje logger, ustawia domyślny plik logowania i poziom szczegółowości.
- Parametry:
  - `argc, argv` – argumenty przekazane do programu.
  - `default_log_file` – ścieżka do pliku logów.
  - `verbosity` – poziom logowania (np. `loguru::Verbosity_INFO`).
  - `flush_interval_ms` – czas w milisekundach pomiędzy flushowaniem logów.

---

### **2. Dodawanie logów dla modułów**

Każdy moduł może posiadać własny plik logów, co pozwala na rozdzielenie informacji z różnych części aplikacji.

```cpp
LogSvc::AddModuleLogFile("Physics", "logs/physics.log", loguru::Verbosity_ERROR);
LogSvc::AddModuleLogFile("Simulation", "logs/simulation.log", loguru::Verbosity_INFO);
```
- **AddModuleLogFile()** – dodaje nowy plik logów dla określonego modułu.
- Parametry:
  - `module` – nazwa modułu.
  - `log_file` – ścieżka do pliku logów dla modułu (obecnie ścieżka względa do root'a projektu).
  - `verbosity` – poziom szczegółowości logowania (tylko logi niższej szczegółowości (wyższej ważności) zostaną zapisane w pliku).

---

## 🔧 **Używanie funkcji logowania**

LogSvc udostępnia szereg funkcji logowania dla różnych poziomów ważności komunikatów.

```cpp
LOGSVC_INFO("Physics", "Starting physics calculations...");
LOGSVC_WARNING("Simulation", "Simulation might be unstable at step {}", 42);
LOGSVC_ERROR("UI", "UI encountered a fatal error!");
```
- Makra logowania:
  - `LOGSVC_DEBUG`, `LOGSVC_INFO`, `LOGSVC_WARNING`, `LOGSVC_ERROR`, `LOGSVC_FATAL`
- Każde makro automatycznie wstawia nazwę pliku, numer linii i formatuje wiadomość.

---

## 🔧 **Nadpisywanie funkcji logowania**

LogSvc udostępnia możliwość kreacji lokalnego logera za pomocą definiowania lokalnych makr.

```cpp
#define DEFAULT_MODULE "Simulation"

#define LOG_DEBUG(msg, ...)   LOGSVC_DEBUG(DEFAULT_MODULE, msg, ##__VA_ARGS__)
#define LOG_INFO(msg, ...)    LOGSVC_INFO(DEFAULT_MODULE, msg, ##__VA_ARGS__)
...
...
...
```
- Lokalne makra logowania:
  - Umożliwiają flushowanie do lokalnego sink'a predefiniowanego dla modułu (tu np dla modułu "Simulation")

---

## 🌐 **Przykładowe logi**
### **Plik logs/physics.log:**
```
2025-02-04 14:00:01.123 (  0.001s) [main thread] physics.cpp:42      INFO| Starting physics calculations...
```
### **Plik logs/simulation.log:**
```
2025-02-04 14:01:15.567 ( 14.444s) [worker-thread] simulation.cpp:108 WARN| Simulation might be unstable at step 42
```
### **Wywołanie LOGSVC_FATAL:**
```
Stack trace:
4       0x5557ddf531de ./examples/example_app(+0x61de) [0x5557ddf531de]
3       0x7f6650df5640 __libc_start_main + 128
2       0x7f6650df5590 /lib64/libc.so.6(+0x29590) [0x7f6650df5590]
1       0x5557ddf52a8d ./examples/example_app(+0x5a8d) [0x5557ddf52a8d]
0       0x5557ddf53b84 ./examples/example_app(+0x6b84) [0x5557ddf53b84]
2025-02-04 16:21:26.456 (   0.000s) [main thread     ]         simulation.cpp:9     FATL| [Simulation] Krytyczny błąd! Czerwona pigułka zażyta, ale kod nadal nie działa.
```
### **Terminal Log Example:**
```
date       time         ( uptime  ) [ thread name/id ]                   file:line     v| 
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             loguru.cpp:659   INFO| arguments: ./examples/example_app
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             loguru.cpp:662   INFO| Current dir: /home/jackie/work/experimental/LoggingServiceVaccum/build
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             loguru.cpp:664   INFO| stderr verbosity: 0
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             loguru.cpp:665   INFO| -----------------------------------
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             loguru.cpp:841   INFO| Logging to '/home/jackie/work/experimental/LoggingServiceVaccum/logs/app_main.log', mode: 'a', verbosity: 9
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]               main.cpp:14    INFO| [MainModule] Program główny uruchomiony. Nie zapomnij o ręczniku!
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]               main.cpp:15       9| [MainModule] Odczyt argumentów startowych zakończony sukcesem. Możemy śmiało podążać dalej.
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             physic.cpp:4     INFO| [Physics] Uruchamianie modułu fizyki. Przygotowujemy protomolekuły...
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             physic.cpp:5     WARN| [Physics] Eksperyment z antymaterią w toku. Unikać zbliżania się do osi Y.
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]             physic.cpp:6      ERR| [Physics] Kwantowy wzór chaosu przekroczył limit stabilności! Podajcie jabłka Newtonowi.
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]         simulation.cpp:6     INFO| [Simulation] Symulacja krok 1: Wszystko pod kontrolą. Ale to dopiero początek...
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]         simulation.cpp:7     WARN| [Simulation] Krok 42: Napotkano niestabilność rzeczywistości symulacyjnej. Douglas Adams miał rację!
2025-02-04 16:21:49.710 (   0.000s) [main thread     ]         simulation.cpp:8        9| [Simulation] Tworzenie nowej iteracji: rzeczywistość wirtualna jest bardziej kapryśna niż Matrix.
2025-02-04 16:21:49.711 (   0.000s) [main thread     ]               main.cpp:21    INFO| [MainModule] Program główny zakończony. Do zobaczenia w następnej symulacji kosmicznej!
2025-02-04 16:21:49.711 (   0.000s) [main thread     ]             loguru.cpp:538   INFO| atexit
```



---




## 🔒 **Zarządzanie poziomem logowania**
Poziom logowania dla terminala można zmienić dynamicznie za pomocą funkcji:

```cpp
LogSvc::SetTerminalLogLevel(loguru::Verbosity_ERROR);
```
- **SetTerminalLogLevel()** – ustawia minimalny poziom komunikatów wyświetlanych na terminalu.

---

## 🔄 **Callbacki i obsługa niestandardowych zdarzeń**
LogSvc umożliwia również dodawanie niestandardowych callbacków do przetwarzania logów.

```cpp
loguru::add_callback(
    "custom_logger",
    [](void* user_data, const loguru::Message& message) {
        std::cerr << "[CUSTOM] " << message.message << std::endl;
    },
    nullptr,
    loguru::Verbosity_INFO
);
```
- **add_callback()** – dodaje funkcję obsługi dla logów.

---

## 📈 **Podsumowanie funkcji**
| Funkcja                        | Opis                              |
|-------------------------------|-----------------------------------|
| `Init()`                       | Inicjalizacja loggera             |
| `AddModuleLogFile()`           | Dodanie pliku logów dla modułu   |
| `SetTerminalLogLevel()`        | Ustawienie poziomu logowania      |
| `LogDebug()`, `LogInfo()` itd. | Logowanie komunikatów            |
| `add_callback()`               | Dodanie callbacka do logów        |

---

✨ **LogSvc** łączy elastyczność z wysoką wydajnością, dzięki czemu idealnie nadaje się do dużych projektów, takich jak symulacje w Geant4 czy aplikacje HPC.

