#include <gtest/gtest.h>

#include <vector>
#include <set>

#include <algorithm>

#include "data_structures/fenwick_tree/fenwick_multiset.h"

TEST(FenwickMultiset, InitialSetup) {
    // Arrange.
    fenwick_multiset<10> multiset;

    //
    // Assert
    //

    // Initially the multiset should be empty.
    EXPECT_EQ(multiset.size(), 0);

    // All elements should have a count of 0.
    for (int i = 1; i <= 20; ++i) {
        EXPECT_EQ(multiset.count(i), 0);
    }
}

TEST(FenwickMultiset, InsertSingleElement) {
    // Arrange.
    int element = 5;
    fenwick_multiset<10> multiset;

    // Act.
    multiset.insert(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 1);
    EXPECT_EQ(multiset.count(element), 1);
}

TEST(FenwickMultiset, InsertSingleElementMultipleTimes) {
    // Arrange.
    int element = 5;
    fenwick_multiset<10> multiset;

    // Act.
    multiset.insert(element);
    multiset.insert(element);
    multiset.insert(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 3);
    EXPECT_EQ(multiset.count(element), 3);
}

TEST(FenwickMultiset, InsertElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 5, 1, 1, 1, 7 };
    std::multiset<int> std_multiset;
    fenwick_multiset<10> multiset;

    //
    // Act & Assert
    //

    for (int i = 0; i < values.size(); ++i) {
        // Insert the value to the multiset.
        multiset.insert(values[i]);
        std_multiset.insert(values[i]);

        // Assert the size of the multiset.
        EXPECT_EQ(multiset.size(), std_multiset.size());

        // Assert the count of each element.
        EXPECT_EQ(multiset.count(values[i]), std_multiset.count(values[i]));
    }
}

TEST(FenwickMultiset, EraseSingleElement) {
    // Arrange.
    int element = 5;
    fenwick_multiset<10> multiset;

    // Act.
    multiset.insert(element);
    multiset.insert(element);
    multiset.erase(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 1);
    EXPECT_EQ(multiset.count(element), 1);
}

TEST(FenwickMultiset, EraseNonExistingElement) {
    // Arrange.
    fenwick_multiset<10> multiset;

    // Act.
    multiset.insert(1);
    multiset.insert(2);
    auto flag = multiset.erase(7);

    // Assert.
    EXPECT_FALSE(flag);
    EXPECT_EQ(multiset.size(), 2);
}

TEST(FenwickMultiset, ClearElements) {
    // Arrange.
    fenwick_multiset<10> multiset;

    // Act.
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(3);
    multiset.clear();

    // Assert.
    EXPECT_EQ(multiset.size(), 0);
}

TEST(FenwickMultiset, GetElementsByIndex) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    fenwick_multiset<10> multiset;

    // Insert the values to the multiset.
    for (int v : values) {
        multiset.insert(v);
    }

    // Sort the values to get the expected result.
    auto sorted_values = values;
    std::sort(sorted_values.begin(), sorted_values.end());

    //
    // Act & Assert
    //

    for (int i = 0; i < values.size(); ++i) {
        // Note that the multiset is 1-indexed.
        EXPECT_EQ(multiset[i + 1], sorted_values[i]);
    }
}

TEST(FenwickMultiset, FindLowerBound_EmptySet) {
    // Arrange.
    fenwick_multiset<10> multiset;

    // Act & Assert.
    EXPECT_EQ(multiset.lower_bound(1), multiset.size() + 1);
    EXPECT_EQ(multiset.lower_bound(7), multiset.size() + 1);
}

TEST(FenwickMultiset, FindLowerBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    fenwick_multiset<10> multiset;

    // Insert the values to the multiset.
    for (int v : values) {
        multiset.insert(v);
    }

    // Sort the values to get the expected lower bound.
    auto sorted_values = values;
    std::sort(sorted_values.begin(), sorted_values.end());

    //
    // Act & Assert
    //

    for (int i = 0; i < 20; ++i) {
        // Get the expected lower bound.
        int expected = std::lower_bound(sorted_values.begin(), sorted_values.end(), i) - sorted_values.begin();

        // Assert the lower bound.
        // Note that the multiset is 1-indexed.
        EXPECT_EQ(multiset.lower_bound(i), expected + 1);
    }
}

TEST(FenwickMultiset, FindUpperBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    fenwick_multiset<10> multiset;

    // Insert the values to the multiset.
    for (int v : values) {
        multiset.insert(v);
    }

    // Sort the values to get the expected lower bound.
    auto sorted_values = values;
    std::sort(sorted_values.begin(), sorted_values.end());

    //
    // Act & Assert
    //

    for (int i = 0; i < 20; ++i) {
        // Get the expected lower bound.
        int expected = std::upper_bound(sorted_values.begin(), sorted_values.end(), i) - sorted_values.begin();

        // Assert the lower bound.
        // Note that the multiset is 1-indexed.
        EXPECT_EQ(multiset.upper_bound(i), expected + 1);
    }
}
