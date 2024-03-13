// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <uur/fixtures.h>

using urProgramCompileTest = uur::urProgramTest;
UUR_INSTANTIATE_KERNEL_TEST_SUITE_P(urProgramCompileTest);

TEST_P(urProgramCompileTest, Success) {
    ASSERT_SUCCESS(urProgramCompile(context, program, nullptr));
}

TEST_P(urProgramCompileTest, InvalidNullHandleContext) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_HANDLE,
                     urProgramCompile(nullptr, program, nullptr));
}

TEST_P(urProgramCompileTest, InvalidNullHandleProgram) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_HANDLE,
                     urProgramCompile(context, nullptr, nullptr));
}

TEST_P(urProgramCompileTest, InvalidCompileOptions) {
    ASSERT_SUCCESS(urProgramCompile(context, program, "asdaf"));

    size_t logSize;
    std::vector<char> log;

    ASSERT_SUCCESS(urProgramGetBuildInfo(
        program, device, UR_PROGRAM_BUILD_INFO_LOG, 0, nullptr, &logSize));
    log.resize(logSize);
    log[logSize - 1] = 'x';
    ASSERT_SUCCESS(urProgramGetBuildInfo(program, device,
                                         UR_PROGRAM_BUILD_INFO_LOG, logSize,
                                         log.data(), nullptr));
    ASSERT_EQ(std::string{log.data()}, "hello");
}
