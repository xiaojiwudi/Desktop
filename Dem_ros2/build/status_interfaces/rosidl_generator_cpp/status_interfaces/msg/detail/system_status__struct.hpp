// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from status_interfaces:msg/SystemStatus.idl
// generated code does not contain a copyright notice

#ifndef STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_HPP_
#define STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__status_interfaces__msg__SystemStatus __attribute__((deprecated))
#else
# define DEPRECATED__status_interfaces__msg__SystemStatus __declspec(deprecated)
#endif

namespace status_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SystemStatus_
{
  using Type = SystemStatus_<ContainerAllocator>;

  explicit SystemStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->host_name = "";
      this->cpu_percent = 0.0f;
      this->memory_percent = 0.0f;
      this->memory_total = 0.0f;
      this->memory_available = 0.0f;
      this->net_sent = 0.0;
      this->net_recv = 0.0;
    }
  }

  explicit SystemStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    host_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->host_name = "";
      this->cpu_percent = 0.0f;
      this->memory_percent = 0.0f;
      this->memory_total = 0.0f;
      this->memory_available = 0.0f;
      this->net_sent = 0.0;
      this->net_recv = 0.0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _host_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _host_name_type host_name;
  using _cpu_percent_type =
    float;
  _cpu_percent_type cpu_percent;
  using _memory_percent_type =
    float;
  _memory_percent_type memory_percent;
  using _memory_total_type =
    float;
  _memory_total_type memory_total;
  using _memory_available_type =
    float;
  _memory_available_type memory_available;
  using _net_sent_type =
    double;
  _net_sent_type net_sent;
  using _net_recv_type =
    double;
  _net_recv_type net_recv;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__host_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->host_name = _arg;
    return *this;
  }
  Type & set__cpu_percent(
    const float & _arg)
  {
    this->cpu_percent = _arg;
    return *this;
  }
  Type & set__memory_percent(
    const float & _arg)
  {
    this->memory_percent = _arg;
    return *this;
  }
  Type & set__memory_total(
    const float & _arg)
  {
    this->memory_total = _arg;
    return *this;
  }
  Type & set__memory_available(
    const float & _arg)
  {
    this->memory_available = _arg;
    return *this;
  }
  Type & set__net_sent(
    const double & _arg)
  {
    this->net_sent = _arg;
    return *this;
  }
  Type & set__net_recv(
    const double & _arg)
  {
    this->net_recv = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    status_interfaces::msg::SystemStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const status_interfaces::msg::SystemStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      status_interfaces::msg::SystemStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      status_interfaces::msg::SystemStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__status_interfaces__msg__SystemStatus
    std::shared_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__status_interfaces__msg__SystemStatus
    std::shared_ptr<status_interfaces::msg::SystemStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemStatus_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->host_name != other.host_name) {
      return false;
    }
    if (this->cpu_percent != other.cpu_percent) {
      return false;
    }
    if (this->memory_percent != other.memory_percent) {
      return false;
    }
    if (this->memory_total != other.memory_total) {
      return false;
    }
    if (this->memory_available != other.memory_available) {
      return false;
    }
    if (this->net_sent != other.net_sent) {
      return false;
    }
    if (this->net_recv != other.net_recv) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemStatus_

// alias to use template instance with default allocator
using SystemStatus =
  status_interfaces::msg::SystemStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace status_interfaces

#endif  // STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_HPP_
