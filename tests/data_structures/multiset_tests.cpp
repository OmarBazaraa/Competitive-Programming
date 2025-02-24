#include <gtest/gtest.h>

#include <vector>
#include <set>
#include <algorithm>

#include "data_structures/segment_tree/segment_tree_multiset.h"
#include "data_structures/treap/treap_multiset.h"

// A fixture class template for testing different multiset implementations.
template <typename T>
class Multiset : public testing::Test {
public:
    T multiset;
};

// The list of types to test.
using MyTypes = ::testing::Types<
    segment_tree_multiset,
    treap_multiset
>;

// Define the test suite.
TYPED_TEST_SUITE(Multiset, MyTypes);

//
// Test Cases
//

TYPED_TEST(Multiset, InitialSetup) {
    // Initially the multiset should be empty.
    EXPECT_EQ(this->multiset.size(), 0);

    // All elements should have a count of 0.
    for (int i = 1; i <= 20; ++i) {
        EXPECT_EQ(this->multiset.count(i), 0);
    }
}

TYPED_TEST(Multiset, InsertSingleElement) {
    // Arrange.
    int element = 5;

    // Act.
    this->multiset.insert(element);

    // Assert.
    EXPECT_EQ(this->multiset.size(), 1);
    EXPECT_EQ(this->multiset.count(element), 1);
}

TYPED_TEST(Multiset, InsertSingleElementMultipleTimes) {
    // Arrange.
    int element = 5;

    // Act.
    this->multiset.insert(element);
    this->multiset.insert(element);
    this->multiset.insert(element);

    // Assert.
    EXPECT_EQ(this->multiset.size(), 3);
    EXPECT_EQ(this->multiset.count(element), 3);
}

TYPED_TEST(Multiset, InsertElements) {
    // Arrange.
    std::vector<int> values = { 2, 5, 1, 5, 1, 1, 1, 7 };
    std::multiset<int> std_multiset;

    //
    // Act & Assert
    //

    for (int i = 0; i < values.size(); ++i) {
        // Insert the value to the multiset.
        this->multiset.insert(values[i]);
        std_multiset.insert(values[i]);

        // Assert the size of the multiset.
        EXPECT_EQ(this->multiset.size(), std_multiset.size());

        // Assert the count of each element.
        EXPECT_EQ(this->multiset.count(values[i]), std_multiset.count(values[i]));
    }
}

TYPED_TEST(Multiset, EraseSingleElement) {
    // Arrange.
    int element = 5;

    // Act.
    this->multiset.insert(element);
    this->multiset.insert(element);
    this->multiset.erase(element);

    // Assert.
    EXPECT_EQ(this->multiset.size(), 1);
    EXPECT_EQ(this->multiset.count(element), 1);
}

TYPED_TEST(Multiset, EraseNonExistingElement) {
    // Act.
    this->multiset.insert(1);
    this->multiset.insert(2);
    auto flag = this->multiset.erase(7);

    // Assert.
    EXPECT_FALSE(flag);
    EXPECT_EQ(this->multiset.size(), 2);
}

TYPED_TEST(Multiset, ClearElements) {
    // Act.
    this->multiset.insert(1);
    this->multiset.insert(2);
    this->multiset.insert(3);
    this->multiset.clear();

    // Assert.
    EXPECT_EQ(this->multiset.size(), 0);
}

TYPED_TEST(Multiset, GetElementsByIndex) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };

    // Insert the values to the multiset.
    for (int v : values) {
        this->multiset.insert(v);
    }

    // Sort the values to get the expected result.
    auto sorted_values = values;
    std::sort(sorted_values.begin(), sorted_values.end());

    //
    // Act & Assert
    //

    for (int i = 0; i < values.size(); ++i) {
        EXPECT_EQ(this->multiset[i], sorted_values[i]);
    }
}

TYPED_TEST(Multiset, FindLowerBound_EmptySet) {
    // Act & Assert.
    EXPECT_EQ(this->multiset.lower_bound(1), this->multiset.size());
    EXPECT_EQ(this->multiset.lower_bound(7), this->multiset.size());
}

TYPED_TEST(Multiset, FindLowerBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };

    // Insert the values to the multiset.
    for (int v : values) {
        this->multiset.insert(v);
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
        EXPECT_EQ(this->multiset.lower_bound(i), expected);
    }
}

TYPED_TEST(Multiset, FindUpperBound_ExistingElements) {
    //
    // Arrange
    //

    std::vector<int> values = { 1, 7, 1, 7, 5, 7, 9, 7 };

    // Insert the values to the multiset.
    for (int v : values) {
        this->multiset.insert(v);
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
        EXPECT_EQ(this->multiset.upper_bound(i), expected);
    }
}
