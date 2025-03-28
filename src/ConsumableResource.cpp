#include "ConsumableResource.h"
#include <stdexcept>
#include <iostream>

/**
 * @brief Constructs a ConsumableResource with a name and capacity.
 * @param name The unique identifier for the resource.
 * @param capacity The total capacity of the resource.
 * @throw std::invalid_argument If capacity is not positive.
 */
ConsumableResource::ConsumableResource(const std::string& name, const int capacity)
    : Resource(name, Type::Consumable), totalCapacity(capacity), remainingCapacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be positive");
    }
}

/**
 * @brief Checks if the resource has remaining capacity for allocation.
 * @return True if remaining capacity is greater than 0, false otherwise.
 */
bool ConsumableResource::isAvailableForUse() const {
    return remainingCapacity > 0;
}

/**
 * @brief Allocates one unit of the resource, reducing its remaining capacity.
 * @throw std::runtime_error If no capacity remains to allocate.
 */
void ConsumableResource::allocate() {
    if (remainingCapacity <= 0) {
        throw std::runtime_error("No remaining capacity for consumable resource '" + name + "'");
    }
    remainingCapacity--;
    isAvailable = (remainingCapacity > 0);
}

/**
 * @brief Releases the resource, updating availability status.
 * @note Does not restore capacity; external replenishment is required.
 */
void ConsumableResource::release() {
    if (remainingCapacity == 0 && !isAvailable) {
        std::cerr << "Warning: Consumable resource '" << name << "' is depleted and cannot be reused without replenishment\n";
    }
    isAvailable = (remainingCapacity > 0);
}

/**
 * @brief Displays the resource usage details, including remaining capacity.
 */
void ConsumableResource::use() const {
    std::cout << "    Using consumable resource '" << name << "' (remaining: " << remainingCapacity << "/" << totalCapacity << " MB)\n";
}

/**
 * @brief Retrieves the remaining capacity of the resource.
 * @return The current remaining capacity in units (e.g., MB).
 */
int ConsumableResource::getRemainingCapacity() const {
    return remainingCapacity;
}