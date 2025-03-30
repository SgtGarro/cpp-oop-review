# User Stories

This document contains the user stories with acceptance criteria for `cpp-oop-review`, focusing on the functional requirements of simulating a compilation process in C++. The criteria use the Given-When-Then format in third person to specify observable behavior.

## US01: Simulate a Successful Compilation Process
**As a** user of the simulation,  
**I want** to execute a compilation process with sufficient resources,  
**so that** I can observe a complete workflow from source code to executable.

### Acceptance Criteria
- **Scenario 1: Full compilation with ample resources**
    - **Given** a process named "CompileMain" with a CPU (3 GHz) and Memory (4096 MB) and tasks (scanning, parsing, static analysis, code generation, linking),
    - **When** the user runs the simulation,
    - **Then** the system executes all tasks in sequence, displays resource usage for each, and outputs "Process 'CompileMain' completed."

## US02: Handle Resource Constraints During Compilation
**As a** user of the simulation,  
**I want** to execute a compilation process with limited resources,  
**so that** I can see how the system manages insufficient resources.

### Acceptance Criteria
- **Scenario 1: Compilation with limited memory**
    - **Given** a process named "CompileLimited" with a CPU (3 GHz) and Memory (2 MB) and tasks (scanning, parsing),
    - **When** the user runs the simulation,
    - **Then** the system executes the scanning task, skips the parsing task with a message "Task 'ParseSyntax' skipped: insufficient resources," and outputs "Process 'CompileLimited' completed."

## US03: Track Consumable Resource Usage
**As a** user of the simulation,  
**I want** to monitor the depletion of consumable resources like memory,  
**so that** I can understand resource consumption during the process.

### Acceptance Criteria
- **Scenario 1: Memory usage display**
    - **Given** a process with a ConsumableResource "Memory" (4096 MB) and multiple tasks,
    - **When** the user runs the simulation,
    - **Then** the system displays memory usage (e.g., "remaining: 4095/4096 MB") after each task, decreasing with each allocation.

## US04: Manage Usable Resource Availability
**As a** user of the simulation,  
**I want** to see how usable resources like CPU are allocated and released,  
**so that** I can observe resource occupancy during the process.

### Acceptance Criteria
- **Scenario 1: CPU allocation and release**
    - **Given** a process with a UsableResource "CentralProcessingUnit" (3 GHz) and a task,
    - **When** the user runs the simulation,
    - **Then** the system allocates the CPU for the task, displays its usage (e.g., "capacity: 3 GHz"), and releases it afterward, making it available for subsequent tasks.

## US05: Execute Hierarchical Processes
**As a** user of the simulation,  
**I want** to run a process that manages a sequence of tasks,  
**so that** I can see how tasks are orchestrated within a workflow.

### Acceptance Criteria
- **Scenario 1: Sequential task execution**
    - **Given** a process with multiple tasks (e.g., scanning, parsing),
    - **When** the user runs the simulation,
    - **Then** the system executes each task in the order added, displaying their execution details (e.g., "Executing task 'ScanSourceCode'...").