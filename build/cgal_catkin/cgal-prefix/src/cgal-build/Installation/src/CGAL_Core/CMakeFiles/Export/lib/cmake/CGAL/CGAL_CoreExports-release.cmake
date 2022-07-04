#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CGAL::CGAL_Core" for configuration "Release"
set_property(TARGET CGAL::CGAL_Core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CGAL::CGAL_Core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libCGAL_Core.so.13.0.3"
  IMPORTED_SONAME_RELEASE "libCGAL_Core.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS CGAL::CGAL_Core )
list(APPEND _IMPORT_CHECK_FILES_FOR_CGAL::CGAL_Core "${_IMPORT_PREFIX}/lib/libCGAL_Core.so.13.0.3" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
