#include "UsableResource.h"
#include <iostream>
#include <stdexcept>

UsableResource::UsableResource(const std::string& name, const int capacity)
    : Resource(name, Type::Usable), capacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be positive");
    }
}

bool UsableResource::isAvailableForUse() const {
    return isAvailable;
}

void UsableResource::allocate() {
    if (!isAvailable) {
        throw std::runtime_error("Usable resource '" + name + "' is already allocated");
    }
    isAvailable = false;
}

void UsableResource::release() {
    if (isAvailable) {
        std::cerr << "Warning: Attempted to release already free usable resource '" << name << "'\n";
    }
    isAvailable = true;
}

void UsableResource::use() const {
    std::cout << "    Using usable resource '" << name << "' (capacity: " << capacity << " GHz)\n";
}

