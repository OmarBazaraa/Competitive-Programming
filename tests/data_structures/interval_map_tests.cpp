#include <gtest/gtest.h>

#include <vector>

#include "data_structures/interval_map/interval_map.h"

TEST(IntervalMap, InitialSetup) {
    // Arrange.
    int default_value = -1;
    interval_map<int, int> map(default_value);

    //
    // Assert
    //

    // Initially all keys should have the default value.
    for (int i = -10; i < 10; ++i) {
        EXPECT_EQ(map[i], default_value);
    }
}

TEST(IntervalMap, AssignSingleInterval) {
    // Arrange.
    int default_value = -1;
    int l = 1, r = 5, value = 7;
    interval_map<int, int> map(default_value);

    // Act.
    map.assign(l, r, value);

    //
    // Assert
    //
    
    // The interval [1, 5) should have the value 7.
    for (int i = l; i < r; ++i) {
        EXPECT_EQ(map[i], value);
    }

    // The point 5 should have the default value.
    EXPECT_EQ(map[r], default_value);
}

TEST(IntervalMap, AssignOverlappingIntervals) {
    // Arrange.
    int default_value = -1;
    int l1 = 1, r1 = 5, value1 = 7;
    int l2 = 3, r2 = 9, value2 = 2;
    interval_map<int, int> map(default_value);

    // Act.
    map.assign(l1, r1, value1);
    map.assign(l2, r2, value2);

    //
    // Assert
    //

    // The interval [1, 3) should have the value 7.
    for (int i = l1; i < l2; ++i) {
        EXPECT_EQ(map[i], value1);
    }

    // The interval [3, 9) should have the value 7.
    for (int i = l2; i < r2; ++i) {
        EXPECT_EQ(map[i], value2);
    }
}

TEST(IntervalMap, ClearIntervals) {
    // Arrange.
    int default_value = -1;
    int l = 1, r = 5, value = 7;
    interval_map<int, int> map(default_value);

    // Act.
    map.assign(l, r, value);
    map.clear();

    // Assert.
    for (int i = l; i < r; ++i) {
        EXPECT_EQ(map[i], default_value);
    }
}

TEST(IntervalMap, ClearIntervalsAndUpdateDefaultValue) {
    // Arrange.
    int default_value = -1;
    int new_default_value = 2;
    int l = 1, r = 5, value = 7;
    interval_map<int, int> map(default_value);

    // Act.
    map.assign(l, r, value);
    map.clear(new_default_value);

    // Assert.
    for (int i = l; i < r; ++i) {
        EXPECT_EQ(map[i], new_default_value);
    }
}