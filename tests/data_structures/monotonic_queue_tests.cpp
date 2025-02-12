#include <gtest/gtest.h>

#include "data_structures/monotonic_queue/monotonic_queue.h"

TTEST(MonotonicQueueTest, InitialSetup) {
    // Arrange.
    monotonic_queue<int> mq;

    //
    // Assert
    //

    // Initially the queue should be empty.
    EXPECT_TRUE(mq.empty());
    EXPECT_EQ(mq.size(), 0);
}

TTEST(MonotonicQueueTest, PushSingleElement) {
    // Arrange.
    int value = 5;
    monotonic_queue<int> mq;

    // Act.
    mq.push(value);

    // Assert.
    EXPECT_FALSE(mq.empty());
    EXPECT_EQ(mq.size(), 1);
    EXPECT_EQ(mq.front(), value);
    EXPECT_EQ(mq.max(), value);
    EXPECT_EQ(mq.min(), value);
}

TTEST(MonotonicQueueTest, PushMultipleElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 3, 1, 6, 1, 7 };
    monotonic_queue<int> mq;

    //
    // Act & Assert
    //

    int expected_max = values[0];
    int expected_min = values[0];

    for (int i = 0; i < values.size(); ++i) {
        // Push the value to the queue.
        mq.push(values[i]);

        // Update expected max & min.
        expected_max = std::max(expected_max, values[i]);
        expected_min = std::min(expected_min, values[i]);

        // Assert the size of the queue.
        EXPECT_EQ(mq.size(), i + 1);

        // Assert the front element.
        EXPECT_EQ(mq.front(), values[0]);

        // Assert the maximum & minimum values.
        EXPECT_EQ(mq.max(), expected_max);
        EXPECT_EQ(mq.min(), expected_min);
    }
}

TTEST(MonotonicQueueTest, PopSingleElement) {
    // Arrange.
    int value = 5;
    monotonic_queue<int> mq;

    // Act.
    mq.push(value);
    auto popped_value = mq.pop();

    // Assert.
    EXPECT_EQ(popped_value, value);
    EXPECT_EQ(mq.size(), 0);
    EXPECT_TRUE(mq.empty());
}

TTEST(MonotonicQueueTest, PopMultipleElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 5, 1, 1, 1, 7 };
    monotonic_queue<int> mq;

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        mq.push(values[i]);
    }

    // Pop the elements from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto popped_value = mq.pop();

        EXPECT_EQ(popped_value, values[i]);
    }

    // Assert the queue is empty.
    EXPECT_EQ(mq.size(), 0);
    EXPECT_TRUE(mq.empty());
}

TTEST(MonotonicQueueTest, GetMaxAndMinValues) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 3, 6, 2, 1, 4, 1, 1 };
    monotonic_queue<int> mq;

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(mq.max(), expected_max);
        EXPECT_EQ(mq.min(), expected_min);

        mq.pop();
    }
}

TTEST(MonotonicQueueTest, GetMaxAndMinValues_NonIncreasingElements) {
    // Arrange.
    std::vector<int> values = { 6, 5, 5, 5, 5, 5, 3, 3, 3, 2, 1 };
    monotonic_queue<int> mq;

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(mq.max(), expected_max);
        EXPECT_EQ(mq.min(), expected_min);

        mq.pop();
    }
}

TTEST(MonotonicQueueTest, GetMaxAndMinValues_NonDecreasingElements) {
    // Arrange.
    std::vector<int> values = { 1, 1, 1, 2, 3, 3, 5, 5, 5, 5, 6, 7, 7, 9 };
    monotonic_queue<int> mq;

    //
    // Act & Assert
    //

    // Push the values to the queue.
    for (int i = 0; i < values.size(); ++i) {
        mq.push(values[i]);
    }

    // Assert max and min values while popping from the queue.
    for (int i = 0; i < values.size(); ++i) {
        auto expected_max = *std::max_element(values.begin() + i, values.end());
        auto expected_min = *std::min_element(values.begin() + i, values.end());

        EXPECT_EQ(mq.max(), expected_max);
        EXPECT_EQ(mq.min(), expected_min);

        mq.pop();
    }
}