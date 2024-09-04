#ifndef WORK_HOURS_REGISTER_IMPL_HPP
#define WORK_HOURS_REGISTER_IMPL_HPP

#include "work_hours_register.hpp"
#include <unordered_map>

class WorkHoursRegisterImpl : public WorkHoursRegister {
  private:
    std::unordered_map<std::string, WorkerInfo> WorkerRegistry;

  public:
    bool addWorker(const std::string &worker_id, const std::string &position,
                   int compensation) override;
    bool Register(const std::string &worker_id, int timestamp) override;
    std::optional<int> Get(const std::string &worker_id) const override;
};

#endif // !WORK_HOURS_REGISTER_IMPL_HPP
