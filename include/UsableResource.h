#ifndef USABLERESOURCE_H
#define USABLERESOURCE_H

#include "Resource.h"

class UsableResource : public Resource {
private:
    int capacity;  ///< Fixed capacity of the resource (e.g., GHz for CPU).

public:
    UsableResource(const std::string& name, int capacity);
    bool isAvailableForUse() const override;
    void allocate() override;
    void release() override;
    void use() const override;
};
#endif //USABLERESOURCE_H
