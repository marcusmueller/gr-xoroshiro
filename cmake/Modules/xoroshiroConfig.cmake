INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_XOROSHIRO xoroshiro)

FIND_PATH(
    XOROSHIRO_INCLUDE_DIRS
    NAMES xoroshiro/api.h
    HINTS $ENV{XOROSHIRO_DIR}/include
        ${PC_XOROSHIRO_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    XOROSHIRO_LIBRARIES
    NAMES gnuradio-xoroshiro
    HINTS $ENV{XOROSHIRO_DIR}/lib
        ${PC_XOROSHIRO_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(XOROSHIRO DEFAULT_MSG XOROSHIRO_LIBRARIES XOROSHIRO_INCLUDE_DIRS)
MARK_AS_ADVANCED(XOROSHIRO_LIBRARIES XOROSHIRO_INCLUDE_DIRS)

