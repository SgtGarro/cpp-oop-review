#include "Resource.h"

/**
 * @brief Constructor for the Resource with the given name and type.
 *
 * @param name Unique name of the resource.
 * @param type Type of the resource (Consumable or Usable).
 */
Resource::Resource(std::string  name, const Type type)
: name(std::move(name)), isAvailable(true), resourceType(type) {}

/**
 * @brief Retrieves the name of the resource.
 *
 * @return The name of the resource.
 */
std::string Resource::getName() const { return name;}

/**
 * @brief Retrieves the type of the resource.
 *
 * @return The type of the resource (Consumable or Usable).
 */
Resource::Type Resource::getResourceType() const { return resourceType; }
