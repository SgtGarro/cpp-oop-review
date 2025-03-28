#include "Executable.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

/**
 * @brief Constructs an Executable entity.
 * @param name The unique identifier for the entity.
 * @param description A description of the entity's purpose.
 * @param requiredResourcesNames Names of resources required for execution.
 * @param durationInUnits Duration of execution in time units.
 * @throw std::invalid_argument If name is empty or duration is not positive.
 */
Executable::Executable(const std::string& name, std::string  description,
                       const std::vector<std::string>& requiredResourcesNames, int durationInUnits)
    : name(name), description(std::move(description)), requiredResourcesNames(requiredResourcesNames),
      durationInUnits(durationInUnits), assignedResources() {
    if (name.empty()) throw std::invalid_argument("Executable name cannot be empty");
    if (durationInUnits <= 0) throw std::invalid_argument("Duration for '" + name + "' must be positive");
}

/**
 * @brief Retrieves the entity's unique name.
 * @return The name of the executable entity.
 */
std::string Executable::getName() const {
    return name;
}

/**
 * @brief Retrieves the names of required resources.
 * @return A constant reference to the vector of resource names.
 */
const std::vector<std::string>& Executable::getRequiredResourcesNames() const {
    return requiredResourcesNames;
}

/**
 * @brief Retrieves the execution duration.
 * @return The duration in time units.
 */
int Executable::getDurationInUnits() const {
    return durationInUnits;
}

/**
 * @brief Assigns required resources from a pool.
 * @param resourcePool The pool of available resources.
 * @throw std::runtime_error If any required resource is unavailable.
 */
void Executable::assignResources(const std::vector<std::unique_ptr<Resource>>& resourcePool) {
    assignedResources.clear();
    if (requiredResourcesNames.empty()) return;

    for (const auto& resourceName : requiredResourcesNames) {
        bool found = false;
        for (auto& resource : resourcePool) {
            if (resource->getName() == resourceName && resource->isAvailableForUse()) {
                resource->allocate();
                assignedResources.push_back(resource.get());
                found = true;
                break;
            }
        }
        if (!found) {
            releaseResources();
            throw std::runtime_error("Resource '" + resourceName + "' not available for '" + name + "'");
        }
    }
}

/**
 * @brief Releases all assigned resources.
 */
void Executable::releaseResources() {
    for (auto* resource : assignedResources) {
        try {
            resource->release();
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to release resource '" << resource->getName()
                      << "' in '" << name << "': " << e.what() << "\n";
        }
    }
    assignedResources.clear();
}

/**
 * @brief Checks if the entity can be executed with the given resource pool.
 * @param resourcePool The pool of available resources.
 * @return True if all required resources are available, false otherwise.
 */
bool Executable::canExecute(const std::vector<std::unique_ptr<Resource>>& resourcePool) const {
    if (requiredResourcesNames.empty()) return true;
    for (const auto& resourceName : requiredResourcesNames) {
        if (std::none_of(resourcePool.begin(), resourcePool.end(),
            [&resourceName](const std::unique_ptr<Resource>& resource) {
                return resource->getName() == resourceName && resource->isAvailableForUse(); })) {
            return false;
                }
    }
    return true;
}

/**
 * @brief Virtual destructor for proper cleanup in derived classes.
 */
Executable::~Executable() {
    releaseResources();
}



