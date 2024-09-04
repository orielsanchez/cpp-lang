#ifndef WORK_HOURS_REGIST_IMPL_CPP
#define WORK_HOURS_REGIST_IMPL_CPP

#include "work_hours_register_impl.hpp"
#include <optional>

bool WorkHoursRegisterImpl::addWorker(const std::string &worker_id, const std::string &position, int compensation) {
    return true;
}

bool WorkHoursRegisterImpl::Register(const std::string &worker_id, int timestamp) {
    return true;
}

std::optional<int> WorkHoursRegisterImpl::Get(const std::string &worker_id) const {
    return 0;
}

#endif // !WORK_HOURS_REGIST_IMPL_CPP
