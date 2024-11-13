#pragma once
#include <gtest/gtest.h>
#include "Array.hpp"

template<typename ResultType, typename Class>
void array_return_test(const Class* makedInstance, ResultType (Class::*method)() const, const ResultType expect) {
    EXPECT_EQ((makedInstance->*method)(), expect);
    delete makedInstance;
}

