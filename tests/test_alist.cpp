#include <../gtest/gtest.h>
#include "AList.h"

TEST(alist, can_create_list)
{
	ASSERT_NO_THROW(AList<int> a);
}

TEST(alist, can_copy)
{
	AList<int> a;
	ASSERT_NO_THROW(AList<int> b(a));
}

TEST(alist, can_push_back)
{
	AList<int> a;
	ASSERT_NO_THROW(a.push_back(1));
}

TEST(alist, can_pop_back)
{
	AList<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_back());
}

TEST(alist, cant_pop_in_empty_list)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(alist, can_push_front)
{
	AList<int> a;
	a.push_back(2);
	ASSERT_NO_THROW(a.push_front(1));
}

TEST(alist, can_pop_front)
{
	AList<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_front());
}

TEST(alist, can_insert)
{
	AList<int> a;
	a.push_back(1);
	a.push_back(3);
	ASSERT_NO_THROW(a.insert(2, 1));
}

TEST(alist, can_remove)
{
	AList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	ASSERT_NO_THROW(a.remove(1));
}

TEST(alist, can_insert_at_end)
{
	AList<int> a;
	a.push_back(1);
	a.push_back(2);
	ASSERT_NO_THROW(a.insert(3, 2));
}

TEST(alist, cant_insert_beyond_border)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(alist, cant_remove_beyond_border)
{
	AList<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}