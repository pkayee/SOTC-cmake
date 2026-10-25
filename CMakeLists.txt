# Shadow of the Colossus decompilation, CMake build.
#
#   cmake --preset default && cmake --build out && ctest --test-dir out
#
# Files:  cmake/Dependencies.cmake  venv, compiler download, tool and game-file checks
#         cmake/Toolchain.cmake     assembler, python, patcher settings and quirks
#         cmake/Decomp.cmake        the rules: objects -> link -> objcopy -> sha1 test
#
# Options (-D<NAME>=...): SOTC_MODULES, DECOMP_AUTO_SETUP, DECOMP_CROSS, DECOMP_CC, DECOMP_PYTHON,
#                         DECOMP_NUMERIC_REGS, DECOMP_EEGCC_URL, DECOMP_EEGCC_SHA256

cmake_minimum_required(VERSION 3.20)
project(sotc LANGUAGES NONE)

# The one place a module is registered:  <target name>:<basename>
# (basename = the file in iso/ and config/<basename>/<basename>.yaml)
set(SOTC_ALL_MODULES
        loader:SCPS_150.97
        kernel:KERNEL.XFF
        gamecore:GAMECORE.XFF
        manager:MANAGER.XFF
        dbgcore:DBGCORE.XFF
        dbgmgr:DBGMGR.XFF
        grptools:GRPTOOLS.XFF
        maptool:MAPTOOL.XFF
        pathtool:PATHTOOL.XFF
        prttool:PRTTOOL.XFF
)


set(SOTC_MODULES "all" CACHE STRING "modules to extract and build: 'all', or a list like 'loader' or 'loader;kernel'")

set(SOTC_ENABLED "")
set(SOTC_ENABLED_BASENAMES "")
set(_known "")
foreach (_entry IN LISTS SOTC_ALL_MODULES)
    string(REPLACE ":" ";" _pair "${_entry}")
    list(GET _pair 0 _name)
    list(GET _pair 1 _base)
    list(APPEND _known ${_name})
    if (SOTC_MODULES STREQUAL "all" OR _name IN_LIST SOTC_MODULES)
        list(APPEND SOTC_ENABLED "${_entry}")
        list(APPEND SOTC_ENABLED_BASENAMES ${_base})
    endif ()
endforeach ()
foreach (_m IN LISTS SOTC_MODULES)          # a typo should not silently build nothing
    if (NOT _m STREQUAL "all" AND NOT _m IN_LIST _known)
        message(FATAL_ERROR "Unknown module '${_m}'. Known modules: ${_known}")
    endif ()
endforeach ()
if (NOT SOTC_ENABLED)
    message(FATAL_ERROR "SOTC_MODULES='${SOTC_MODULES}' selects no module. Known modules: ${_known}")
endif ()

enable_testing()                       # before the modules, or the sha1 tests are not registered

if (NOT FAST_BUILD)
    include(cmake/Dependencies.cmake)
endif ()

if (NOT FAST_BUILD)
    decomp_check_dependencies()
endif()                            
include(cmake/Toolchain.cmake)         # assembler, python, patcher settings
include(cmake/Decomp.cmake)            # the build rules

foreach (_entry IN LISTS SOTC_ENABLED)
    string(REPLACE ":" ";" _pair "${_entry}")
    list(GET _pair 0 _name)
    list(GET _pair 1 _base)
    decomp_add_module(${_name} BASENAME ${_base})
endforeach ()
