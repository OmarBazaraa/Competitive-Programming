#include <gtest/gtest.h>

#include <vector>

#include "data_structures/fenwick_tree/fenwick_tree.h"

const int N = 50;

TEST(FenwickTree, InitialSetup) {
    // Arrange.
    fenwick_tree<int, N> bit;

    //
    // Assert
    //

    // Initially all elements should be zeros.
    for (int i = 1; i <= N; ++i) {
        EXPECT_EQ(bit.prefix_sum(i), 0);
    }
}

TEST(FenwickTree, UpdateSingleElement) {
    // Arrange.
    int element = 5, value = 7;
    fenwick_tree<int, N> bit;

    // Act.
    bit.update(element, value);

    //
    // Assert
    //

    // All prefix sums up to the 5th element should be 0.
    for (int i = 1; i < element; ++i) {
        EXPECT_EQ(bit.prefix_sum(i), 0);
    }

    // All prefix sums up to the 5th element should be 0.
    for (int i = element; i <= N; ++i) {
        EXPECT_EQ(bit.prefix_sum(i), value);
    }
}

TEST(FenwickTree, UpdateSingleElementMultipleTimes) {
    // Arrange.
    int element = 5;
    int x = 7, y = 3, z = 1;
    fenwick_tree<int, N> bit;

    // Act.
    bit.update(element, x);
    bit.update(element, y);
    bit.update(element, z);

    // Assert.
    EXPECT_EQ(bit.prefix_sum(element), x + y + z);
}

TEST(FenwickTree, ComputePrefixSum) {
    // Arrange.
    std::vector<int> values = { 1, 7, 2, 3, 9, 10, -5, 6, 1, 1, 1 };
    fenwick_tree<int, N> bit;

    //
    // Act & Assert
    //

    for (int i = 0, sum = 0; i < values.size(); ++i) {
        // Update the tree with the current value.
        bit.update(i + 1, values[i]);

        // Update the prefix sum.
        sum += values[i];

        // Assert the prefix sum up to the current index.
        EXPECT_EQ(bit.prefix_sum(i + 1), sum);
    }
}
