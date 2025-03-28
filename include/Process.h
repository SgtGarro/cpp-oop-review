#ifndef PROCESS_H
#define PROCESS_H

#include "Executable.h"

/**
 * @brief Concrete implementation of Executable for managing a sequence of tasks.
 *
 * This class represents a process that orchestrates a series of tasks, such as a compilation pipeline.
 * It maintains a resource pool and executes tasks sequentially, supporting hierarchical composition
 * where a Process can act as a Task within another Process.
 */
class Process final : public Executable {
private:
    std::vector<std::unique_ptr<Resource> > resourcePool; ///< Pool of resources available to tasks.
    std::vector<std::unique_ptr<Executable> > tasks; ///< Sequence of tasks to execute.
public:
    /**
     * @brief Constructs a Process to manage a sequence of tasks.
     * @param name The unique identifier for the process.
     * @param description A description of the process's purpose.
     * @param requiredResourcesNames Names of resources required if acting as a task.
     * @param durationInUnits Duration of execution in time units.
     * @throw std::invalid_argument If name is empty or duration is not positive.
     */
    Process(const std::string &name, const std::string &description,
            const std::vector<std::string> &requiredResourcesNames, int durationInUnits);

    /**
     * @brief Adds a resource to the process's resource pool.
     * @param resource A unique pointer to the resource to add.
     */
    void addResource(std::unique_ptr<Resource> resource);

    /**
     * @brief Adds a task to the process's sequence.
     * @param task A unique pointer to the task to add.
     */
    void addTask(std::unique_ptr<Executable> task);

    /**
     * @brief Executes the process by running its sequence of tasks.
     * @throw std::runtime_error If resources are not properly assigned or tasks fail.
     */
    void execute() const override;

    /**
     * @brief Runs the process standalone, managing its own resource pool.
     * @throw std::runtime_error If insufficient resources are available to start.
     */
    void run();
};
#endif //PROCESS_H
