#ifndef USABLE_RESOURCE_H
#define USABLE_RESOURCE_H

#include "Resource.h"

/**
 * @brief Usable resource that is occupied during use, such as a CPU.
 *
 * This class extends Resource to model resources that can be allocated and released without
 * depletion, maintaining a fixed capacity that indicates its capability (e.g., GHz).
 */
class UsableResource final : public Resource {
private:
    int capacity;  ///< Fixed capacity of the resource (e.g., GHz for CPU).

public:
    /**
     * @brief Constructs a UsableResource with a name and capacity.
     * @param name The unique identifier for the resource.
     * @param capacity The capacity of the resource (e.g., GHz).
     * @throw std::invalid_argument If capacity is not positive.
     */
    UsableResource(const std::string& name, int capacity);

    /**
     * @brief Checks if the resource is available for allocation.
     * @return True if the resource is not currently allocated, false otherwise.
     */
    [[nodiscard]] bool isAvailableForUse() const override;

    /**
     * @brief Allocates the resource, marking it as unavailable.
     * @throw std::runtime_error If the resource is already allocated.
     */
    void allocate() override;

    /**
     * @brief Releases the resource, making it available again.
     */
    void release() override;

    /**
     * @brief Displays the resource usage details, including its capacity.
     */
    void use() const override;
};
#endif //USABLE_RESOURCE_H
