# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_status_dispaly_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED status_dispaly_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(status_dispaly_FOUND FALSE)
  elseif(NOT status_dispaly_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(status_dispaly_FOUND FALSE)
  endif()
  return()
endif()
set(_status_dispaly_CONFIG_INCLUDED TRUE)

# output package information
if(NOT status_dispaly_FIND_QUIETLY)
  message(STATUS "Found status_dispaly: 0.0.0 (${status_dispaly_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'status_dispaly' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${status_dispaly_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(status_dispaly_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${status_dispaly_DIR}/${_extra}")
endforeach()
