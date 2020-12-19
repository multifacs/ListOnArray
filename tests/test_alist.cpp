#include <../gtest/gtest.h>
#include "AList.h"

TEST(alist, can_create_list)
{
	ASSERT_NO_THROW(AList<int> a);
}

TEST(alist, can_copy)
{
	AList<int> a;
	a.push_back(123);

	AList<int> b(a);
	AListIterator<int> k = b.begin();
	EXPECT_EQ(123, *k);
}

TEST(alist, can_push_back)
{
	AList<int> lst(2);

	lst.push_back(5);
	lst.push_back(100);

	AListIterator<int> k = lst.begin();
	k++;
	EXPECT_EQ(100, *k);
}

TEST(alist, can_pop_back)
{
	AList<int> lst(2);

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_back();

	lst.push_back(17);
	AListIterator<int> k = lst.begin();
	k++;
	EXPECT_EQ(17, *k);
}

TEST(alist, cant_pop_in_empty_list)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(alist, can_push_front)
{
	AList<int> lst(3);

	lst.push_back(5);
	lst.push_back(100);

	lst.push_front(17);

	AListIterator<int> k = lst.begin();
	EXPECT_EQ(17, *k);
}

TEST(alist, can_pop_front)
{
	AList<int> lst(2);

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_front();

	AListIterator<int> k = lst.begin();
	EXPECT_EQ(100, *k);
}

TEST(alist, can_insert)
{
	AList<int> lst(5);

	lst.push_back(5);
	lst.push_back(100);

	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);

	AListIterator<int> k = lst.begin();
	k++; k++; k++;
	EXPECT_EQ(99, *k);
}

TEST(alist, can_remove)
{
	AList<int> lst(3);

	lst.push_back(5);
	lst.push_back(100);
	lst.push_back(21);

	lst.remove(1);

	AListIterator<int> k = lst.begin();
	k++;
	EXPECT_EQ(21, *k);
}

TEST(alist, can_insert_at_end)
{
	AList<int> a(3);
	a.push_back(1);
	a.push_back(2);

	a.insert(3, a.GetCount());

	AListIterator<int> k = a.begin();
	k++; k++;
	EXPECT_EQ(3, *k);
}

TEST(alist, can_remove_at_end)
{
	AList<int> a(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	a.remove(a.GetCount() - 1);

	AListIterator<int> k = a.begin();
	k++;
	EXPECT_EQ(2, *k);
}

TEST(alist, cant_insert_out_of_bounds)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(alist, cant_remove_out_of_bounds)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}