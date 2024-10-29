#pragma once
#include <gtest/gtest.h>
#include "Array.hpp"

template<typename ReturnValue, typename ClassValue>
void array_return_test(const ClassValue* makedInstance, ReturnValue (ClassValue::*method)() const, const ReturnValue expect) {
    EXPECT_EQ((makedInstance->*method)(), expect);
    delete makedInstance;
}

