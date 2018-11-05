#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, can_set_infix)
{
	ASSERT_NO_THROW(TPostfix p("a+b"));
}
TEST(TPostfix, can_get_infix)
{
	TPostfix p("a+b");
	EXPECT_EQ("a+b", p.GetInfix());
}
TEST(TPostfix, can_get_postfix_of_two_arguments)
{
	TPostfix p("a+b");
	p.ToPostfix();
	EXPECT_EQ("ab+", p.GetPostfix());
}
TEST(TPostfix, can_get_postfix_of_three_arguments)
{
	TPostfix p("a+b*c");
	p.ToPostfix();
	EXPECT_EQ("abc*+", p.GetPostfix());
}
TEST(TPostfix, can_get_postfix_with_parentheses)
{
	TPostfix p("a+(b-c)");
	p.ToPostfix();
	EXPECT_EQ("abc-+", p.GetPostfix());
}

TEST(TPostfix, can_calculate_postfix)
{
	TPostfix p("a+b");
	p.ToPostfix();
	double tmp[2] = { 2,2 };
	EXPECT_EQ(4, p.Calculate(tmp));
}

