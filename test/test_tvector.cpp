#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	TDynamicVector<int> v1(arr1, 3), v3(v1);
	EXPECT_EQ(v1, v3);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	TDynamicVector<int> v1(arr1, 3), v3(std::move(v1));
	EXPECT_NE(&v1, &v3);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(11));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(v, v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(10), v1(10);
	ASSERT_NO_THROW(v = v1);
	EXPECT_EQ(v1, v = v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(10), v1(5);
	ASSERT_NO_THROW(v = v1);
	EXPECT_EQ(v1.size(), v.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(10), v1(5);
	ASSERT_NO_THROW(v = v1);
	EXPECT_EQ(v1, v = v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { 1, 2, 3 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v1, v3);

	delete[] arr1;
	delete[] arr3;
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(4);
	EXPECT_EQ(v1 == v1, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(4), v2(5);
	EXPECT_EQ(v1 == v2, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { 4, 5, 6 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 + 3);

	delete[] arr1;
	delete[] arr3;
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { -2, -1, 0 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 - 3);

	delete[] arr1;
	delete[] arr3;
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { 3, 6, 9 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 * 3);

	delete[] arr1;
	delete[] arr3;
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr2 = new int[3] { 2, 3, 4 };
	int* arr3 = new int[3] { 3, 5, 7 };
	TDynamicVector<int> v1(arr1, 3), v2(arr2, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 + v2);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr2 = new int[3] { 2, 3, 4 };
	int* arr3 = new int[3] { -1, -1, -1 };
	TDynamicVector<int> v1(arr1, 3), v2(arr2, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 - v2);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr2 = new int[3] { 2, 3, 4 };
	TDynamicVector<int> v1(arr1, 3), v2(arr2, 3);
	EXPECT_EQ(20, v1 * v2);

	delete[] arr1;
	delete[] arr2;
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 * v2);
}

