# Student Grade Tracker

A small C program that reads a fixed set of student grades, validates the input, and prints an average/highest/lowest report.

This project isn't about the grade tracker itself — it's a hands-on exercise for core C fundamentals: splitting a program across multiple files, function prototypes, header guards, and `static` for file-local scope.

## What it does

1. Prompts for 6 grades, one at a time.
2. Re-prompts on bad input (e.g. letters) until a valid integer is entered.
3. Prints a formatted report with the average, highest, and lowest grade.

```
=== Student Grade Tracker ===
Please enter 6 grades.

Enter grade 1: 85
Enter grade 2: 92
Enter grade 3: abc
Only integers are allowed, enter a proper grade: 78
Enter grade 4: 60
Enter grade 5: 100
Enter grade 6: 73


==========================
    GRADE REPORT
==========================
    AVERAGE  : 81.33
    Highest  : 100
    Lowest   : 60
==========================

```

## Project layout

```
src/
├── main.c       # Input loop + validation, drives the program
├── stats.h      # Public API for grade calculations
├── stats.c      # average / highest / lowest (+ a private sum helper)
├── report.h     # Public API for printing the report
├── report.c     # print_report (+ a private print_line helper)
└── Makefile     # Build rules
```

Each `.c` file pairs with a `.h` file that exposes only what other files need. Everything else stays `static` and hidden inside the file that owns it.

## Concepts practiced

| Concept                                   | Where                                                                                                                                                                                                       |
| ----------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Function prototypes**                   | `stats.h` and `report.h` declare signatures separately from their implementation, so `main.c` can call `print_report()` without knowing how it works internally.                                            |
| **Header guards**                         | `#ifndef` / `#define` / `#endif` in every header ([stats.h](src/stats.h), [report.h](src/report.h)) prevents duplicate declarations if a header is included more than once.                                 |
| **`static` functions (internal linkage)** | [sum()](src/stats.c#L4) in `stats.c` and [print_line()](src/report.c#L5) in `report.c` are implementation details — `static` keeps them private to their file instead of leaking into the global namespace. |
| **Separation of concerns**                | Input/validation (`main.c`), calculations (`stats.c`), and presentation (`report.c`) are split into independent modules that only talk through their headers.                                               |
| **Input validation with `sscanf`**        | The retry loop in `main.c` uses `sscanf(input, "%d %c", ...)` to reject anything that isn't a clean integer.                                                                                                |
| **Build automation**                      | The `Makefile` compiles each `.c` file into an object file and links them, tracking header dependencies so changes trigger a rebuild.                                                                       |

## Building and running

From the `src/` directory:

```bash
make        # builds ./main
./main      # run it
make clean  # remove build artifacts
```

Requires `gcc`. Compiled with `-Wall -Wextra` to keep warnings honest while learning.
