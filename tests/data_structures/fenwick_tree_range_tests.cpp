#include <gtest/gtest.h>

#include "data_structures/fenwick_tree/fenwick_tree_range.h"

const int N = 50;

TEST(RangeFenwickTree, InitialSetup) {
    // Arrange.
    range_fenwick_tree<int, N> bit;

    //
    // Assert
    //

    // Initially all elements should be zeros.
    for (int i = 1; i <= N; ++i) {
        EXPECT_EQ(bit.prefix_sum(i), 0);
    }
}

TEST(RangeFenwickTree, UpdateSingleRange) {
    // Arrange.
    int l = 5, r = 9, value = 7;
    range_fenwick_tree<int, N> bit;

    // Act.
    bit.update(l, r, value);

    // Assert.
    EXPECT_EQ(bit.prefix_sum(l - 1), 0);
    EXPECT_EQ(bit.prefix_sum(r - 1), (r - l) * value);
    EXPECT_EQ(bit.prefix_sum(r), (r - l) * value);
}

TEST(RangeFenwickTree, UpdateOverlappingRanges) {
    // Arrange.
    int l1 = 2, r1 = 6, value1 = 7;
    int l2 = 5, r2 = 9, value2 = 3;
    range_fenwick_tree<int, N> bit;

    // Act.
    bit.update(l1, r1, value1);
    bit.update(l2, r2, value2);

    //
    // Assert
    //

    int sum = 0;

    for (int i = l1; i < l2; ++i) {
        sum += value1;
        EXPECT_EQ(bit.prefix_sum(i), sum);
    }

    for (int i = l2; i < r1; ++i) {
        sum += value1 + value2;
        EXPECT_EQ(bit.prefix_sum(i), sum);
    }

    for (int i = r1; i < r2; ++i) {
        sum += value2;
        EXPECT_EQ(bit.prefix_sum(i), sum);
    }
}
