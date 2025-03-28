#include "Process.h"
#include "Task.h"
#include "UsableResource.h"
#include "ConsumableResource.h"
#include <iostream>
#include <memory>

int main() {
    try {
        // Compilation process for main.c
        const auto compilationProcess = std::unique_ptr<Process>(
            new Process("CompileMain", "Compile main.c to main.exe", {"CentralProcessingUnit", "Memory"}, 15));

        // Add resources to the pool
        compilationProcess->
                addResource(std::unique_ptr<UsableResource>(new UsableResource("CentralProcessingUnit", 3)));
        compilationProcess->addResource(std::unique_ptr<ConsumableResource>(new ConsumableResource("Memory", 4096)));

        // Define compilation tasks
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("ScanSourceCode", "Tokenize main.c",
                                                                   {"CentralProcessingUnit", "Memory"}, 2)));
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("ParseSyntax", "Build syntax tree from tokens",
                                                                   {"CentralProcessingUnit", "Memory"}, 3)));
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("PerformStaticAnalysis",
                                                                   "Check syntax tree for errors",
                                                                   {"CentralProcessingUnit", "Memory"}, 4)));
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("GenerateCode", "Generate machine code",
                                                                   {"CentralProcessingUnit", "Memory"}, 3)));
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("LinkBinary", "Link object files into main.exe",
                                                                   {"CentralProcessingUnit", "Memory"}, 2)));

        // Run successful compilation
        std::cout << "Starting compilation simulation...\n";
        compilationProcess->run();

        // Simulate compilation with limited memory
        std::cout << "\nSimulating compilation with limited memory...\n";
        const auto limitedCompilation = std::unique_ptr<Process>(
            new Process("CompileLimited", "Compile main.c with low memory", {"CentralProcessingUnit", "Memory"}, 15));
        limitedCompilation->
                addResource(std::unique_ptr<UsableResource>(new UsableResource("CentralProcessingUnit", 3)));
        limitedCompilation->addResource(std::unique_ptr<ConsumableResource>(new ConsumableResource("Memory", 2)));
        limitedCompilation->addTask(std::unique_ptr<Task>(new Task("ScanSourceCode", "Tokenize main.c",
                                                                   {"CentralProcessingUnit", "Memory"}, 2)));
        limitedCompilation->addTask(std::unique_ptr<Task>(new Task("ParseSyntax", "Build syntax tree from tokens",
                                                                   {"CentralProcessingUnit", "Memory"}, 3)));
        limitedCompilation->run();
    } catch (const std::exception &e) {
        std::cerr << "Critical error in main: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
