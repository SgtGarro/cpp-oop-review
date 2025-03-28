#include "Resource.h"

Resource::Resource(const std::string& name, Type type) : name(name), resourceType(type), isAvailable(true) {}

std::string Resource::getName() const { return name;}

Resource::Type Resource::getResourceType() const { return resourceType; }
