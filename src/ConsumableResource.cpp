//
// Created by Angel Velasquez on 27/03/25.
//

#include "ConsumableResource.h"
#include <stdexcept>
#include <iostream>

ConsumableResource::ConsumableResource(const std::string& name, int capacity)
    : Resource(name, Type::Consumable), totalCapacity(capacity), remainingCapacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be positive");
    }
}

bool ConsumableResource::isAvailableForUse() const {
    return remainingCapacity > 0;
}

void ConsumableResource::allocate() {
    if (remainingCapacity <= 0) {
        throw std::runtime_error("No remaining capacity for consumable resource '" + name + "'");
    }
    remainingCapacity--;
    isAvailable = (remainingCapacity > 0);
}

void ConsumableResource::release() {
    if (remainingCapacity == 0 && !isAvailable) {
        std::cerr << "Warning: Consumable resource '" << name << "' is depleted and cannot be reused without replenishment\n";
    }
    isAvailable = (remainingCapacity > 0);
}

void ConsumableResource::use() const {
    std::cout << "    Using consumable resource '" << name << "' (remaining: " << remainingCapacity << "/" << totalCapacity << " MB)\n";
}

int ConsumableResource::getRemainingCapacity() const {
    return remainingCapacity;
}