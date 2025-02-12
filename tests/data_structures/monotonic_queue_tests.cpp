#include <gtest/gtest.h>

#include "data_structures/monotonic_queue/monotonic_queue.h"
#include "data_structures/monotonic_queue/monotonic_queue_using_stacks.h"

// A fixture class template for testing monotonic queues.
template <typename T>
class MonotonicQueue : public testing::Test {
public:
    T mq;
};

// The list of types to test.
using MyTypes = ::testing::Types<
    monotonic_queue<int>,
    monotonic_queue_using_stacks<int>
>;

// Define the test suite.
TYPED_TEST_SUITE(MonotonicQueue, MyTypes);

//
// Test Cases
//

TYPED_TEST(MonotonicQueue, InitialSetup) {
    // Initially the queue should be empty.
    EXPECT_TRUE(this->mq.empty());
    EXPECT_EQ(this->mq.size(), 0);
}

TYPED_TEST(MonotonicQueue, PushSingleElement) {
    // Arrange.
    int value = 5;

    // Act.
    this->mq.push(value);

    // Assert.
    EXPECT_FALSE(this->mq.empty());
    EXPECT_EQ(this->mq.size(), 1);
    EXPECT_EQ(this->mq.front(), value);
    EXPECT_EQ(this->mq.max(), value);
    EXPECT_EQ(this->mq.min(), value);
}

TYPED_TEST(MonotonicQueue, PushMultipleElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 3, 1, 6, 1, 7 };

    //
    // Act & Assert
    //

    int expected_max = values[0];
    int expected_min = values[0];

    for (int i = 0; i < values.size(); ++i) {
        // Push the value to the queue.
        this->mq.push(values[i]);

        // Update expected max & min.
        expected_max = std::max(expected_max, values[i]);
        expected_min = std::min(expected_min, values[i]);

        // Assert the size of the queue.
        EXPECT_EQ(this->mq.size(), i + 1);

        // Assert the front element.
        EXPECT_EQ(this->mq.front(), values[0]);

        // Assert the maximum & minimum values.
        EXPECT_EQ(this->mq.max(), expected_max);
        EXPECT_EQ(this->mq.min(), expected_min);
    }
}

TYPED_TEST(MonotonicQueue, PopSingleElement) {
    // Arrange.
    int value = 5;

    // Act.
    this->mq.push(value);
    auto popped_value = this->mq.pop();

    // Assert.
    EXPECT_EQ(popped_value, value);
    EXPECT_EQ(this->mq.size(), 0);
    EXPECT_TRUE(this->mq.empty());
}

TYPED_TEST(MonotonicQueue, PopMultipleElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 5, 1, 1, 1, 7 };

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        this->mq.push(values[i]);
    }

    // Pop the elements from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto popped_value = this->mq.pop();

        EXPECT_EQ(popped_value, values[i]);
    }

    // Assert the queue is empty.
    EXPECT_EQ(this->mq.size(), 0);
    EXPECT_TRUE(this->mq.empty());
}

TYPED_TEST(MonotonicQueue, GetMaxAndMinValues) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 3, 6, 2, 1, 4, 1, 1 };

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        this->mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(this->mq.max(), expected_max);
        EXPECT_EQ(this->mq.min(), expected_min);

        this->mq.pop();
    }
}

TYPED_TEST(MonotonicQueue, GetMaxAndMinValues_NonIncreasingElements) {
    // Arrange.
    std::vector<int> values = { 6, 5, 5, 5, 5, 5, 3, 3, 3, 2, 1 };

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        this->mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(this->mq.max(), expected_max);
        EXPECT_EQ(this->mq.min(), expected_min);

        this->mq.pop();
    }
}

TYPED_TEST(MonotonicQueue, GetMaxAndMinValues_NonDecreasingElements) {
    // Arrange.
    std::vector<int> values = { 1, 1, 1, 2, 3, 3, 5, 5, 5, 5, 6, 7, 7, 9 };

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        this->mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(this->mq.max(), expected_max);
        EXPECT_EQ(this->mq.min(), expected_min);

        this->mq.pop();
    }
}