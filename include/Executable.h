#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "Resource.h"
#include <string>
#include <vector>
#include <memory>


class Executable {
protected:
  std::string name;
  std::string description;
  std::vector<std::string> requiredResourcesNames;
  int durationInUnits;
  std::vector<Resource*> assignedResources;
public:
  Executable(const std::string &name, const std::string &description,
             const std::vector<std::string> &requiredResourcesNames, int durationInUnits);

  virtual ~Executable();
  std::string getName() const;
  const std::vector<std::string>& getRequiredResourcesNames() const;
  int getDurationInUnits() const;
  void assignResources(const std::vector<std::unique_ptr<Resource>>& resourcePool);
  void releaseResources();
  virtual void execute() const = 0;
  bool canExecute(const std::vector<std::unique_ptr<Resource>>& resourcePool) const;
};

#endif //EXECUTABLE_H
