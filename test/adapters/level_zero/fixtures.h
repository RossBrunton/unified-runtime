// Copyright (C) 2022-2024 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef UR_TEST_CONFORMANCE_ADAPTERS_LEVEL_ZERO_FIXTURES_H_INCLUDED
#define UR_TEST_CONFORMANCE_ADAPTERS_LEVEL_ZERO_FIXTURES_H_INCLUDED
#include <cuda.h>
#include <uur/fixtures.h>

namespace uur {
struct ResultLevelZero {

    constexpr ResultLevelZero(CUresult result) noexcept : value(result) {}

    inline bool operator==(const ResultLevelZero &rhs) const noexcept {
        return rhs.value == value;
    }

    CUresult value;
};

} // namespace uur

#ifndef ASSERT_EQ_RESULT_LEVEL_ZERO
#define ASSERT_EQ_RESULT_LEVEL_ZERO(EXPECTED, ACTUAL)                          \
    ASSERT_EQ(uur::ResultCuda(EXPECTED), uur::ResultCuda(ACTUAL))
#endif // ASSERT_EQ_RESULT_LEVEL_ZERO

#ifndef ASSERT_SUCCESS_LEVEL_ZERO
#define ASSERT_SUCCESS_LEVEL_ZERO(ACTUAL)                                      \
    ASSERT_EQ_RESULT_LEVEL_ZERO(LEVEL_ZERO_SUCCESS, ACTUAL)
#endif // ASSERT_SUCCESS_LEVEL_ZERO

#ifndef EXPECT_EQ_RESULT_LEVEL_ZERO
#define EXPECT_EQ_RESULT_LEVEL_ZERO(EXPECTED, ACTUAL)                          \
    EXPECT_EQ(uur::ResultCuda(EXPECTED), uur::ResultCuda(ACTUAL))
#endif // EXPECT_EQ_RESULT_LEVEL_ZERO

#ifndef EXPECT_SUCCESS_LEVEL_ZERO
#define EXPECT_SUCCESS_LEVEL_ZERO(ACTUAL)                                      \
    EXPECT_EQ_RESULT_LEVEL_ZERO(LEVEL_ZERO_SUCCESS, ACTUAL)
#endif // EXPECT_EQ_RESULT_LEVEL_ZERO

#endif // UR_TEST_CONFORMANCE_ADAPTERS_LEVEL_ZERO_FIXTURES_H_INCLUDED
