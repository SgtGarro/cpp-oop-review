#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

/**
 * @brief Abstract base class for resources used in executable tasks or processes.
 *
 * This class defines the interface for resources that can be either consumable (e.g., memory)
 * or usable (e.g., CPU). It provides a foundation for resource management, including allocation,
 * release, and usage tracking.
 */
class Resource {
public:
    /// @brief Enumeration defining the type of resource.
    enum class Type { Consumable, Usable };

protected:
    std::string name; ///< Unique name of the resource.
    bool isAvailable; ///< Indicates whether the resource is available for use.
    Type resourceType; ///< Specifies the type of resource (Consumable or Usable).
public:
    /**
     * @brief Constructor for the Resource class.
     *
     * @param name Unique name of the resource.
     * @param type Type of the resource (Consumable or Usable).
     */
    Resource(std::string name, Type type);

    /**
     * @brief Virtual Destructor for proper cleanup of Resource class in derived classes.
     */
    virtual ~Resource() = default;

    /**
     * @brief Retrieves the name of the resource.
     *
     * @return The name of the resource.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Checks if the resource is available for use.
     * @return True if the resource is available, false otherwise.
     */
    [[nodiscard]] virtual bool isAvailableForUse() const = 0;

    /**
     * @brief Allocates the resource for use.
     * @throws std::runtime_error if the resource is not available (e.g., already in use or depleted).
     */
    virtual void allocate() = 0;

    /**
     * @brief Releases the resource after use.
     */
    virtual void release() = 0;

    /**
     * @brief Defines how the resource is utilized during execution.
     */
    virtual void use() const = 0;

    /**
     * @brief Retrieves the type of the resource.
     *
     * @return The type of the resource (Consumable or Usable).
     */
    [[nodiscard]] Type getResourceType() const;
};
#endif //RESOURCE_H
