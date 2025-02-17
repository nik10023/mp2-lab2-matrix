#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5, 3));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_create_vector_with_max_size)
{
    ASSERT_NO_THROW(TVector<int> v(MAX_VECTOR_SIZE));
}

TEST(TVector, can_create_vector_with_zero_size)
{
    ASSERT_NO_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(5, 3);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5, 3);
	TVector<int> v1(v);

	EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(5, 3);
	TVector<int> v1(v);

	v1[3] = 1;

	EXPECT_NE(1, v[3]);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(5, 3);

  EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(5, 3);

  EXPECT_EQ(3, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(5, 3);
	v[4] = 4;

  EXPECT_EQ(4, v[4]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(1);

	ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5, 3);

	ASSERT_ANY_THROW(v[6] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5, 3);

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(5, 3);

	ASSERT_NO_THROW(v = v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(1);
	v = v1;

	EXPECT_EQ(1, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(10, 7);
	v[3] = 3;
	v[4] = 4;
	v[5] = 5;

	v1 = v;

	EXPECT_EQ(5, v.GetSize());
	EXPECT_EQ(3, v.GetStartIndex());
	EXPECT_EQ(3, v[3]);
	EXPECT_EQ(4, v[4]);
	EXPECT_EQ(5, v[5]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(5, 3);
	TVector<int> v1(5, 3);

	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5, 3);

	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5, 3);
	TVector<int> v1(6, 3);

	EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(5, 3);
	for (int i = v.GetStartIndex(); i <= v.GetSize(); i++)
		v[i] = 0;
	v = v + 5;
	EXPECT_EQ(5, v[3]);
	EXPECT_EQ(5, v[4]);
	EXPECT_EQ(5, v[5]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(2);
	for (int i = v.GetStartIndex(); i <= v.GetSize(); i++)
		v[i] = 10;
	v = v - 5;
	EXPECT_EQ(5, v[1]);
	EXPECT_EQ(5, v[2]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(2);
	for (int i = v.GetStartIndex(); i <=v.GetSize(); i++)
		v[i] = 1;
	v = v * 5;
	EXPECT_EQ(5, v[1]);
	EXPECT_EQ(5, v[2]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(5, 3);
	v[3] = 1;
	v[4] = 1;
	v[5] = 1;
	v1[3] = 1;
	v1[4] = 1;
	v1[5] = 1;
	v = v + v1;

	EXPECT_EQ(2, v[3]);
	EXPECT_EQ(2, v[4]);
	EXPECT_EQ(2, v[5]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5,3);
	TVector<int> v1(5,2);

	ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(5, 3);
	v[3] = 1;
	v[4] = 1;
	v[5] = 1;
	v1[3] = 1;
	v1[4] = 1;
	v1[5] = 1;
	v = v - v1;

	EXPECT_EQ(0, v[3]);
	EXPECT_EQ(0, v[4]);
	EXPECT_EQ(0, v[5]);
}			  

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5,3);
	TVector<int> v1(5,2);

	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(5, 3);
	TVector<int> v1(5, 3);
	v[3] = 1;
	v[4] = 1;
	v[5] = 1;
	v1[3] = 2;
	v1[4] = 2;
	v1[5] = 2;
	int scal = v * v1;

	EXPECT_EQ(6, scal);

}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5,3);
	TVector<int> v1(5,2);

	ASSERT_ANY_THROW(v * v1);
}

