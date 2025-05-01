#include <gtest/gtest.h>
extern "C" {
	#include <demo_library.h>
}

TEST(basic, basic)
{	ASSERT_TRUE(demo_library_function());
}