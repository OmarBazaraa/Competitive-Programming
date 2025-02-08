#include <gtest/gtest.h>

#include "data_structures/disjoint_sets/dsu.h"

TEST(dsu, InitialSetup) {
    // Arrange.
    int n = 10;
    dsu dsu(n);

    //
    // Assert
    //

    // Initially we should have `n` disjoint sets.
    EXPECT_EQ(dsu.size(), n);

    // And each element should be in its own set.
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(dsu.count(i), 1);
    }
}

TEST(dsu, UnionTwoSets) {
    // Arrange.
    dsu dsu(3);
    
    // Act.
    auto flag = dsu.merge(0, 1);

    //
    // Assert
    //

    EXPECT_TRUE(flag);

    // 0 & 1 should be in the same set.
    EXPECT_TRUE(dsu.same_set(0, 1));
    EXPECT_EQ(dsu.find_id(0), dsu.find_id(1));
    EXPECT_EQ(dsu.count(0), 2);

    // 2 should be in its own set.
    EXPECT_FALSE(dsu.same_set(0, 2));
    EXPECT_FALSE(dsu.same_set(1, 2));

    // We should have 2 disjoint sets.
    EXPECT_EQ(dsu.size(), 2);
}

TEST(dsu, UnionAlreadyMergedSets) {
    // Arrange.
    dsu dsu(3);

    // Act.
    dsu.merge(0, 1);
    auto flag = dsu.merge(0, 1);

    //
    // Assert
    //

    EXPECT_FALSE(flag);

    // 0 & 1 should be in the same set.
    EXPECT_TRUE(dsu.same_set(0, 1));
    EXPECT_EQ(dsu.find_id(0), dsu.find_id(1));
    EXPECT_EQ(dsu.count(0), 2);

    // 2 should be in its own set.
    EXPECT_FALSE(dsu.same_set(0, 2));
    EXPECT_FALSE(dsu.same_set(1, 2));

    // We should have 2 disjoint sets.
    EXPECT_EQ(dsu.size(), 2);
}

TEST(dsu, OutOfRangeAccess) {
    // Arrange.
    int n = 10;
    dsu dsu(n);

    //
    // Assert
    //

    ASSERT_DEATH(dsu.count(-1), ".*");
    ASSERT_DEATH(dsu.count(n), ".*");
    ASSERT_DEATH(dsu.count(n + 1), ".*");
}