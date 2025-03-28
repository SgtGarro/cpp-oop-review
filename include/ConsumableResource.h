#ifndef CONSUMABLE_RESOURCE_H
#define CONSUMABLE_RESOURCE_H

#include "Resource.h"

/**
 * @brief Consumable resource that depletes upon use, such as memory.
 *
 * This class extends Resource to model resources with a finite capacity that decreases with each allocation.
 * Once depleted, the resource requires external replenishment to become available again.
 */
class ConsumableResource final : public Resource {
private:
    int totalCapacity; ///< Total capacity of the resource (e.g., total memory in MB).
    int remainingCapacity; ///< Remaining capacity of the resource available for use.

public:
    /**
     * @brief Constructor for ConsumableResource with a given name and capacity.
     *
     * @param name Name of the resource.
     * @param capacity Total capacity of the resource.
     *
     * @throw std::invalid_argument if the capacity is less than or equal to zero.
     */
    ConsumableResource(const std::string &name, int capacity);

    /**
    * @brief Checks if the resource has remaining capacity for allocation.
    * @return True if remaining capacity is greater than 0, false otherwise.
    */
    [[nodiscard]] bool isAvailableForUse() const override;

    /**
     * @brief Allocates one unit of the resource, reducing its remaining capacity.
     * @throw std::runtime_error If no capacity remains to allocate.
     */
    void allocate() override;

    /**
     * @brief Releases the resource, updating availability status.
     * @note Does not restore capacity; external replenishment is required.
     */
    void release() override;

    /**
     * @brief Displays the resource usage details, including remaining capacity.
     */
    void use() const override;

    /**
     * @brief Retrieves the remaining capacity of the resource.
     * @return The current remaining capacity in units (e.g., MB).
     */
    [[nodiscard]] int getRemainingCapacity() const;
};

#endif //CONSUMABLE_RESOURCE_H
