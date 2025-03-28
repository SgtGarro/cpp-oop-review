#include "UsableResource.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructs a UsableResource with a name and capacity.
 * @param name The unique identifier for the resource.
 * @param capacity The capacity of the resource (e.g., GHz).
 * @throw std::invalid_argument If capacity is not positive.
 */
UsableResource::UsableResource(const std::string& name, const int capacity)
    : Resource(name, Type::Usable), capacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be positive");
    }
}

/**
 * @brief Checks if the resource is available for allocation.
 * @return True if the resource is not currently allocated, false otherwise.
 */
bool UsableResource::isAvailableForUse() const {
    return isAvailable;
}

/**
 * @brief Allocates the resource, marking it as unavailable.
 * @throw std::runtime_error If the resource is already allocated.
 */
void UsableResource::allocate() {
    if (!isAvailable) {
        throw std::runtime_error("Usable resource '" + name + "' is already allocated");
    }
    isAvailable = false;
}

/**
 * @brief Releases the resource, making it available again.
 */
void UsableResource::release() {
    if (isAvailable) {
        std::cerr << "Warning: Attempted to release already free usable resource '" << name << "'\n";
    }
    isAvailable = true;
}

/**
 * @brief Displays the resource usage details, including its capacity.
 */
void UsableResource::use() const {
    std::cout << "    Using usable resource '" << name << "' (capacity: " << capacity << " GHz)\n";
}

