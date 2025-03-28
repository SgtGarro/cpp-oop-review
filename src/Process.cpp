#include "Process.h"
#include <iostream>

/**
 * @brief Constructs a Process to manage a sequence of tasks.
 * @param name The unique identifier for the process.
 * @param description A description of the process's purpose.
 * @param requiredResourcesNames Names of resources required if acting as a task.
 * @param durationInUnits Duration of execution in time units.
 * @throw std::invalid_argument If name is empty or duration is not positive.
 */
Process::Process(const std::string& name, const std::string& description,
                 const std::vector<std::string>& requiredResourcesNames, int durationInUnits)
    : Executable(name, description, requiredResourcesNames, durationInUnits) {}

/**
 * @brief Adds a resource to the process's resource pool.
 * @param resource A unique pointer to the resource to add.
 */
void Process::addResource(std::unique_ptr<Resource> resource) {
    resourcePool.push_back(std::move(resource));
}

/**
 * @brief Adds a task to the process's sequence.
 * @param task A unique pointer to the task to add.
 */
void Process::addTask(std::unique_ptr<Executable> task) {
    tasks.push_back(std::move(task));
}

/**
 * @brief Executes the process by running its sequence of tasks.
 * @throw std::runtime_error If resources are not properly assigned or tasks fail.
 */
void Process::execute() const {
    if (!requiredResourcesNames.empty() && assignedResources.size() != requiredResourcesNames.size()) {
        throw std::runtime_error("Resources not properly assigned for process '" + name + "'");
    }
    std::cout << "Executing process '" << name << ": " << description
              << " (Duration: " << durationInUnits << " units)\n";
    if (!assignedResources.empty()) {
        for (const auto* resource : assignedResources) {
            resource->use();
        }
    }

    for (const auto& task : tasks) {
        try {
            if (task->canExecute(resourcePool)) {
                task->assignResources(resourcePool);
                std::cout << "  ";
                task->execute();
                task->releaseResources();
            } else {
                std::cout << "  Task '" << task->getName() << "' skipped: insufficient resources\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "  Error in '" << task->getName() << "': " << e.what() << "\n";
        }
    }

}

/**
 * @brief Runs the process standalone, managing its own resource pool.
 * @throw std::runtime_error If insufficient resources are available to start.
 */
void Process::run() {
    try {
        if (requiredResourcesNames.empty() || canExecute(resourcePool)) {
            if (!requiredResourcesNames.empty()) {
                assignResources(resourcePool);
            }
            execute();
            releaseResources();
            std::cout << "Process '" << name << "' completed.\n";
        } else {
            throw std::runtime_error("Insufficient resources in pool to start '" + name + "'");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in process '" << name << "': " << e.what() << "\n";
    }
}
