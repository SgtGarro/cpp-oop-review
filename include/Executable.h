#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "Resource.h"
#include <string>
#include <vector>

/**
 * @brief Abstract base class for entities that can be executed with resource requirements.
 *
 * This class provides the foundation for tasks and processes, defining common behavior such as
 * resource assignment, execution, and resource release. Derived classes must implement the
 * execute method to specify their execution logic.
 */
class Executable {
protected:
    std::string name; ///< Unique identifier for the executable entity.
    std::string description; ///< Descriptive text explaining the entity's purpose.
    std::vector<std::string> requiredResourcesNames; ///< Names of resources required for execution.
    int durationInUnits; ///< Duration of execution in abstract time units.
    std::vector<Resource *> assignedResources; ///< Pointers to resources currently assigned.
public:
    /**
     * @brief Constructs an Executable entity.
     * @param name The unique identifier for the entity.
     * @param description A description of the entity's purpose.
     * @param requiredResourcesNames Names of resources required for execution.
     * @param durationInUnits Duration of execution in time units.
     * @throw std::invalid_argument If name is empty or duration is not positive.
     */
    Executable(const std::string &name, std::string description,
               const std::vector<std::string> &requiredResourcesNames, int durationInUnits);

    /**
    * @brief Virtual destructor for proper cleanup in derived classes.
    */
    virtual ~Executable();

    /**
    * @brief Retrieves the entity's unique identifier.
    * @return The name of the executable entity.
    */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the names of required resources.
     * @return A constant reference to the vector of resource names.
     */
    [[nodiscard]] const std::vector<std::string>& getRequiredResourcesNames() const;

    /**
     * @brief Retrieves the execution duration.
     * @return The duration in time units.
     */
    [[nodiscard]] int getDurationInUnits() const;

    /**
     * @brief Assigns required resources from a pool.
     * @param resourcePool The pool of available resources.
     * @throw std::runtime_error If any required resource is unavailable.
     */
    void assignResources(const std::vector<std::unique_ptr<Resource> >& resourcePool);

    /**
     * @brief Releases all assigned resources.
     */
    void releaseResources();

    /**
     * @brief Executes the entity using assigned resources.
     * @throw std::runtime_error If resources are not properly assigned.
     */
    virtual void execute() const = 0;

    /**
     * @brief Checks if the entity can be executed with the given resource pool.
     * @param resourcePool The pool of available resources.
     * @return True if all required resources are available, false otherwise.
     */
    [[nodiscard]] bool canExecute(const std::vector<std::unique_ptr<Resource> >& resourcePool) const;
};

#endif //EXECUTABLE_H
