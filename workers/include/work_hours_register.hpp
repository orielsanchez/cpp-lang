#ifndef WORK_HOURS_REGISTER_HPP
#define WORK_HOURS_REGISTER_HPP

#include <optional>
#include <string>
#include <vector>

struct WorkerInfo {
    std::string position;
    int compensation;
    std::vector<int> timestamps;
};

struct WorkHoursRegister {
  public:
    virtual ~WorkHoursRegister() = default;
    virtual bool addWorker(const std::string &worker_id, const std::string &position, int compensation) = 0;
    virtual bool Register(const std::string &worker_id, int timestamp) = 0;
    virtual std::optional<int> Get(const std::string &worker_id) const = 0;
};

#endif // WORK_HOURS_REGISTER_HPP
