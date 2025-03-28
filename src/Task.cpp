#include "Task.h"
#include <iostream>

/**
 * @brief Constructs a Task for a compilation stage.
 * @param name The unique identifier for the task.
 * @param description A description of the task's purpose.
 * @param requiredResourcesNames Names of resources required for execution.
 * @param durationInUnits Duration of execution in time units.
 * @throw std::invalid_argument If name is empty or duration is not positive.
 */
Task::Task(const std::string& name, const std::string& description,
           const std::vector<std::string>& requiredResourcesNames, const int durationInUnits)
    : Executable(name, description, requiredResourcesNames, durationInUnits) {}

/**
 * @brief Executes the task using assigned resources.
 * @throw std::runtime_error If resources are not properly assigned.
 */
void Task::execute() const {
    if (assignedResources.size() != requiredResourcesNames.size()) {
        throw std::runtime_error("Resources not properly assigned for task '" + name + "'");
    }
    std::cout << "Executing task '" << name << ": " << description
    << " (Duration: " << durationInUnits << " units)\n";
    for (const auto* resource : assignedResources) {
        resource->use();
    }
}
