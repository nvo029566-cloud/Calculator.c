# 🧮 Handheld Calculator — C Language

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](#)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](#-license)

A command-line (CLI) calculator application written in **C**, supporting **22 functions** ranging from basic arithmetic to advanced operations (trigonometry, logarithms, number theory), along with a **calculation history system** saved to a file. The project is designed with a **modular architecture** (each group of features lives in its own file), making it ideal for learning C programming.

---

## 📑 Table of Contents

- [Features](#-features)
- [Project Structure](#-project-structure)
- [System Requirements](#️-system-requirements)
- [Installation & Build](#-installation--build)
- [Usage Guide](#-usage-guide)
- [Calculation History](#-calculation-history)
- [Program Flow Diagram](#-program-flow-diagram)
- [Notes & Limitations](#️-notes--limitations)
- [Roadmap](#-roadmap)
- [Author](#-author)
- [License](#-license)

---

## ✨ Features

### ➕ Basic Operations

| Option | Function | Example |
|:---:|---|---|
| 1 | Addition (a + b) | `5 + 3 = 8` |
| 2 | Subtraction (a − b) | `5 − 3 = 2` |
| 3 | Multiplication (a × b) | `5 × 3 = 15` |
| 4 | Division (a ÷ b) | `6 ÷ 3 = 2` |

### 🔢 Mathematics

| Option | Function | Example |
|:---:|---|---|
| 5 | Square root | `√16 = 4` |
| 6 | Factorial (n!) | `5! = 120` |
| 7 | Power (aᵇ) | `2³ = 8` |
| 8 | Prime number check | `7 → is prime` |
| 9 | Greatest Common Divisor (GCD) | `GCD(12, 18) = 6` |
| 10 | Least Common Multiple (LCM) | `LCM(4, 6) = 12` |

### 📐 Trigonometry *(unit: degrees)*

| Option | Function |
|:---:|---|
| 11 | Sine |
| 12 | Cosine |
| 13 | Tangent |

### 🎯 Rounding

| Option | Function | Example |
|:---:|---|---|
| 14 | Standard rounding | `3.6 → 4` |
| 15 | Round up (ceil) | `3.1 → 4` |
| 16 | Round down (floor) | `3.9 → 3` |

### 📊 Logarithm

| Option | Function |
|:---:|---|
| 17 | Natural logarithm (ln) |
| 18 | Base-10 logarithm (log₁₀) |

### ✅ Checks

| Option | Function | Example |
|:---:|---|---|
| 19 | Even / odd check | `4 → even` |
| 20 | Perfect number check | `28 → is a perfect number` |

### 🕘 History

| Option | Function |
|:---:|---|
| 21 | View calculation history |
| 22 | Clear history |
| **0** | **Exit program** |

---

## 📁 Project Structure

```
.
├── main.c          # Main function, menu interface and option handling
├── calculator.c    # Basic operations (add, subtract, multiply, divide)
├── calculator.h    # Header for calculator.c
├── advanced.c      # Advanced math functions
├── advanced.h      # Header for advanced.c
├── history.c       # History management (read/write/clear file)
├── history.h       # Header for history.c
├── lichSu.txt      # History file (auto-created at runtime)
└── README.md       # Project documentation
```

> 💡 Each module (`calculator`, `advanced`, `history`) has its own `.h` file declaring prototypes, keeping the interface cleanly separated from the implementation — following good modular C programming practice.

---

## 🛠️ System Requirements

| Component | Requirement |
|---|---|
| Operating System | Windows (uses `windows.h` and `SetConsoleOutputCP(65001)` to display Vietnamese text in UTF-8) |
| Compiler | GCC (MinGW-w64) or MSVC |
| Standard Libraries | `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `math.h`, `windows.h` |

> ⚠️ On Linux/macOS, the `windows.h` / `SetConsoleOutputCP` calls must be removed or replaced for the program to compile (see [Notes & Limitations](#️-notes--limitations)).

---

## 🚀 Installation & Build

### 1. Clone the repository

```bash
git clone https://github.com/<username>/<repo-name>.git
cd <repo-name>
```

### 2. Compile with GCC

```bash
gcc main.c calculator.c advanced.c history.c -o main -lm
```

> The `-lm` flag is required to link the math library (`math.h`) — used for square root, trigonometry, logarithms, power functions, etc.

### 3. Run the program

```bash
./main
```

Or on Windows:

```bash
main.exe
```

---

## 📖 Usage Guide

After running the program, a menu with 22 functions is displayed. The user simply needs to:

1. Enter the **number corresponding** to the desired function (0–22)
2. Enter the required input values as prompted on screen
3. View the result — valid results are automatically saved to `lichSu.txt`
4. Repeat or enter `0` to exit the program

**Example session:**

```
===== HANDHELD CALCULATOR =====
1. Add         2. Subtract
3. Multiply    4. Divide
5. Square root ...
0. Exit
=================================
Enter your choice: 1
Enter the first number: 45
Enter the second number: 25
Result: 45.00 + 25.00 = 70.00
Saved to history.
```

---

## 📝 Calculation History

Every **successful** calculation is automatically saved to the `lichSu.txt` file (in the same directory as the executable), in the following format:

```
Cong = 70.00
Tru = -144.00
Nhan = 15.00
```

- **Option 21**: displays the full contents of `lichSu.txt` on screen
- **Option 22**: clears the entire history (overwrites the file as empty)

> Calculations that result in an error (division by zero, square root of a negative number, logarithm of a non-positive number, etc.) **will not** be saved to the history.

---

## 🔄 Program Flow Diagram

```
┌─────────────┐
│   main()    │
└──────┬──────┘
       │
       ▼
┌─────────────────────┐
│  Display menu (0-22) │◄──────────────┐
└──────┬───────────────┘               │
       │                                │
       ▼                                │
┌─────────────────────┐                │
│ Read user choice     │                │
└──────┬───────────────┘                │
       │                                │
       ▼                                │
┌─────────────────────────────┐         │
│ switch(choice)               │         │
│  ├─ 1-4   → calculator.c     │         │
│  ├─ 5-20  → advanced.c       │         │
│  ├─ 21-22 → history.c        │         │
│  └─ 0     → Exit             │         │
└──────┬────────────────────────┘        │
       │ (valid result)                  │
       ▼                                  │
┌─────────────────────┐                  │
│ Write to lichSu.txt  │──────────────────┘
└─────────────────────┘
```

---

## ⚠️ Notes & Limitations

- **Division by zero**: the program displays an error message and does **not** save it to the history.
- **Square root of a negative number**: returns an error without performing the calculation.
- **Factorial (n!)**: only accepts **non-negative integers**.
  - ⚠️ The `gt()` function currently uses an `int` for its intermediate variable — for large values of `n` (n > 12), this can cause **integer overflow**. Switching to `long long` is recommended to safely extend the supported range (up to `20!`).
- **Logarithm**: only valid for positive numbers (`x > 0`).
- **Cross-platform compatibility**: the `windows.h`/`SetConsoleOutputCP` calls only work on Windows. To run on Linux/macOS, wrap these sections in `#ifdef _WIN32 ... #endif` or remove them.

---

## 🔮 Roadmap

- [ ] Fix factorial overflow using `long long` or `double` for large `n`
- [ ] Add cross-platform support (Linux/macOS) via `#ifdef`
- [ ] Add a percentage (%) function
- [ ] Add temporary memory functions (M+, M-, MR, MC)
- [ ] Allow exporting history to a CSV file for easier analysis
- [ ] Write unit tests for the `calculator` and `advanced` modules

---

## 👤 Author

This project is written in **C**, following a **modular programming** style, and is intended for learning purposes and practicing basic data structures and algorithms in C.

---

## 📄 License

This project is released under the **MIT License** — free to use, modify, and distribute for educational and non-commercial purposes.
