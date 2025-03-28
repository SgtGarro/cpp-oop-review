#ifndef TASK_H
#define TASK_H

#include "Executable.h"

/**
 * @brief Concrete implementation of Executable for individual compilation tasks.
 *
 * This class represents a single, atomic task in a process, such as scanning or parsing.
 * It executes using assigned resources and provides a simple implementation of the execute method.
 */
class Task final : public Executable {
public:
    /**
     * @brief Constructs a Task for a compilation stage.
     * @param name The unique identifier for the task.
     * @param description A description of the task's purpose.
     * @param requiredResourcesNames Names of resources required for execution.
     * @param durationInUnits Duration of execution in time units.
     * @throw std::invalid_argument If name is empty or duration is not positive.
     */
    Task(const std::string& name, const std::string& description,
         const std::vector<std::string>& requiredResourcesNames, int durationInUnits);

    /**
     * @brief Executes the task using assigned resources.
     * @throw std::runtime_error If resources are not properly assigned.
     */
    void execute() const override;
};
#endif //TASK_H
