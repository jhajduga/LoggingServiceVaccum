# LogSvc Standalone Logging Service

## 🎩 Introduction

Welcome to **LogSvc**—your friendly, ultra-flexible logging service built upon the [Loguru](https://github.com/emilk/loguru) library! Originally conceived to handle complex scientific computations, LogSvc now proudly stands on its own feet, ready to gracefully handle logging tasks in any C++ application you throw at it.

---

## 🚀 Features

- **Bulletproof Thread Safety:** Safeguards your logs from the dreaded race conditions with state-of-the-art mutex locks.
- **Module-Specific Log Files:** Each module can have its own personal log—because mixing "Physics" and "PizzaOrders" logs isn't always helpful.
- **Dynamic Verbosity:** Change your logging detail on-the-fly without restarting or recompiling your app.
- **Custom Callbacks:** Go beyond basic logging with custom reactions—send emails, trigger scripts, or annoy your colleagues automatically!

---

## 🛠️ Setup and Initialization

Kick off LogSvc right at the start of your application's journey:

```cpp
#include "LogSvc.hpp"

int main(int argc, char* argv[]) {
    LogSvc::Init(argc, argv, "logs/my_cool_app.log", loguru::Verbosity_INFO, 100);
    return 0;
}
```

Parameters:
- `argc, argv`: Just pass them along!
- `default_log_file`: Default log file for your awesome application.
- `verbosity`: Set how chatty you want your logs (`loguru::Verbosity_INFO`, `loguru::Verbosity_ERROR`, etc.).
- `flush_interval_ms`: How often logs get safely flushed to disk (in milliseconds).

---

## 📂 Module-Specific Logs

Separate your logs by module for clarity:

```cpp
LogSvc::AddModuleLogFile("Physics", "logs/physics.log", loguru::Verbosity_WARNING);
LogSvc::AddModuleLogFile("PizzaOrders", "logs/pizza.log", loguru::Verbosity_INFO);
```

---

## 📝 Usage Examples (with Humor)

Use these handy macros to make your logging a joy:

```cpp
LOGSVC_INFO("PizzaOrders", "Order #{} is out for delivery!", 42);
LOGSVC_WARNING("Physics", "Quantum instability detected. Reality may break.");
LOGSVC_ERROR("PizzaOrders", "Customer address not found. Deploying pizza drone anyway.");
```

Define local macros to streamline your logging even more:

```cpp
#define PHYSICS_LOG(msg, ...) LOGSVC_INFO("Physics", msg, ##__VA_ARGS__)
#define PIZZA_LOG(msg, ...) LOGSVC_INFO("PizzaOrders", msg, ##__VA_ARGS__)

PHYSICS_LOG("Black hole simulation complete. No planets harmed.");
PIZZA_LOG("Pepperoni shortage alert at store #{}!", store_id);
```

---

## 🎯 Dynamic Verbosity Adjustment

Adjust logging verbosity anytime—handy when debugging or just when you feel less verbose:

```cpp
LogSvc::SetTerminalLogLevel(loguru::Verbosity_ERROR);
```

---

## ⚙️ Custom Callbacks (Advanced Fun)

Callbacks let you react to log events beyond just writing files. For example, send yourself a congratulatory email whenever your program finishes its epic run:

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

Another callback sends alerts over a network socket (for your custom SMS or notification server):

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

## 🗃️ Humorous Example Log Outputs

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
| `loguru::add_callback()`     | Add your own fancy callbacks for custom log handling.            |

---

## 🗝️ Final Words

LogSvc combines robust logging capabilities with humorous flexibility. It's perfect for any C++ project—whether you're simulating universes, tracking pizzas, or just trying not to accidentally delete the database again. Happy logging!

