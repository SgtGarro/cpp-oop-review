# cpp-oop-review

## Overview

**cpp-oop-review** is a C++ console application designed to illustrate the core concepts of Object-Oriented Programming (OOP) using a process simulation. The project implements a simplified compilation pipeline—converting a source file (`main.c`) into an executable (`main.exe`)—to demonstrate encapsulation, inheritance, polymorphism, and abstraction. A `Process` manages a sequence of `Task` objects (e.g., scanning, parsing, static analysis, code generation, linking), utilizing resources like `Consumable` Memory and `Usable` CPU.

**Author**: IoT Solution Development Staff  
**Date**: March 27, 2025  
**Version**: 1.0  
**License**: MIT

## Purpose

The primary goal of `cpp-oop-review` is educational: to provide a practical example of OOP principles in C++ through a process simulation. It serves as a learning tool for developers to explore:
- **Encapsulation**: Data and behavior are bundled within classes (e.g., `Resource`, `Task`).
- **Inheritance**: Classes like `ConsumableResource` and `UsableResource` inherit from `Resource`.
- **Polymorphism**: Virtual methods (e.g., `execute()`) allow runtime behavior variation.
- **Abstraction**: Abstract base classes (`Resource`, `Executable`) define interfaces.

## Features

- **OOP Demonstration**: Clearly showcases encapsulation, inheritance, polymorphism, and abstraction.
- **Modular Design**: Adheres to the class-per-file convention with headers in `include/` and sources in `src/`.
- **Process Simulation**: Models a compilation pipeline with realistic tasks and resource management.
- **Resource Types**: Includes `ConsumableResource` (depletes) and `UsableResource` (reusable).
- **Exception Handling**: Error handling for resource allocation and execution.
- **Documentation**: Doxygen-style comments for classes, attributes, and methods.

# Class Diagram
![Class Diagram](docs/class-diagram.png)
Following is the class diagram for the project, illustrating the relationships between classes and their attributes/methods.

![Class Diagram](https://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/upc-pre-202510-1asi0572-sandbox/cpp-oop-review/refs/heads/master/docs/class-diagram.md?token=GHSAT0AAAAAAC7JG2V4DUHG4SPXXYVLWI3MZ7JPZKQ)
## Prerequisites

- **CMake**: Version 3.10 or higher
- **C++ Compiler**: Supporting C++17 (e.g., GCC, Clang, MSVC)
- **IDE (Optional)**: CLion recommended for macOS development

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/<your-username>/cpp-oop-review.git
   cd cpp-oop-review
   ```
2. **Create a Build Directory**:
   ```bash
   mkdir build
   cd build
   ```
3. **Configure CMake**:
   ```bash
   cmake ..
   ```
4. **Build the Executable**:
   ```bash
    cmake --build .
    ```
## Usage
Run the compiled executable from the `build/` directory:
```bash
./cpp-oop-review
```
The application will simulate a compilation process, outputting the tasks and resources involved.
### Example Output
```plaintext
Starting compilation simulation...
Executing process 'CompileMain': Compile main.c to main.exe (Duration: 15 units)
    Using usable resource 'CentralProcessingUnit' (capacity: 3 GHz)
    Using consumable resource 'Memory' (remaining: 4095/4096 MB)
  Executing task 'ScanSourceCode': Tokenize main.c (Duration: 2 units)
    Using usable resource 'CentralProcessingUnit' (capacity: 3 GHz)
    Using consumable resource 'Memory' (remaining: 4094/4096 MB)
  ...
Process 'CompileMain' completed.

Simulating compilation with limited memory...
Executing process 'CompileLimited': Compile main.c with low memory (Duration: 15 units)
    Using usable resource 'CentralProcessingUnit' (capacity: 3 GHz)
    Using consumable resource 'Memory' (remaining: 1/2 MB)
  Executing task 'ScanSourceCode': Tokenize main.c (Duration: 2 units)
    Using usable resource 'CentralProcessingUnit' (capacity: 3 GHz)
    Using consumable resource 'Memory' (remaining: 0/2 MB)
  Task 'ParseSyntax' skipped: insufficient resources
Process 'CompileLimited' completed.
```
