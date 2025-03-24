# 🍕🎩 LogSvc Standalone Logging Service

## 🎉 Introduction

Welcome to **LogSvc**—your ultra-flexible logging service built upon the robust [Loguru](https://github.com/emilk/loguru) library! Originally crafted for handling complex scientific computations, LogSvc is now ready to gracefully handle logging tasks in any C++ application.

---

## 🚀 Features

- **Bulletproof Thread Safety:** Protect your logs from race conditions using state-of-the-art mutex locks.
- **Module-Specific Log Files:** Keep "Physics" and "PizzaOrders" logs apart, because mixing them isn't always helpful.
- **Dynamic Verbosity:** Adjust logging verbosity dynamically without restarting or recompiling your application.
- **Custom Callbacks:** Automate advanced reactions—send emails, trigger scripts, or perform any custom action!

---

## 🔧 Dependencies

Ensure the following dependencies are properly installed:

- **pthread** (POSIX threads support)
- **dl** (Dynamic linking library)
- **fmtlib** (C++ formatting library)

---

## 🛠️ Setup and Initialization

Initialize LogSvc at the beginning of your application's lifecycle:

```cpp
#include "LogSvc.hpp"

int main(int argc, char* argv[]) {
    LogSvc::Init(argc, argv, "logs/my_cool_app.log", loguru::Verbosity_INFO, 100);
    return 0;
}
```

Parameters:
- `argc, argv`: Pass through from your `main()`.
- `default_log_file`: Default log file for your application.
- `verbosity`: Logging verbosity (`loguru::Verbosity_INFO`, `loguru::Verbosity_ERROR`, etc.).
- `flush_interval_ms`: Frequency for flushing logs to disk.

---

## 📂 Module-Specific Logs

Clearly separate logs per module:

```cpp
LogSvc::AddModuleLogFile("Physics", "logs/physics.log", loguru::Verbosity_WARNING);
LogSvc::AddModuleLogFile("PizzaOrders", "logs/pizza.log", loguru::Verbosity_INFO);
```

---

## 📝 Logging Examples

Handy macros for enjoyable logging:

```cpp
LOGSVC_INFO("PizzaOrders", "Order #{} is out for delivery!", 42);
LOGSVC_WARNING("Physics", "Quantum instability detected. Reality may break.");
LOGSVC_ERROR("PizzaOrders", "Customer address not found. Deploying pizza drone anyway.");
```

Define local macros to simplify your logs:

```cpp
#define PHYSICS_LOG(msg, ...) LOGSVC_INFO("Physics", msg, ##__VA_ARGS__)
#define PIZZA_LOG(msg, ...) LOGSVC_INFO("PizzaOrders", msg, ##__VA_ARGS__)

PHYSICS_LOG("Black hole simulation complete. No planets harmed.");
PIZZA_LOG("Pepperoni shortage alert at store #{}!", store_id);
```

---

## 🎯 Dynamic Verbosity Adjustment

Adjust logging detail on-the-fly:

```cpp
LogSvc::SetTerminalLogLevel(loguru::Verbosity_ERROR);
```

---

## ⚙️ Advanced Custom Callbacks

Use callbacks for sophisticated logging behaviors:

```cpp
loguru::add_callback(
    "epic_completion_email",
    [](void*, const loguru::Message& msg) {
        if (msg.message.find("Mission accomplished") != std::string::npos) {
            triggerPythonEmailScript("simulation_completed.py", msg.message);
        }
    },
    nullptr,
    loguru::Verbosity_INFO
);
```

Send alerts via a network socket:

```cpp
loguru::add_callback(
    "network_alert",
    [](void*, const loguru::Message& msg) {
        if (msg.verbosity <= loguru::Verbosity_WARNING) {
            sendAlertToServer("192.168.1.42", 8080, msg.message);
        }
    },
    nullptr,
    loguru::Verbosity_WARNING
);
```

---

## 🗃️ Example Log Outputs

**logs/pizza.log:**
```
2025-04-01 12:34:56.789 ( 42.000s) [delivery_thread] pizza.cpp:99 INFO| Order #42 delivered! Pizza's warm, success is tasty.
```

**logs/physics.log:**
```
2025-04-01 12:36:00.007 (105.218s) [main thread] physics.cpp:123 WARN| Quantum instability detected. Reality status: questionable.
```

**Terminal Log:**
```
2025-04-01 12:40:00.001 (123.456s) [main thread] main.cpp:314 ERR| Pizza drone crashed into quantum singularity. Combining logs recommended.
```

---

## 📋 Quick Reference

| Function                     | Description                                                      |
|------------------------------|------------------------------------------------------------------|
| `Init()`                     | Initialize the global logging service.                           |
| `AddModuleLogFile()`         | Assigns a log file to a specific module.                         |
| `SetTerminalLogLevel()`      | Adjust verbosity level for terminal logs dynamically.            |
| `LOGSVC_INFO/WARNING/ERROR`  | Handy macros for standardized logging at various severity levels.|
| `loguru::add_callback()`     | Add custom callbacks for advanced logging behavior.              |

---

## 📦 Project Structure

```
LogSvcProject
├── externals
│   ├── loguru.cpp
│   └── loguru.hpp
├── src
│   ├── LogSvc.cpp
│   └── LogSvc.hpp
├── examples
│   ├── Main.cpp
│   ├── Pizza.cpp
│   ├── Pizza.hpp
│   ├── Physic.cpp
│   └── Physic.hpp
└── CMakeLists.txt
```

## 🛠️ CMake Integration

Integrate Loguru in your `CMakeLists.txt`:

```cmake
add_library(loguru STATIC loguru.cpp)
target_include_directories(loguru PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(loguru PUBLIC LOGURU_USE_FMTLIB=1)
target_link_libraries(loguru PUBLIC pthread dl fmt)
```

Include Loguru in your code:

```cpp
#include "loguru.hpp"
```

Initialize Loguru:

```cpp
loguru::init(argc, argv);
```

Link Loguru:

```cmake
target_link_libraries(MyApp PRIVATE loguru)
```

---

🎉 **Happy Logging!** 🚀