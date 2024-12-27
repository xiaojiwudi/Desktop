# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dem_cpp_pkg_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dem_cpp_pkg_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dem_cpp_pkg_FOUND FALSE)
  elseif(NOT dem_cpp_pkg_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dem_cpp_pkg_FOUND FALSE)
  endif()
  return()
endif()
set(_dem_cpp_pkg_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dem_cpp_pkg_FIND_QUIETLY)
  message(STATUS "Found dem_cpp_pkg: 0.0.0 (${dem_cpp_pkg_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dem_cpp_pkg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dem_cpp_pkg_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dem_cpp_pkg_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dem_cpp_pkg_DIR}/${_extra}")
endforeach()
