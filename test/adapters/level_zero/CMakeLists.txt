# Copyright (C) 2023 Intel Corporation
# Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
# See LICENSE.TXT
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

add_adapter_test(level_zero
    FIXTURE KERNELS
    SOURCES
        fixtures.h
        urProgramLink.cpp
    ENVIRONMENT
        "UR_ADAPTERS_FORCE_LOAD=\"$<TARGET_FILE:ur_adapter_level_zero>\""
)

target_include_directories(test-adapter-level_zero PRIVATE
    ${PROJECT_SOURCE_DIR}/source
    ${PROJECT_SOURCE_DIR}/source/adapters/level_zero
)


add_dependencies(test-adapter-level_zero kernel_names_header)
