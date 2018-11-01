#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, can_set_infix)
{
	ASSERT_NO_THROW(TPostfix p("a + b"));
}
TEST(TPostfix, can_get_infix)
{
	TPostfix p("a + b");
	EXPECT_EQ("a + b", p.GetInfix());
}
TEST(TPostfix, can_get_postfix)
{
	TPostfix p("a + b");
	EXPECT_EQ("ab+", p.GetPostfix());
}

