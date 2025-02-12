#include <gtest/gtest.h>

#include <vector>
#include <set>

#include <algorithm>

#include "data_structures/treap/treap.h"

TEST(TreapMultiset, InitialSetup) {
    // Arrange.
    treap_multiset multiset;

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

TEST(TreapMultiset, InsertSingleElement) {
    // Arrange.
    int element = 5;
    treap_multiset multiset;

    // Act.
    multiset.insert(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 1);
    EXPECT_EQ(multiset.count(element), 1);
}

TEST(TreapMultiset, InsertSingleElementMultipleTimes) {
    // Arrange.
    int element = 5;
    treap_multiset multiset;

    // Act.
    multiset.insert(element);
    multiset.insert(element);
    multiset.insert(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 3);
    EXPECT_EQ(multiset.count(element), 3);
}

TEST(TreapMultiset, InsertElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 5, 1, 1, 1, 7 };
    std::multiset<int> std_multiset;
    treap_multiset multiset;

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

TEST(TreapMultiset, EraseSingleElement) {
    // Arrange.
    int element = 5;
    treap_multiset multiset;

    // Act.
    multiset.insert(element);
    multiset.insert(element);
    multiset.erase(element);

    // Assert.
    EXPECT_EQ(multiset.size(), 1);
    EXPECT_EQ(multiset.count(element), 1);
}

TEST(TreapMultiset, EraseNonExistingElement) {
    // Arrange.
    treap_multiset multiset;

    // Act.
    multiset.insert(1);
    multiset.insert(2);
    auto flag = multiset.erase(7);

    // Assert.
    EXPECT_FALSE(flag);
    EXPECT_EQ(multiset.size(), 2);
}

TEST(TreapMultiset, ClearElements) {
    // Arrange.
    treap_multiset multiset;

    // Act.
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(3);
    multiset.clear();

    // Assert.
    EXPECT_EQ(multiset.size(), 0);
}

TEST(TreapMultiset, GetElementsByIndex) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    treap_multiset multiset;

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
        EXPECT_EQ(multiset[i], sorted_values[i]);
    }
}

TEST(TreapMultiset, FindLowerBound_EmptySet) {
    // Arrange.
    treap_multiset multiset;

    // Act & Assert.
    EXPECT_EQ(multiset.lower_bound(1), multiset.size());
    EXPECT_EQ(multiset.lower_bound(7), multiset.size());
}

TEST(TreapMultiset, FindLowerBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    treap_multiset multiset;

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
        EXPECT_EQ(multiset.lower_bound(i), expected);
    }
}

TEST(TreapMultiset, FindUpperBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };
    treap_multiset multiset;

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
        EXPECT_EQ(multiset.upper_bound(i), expected);
    }
}
