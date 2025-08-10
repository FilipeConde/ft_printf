
#include "./Unity-2.6.1/src/unity.h"
#include "../libftprintf.h"

void	setUp()
{
	return ;
}

void	tearDown()
{
	return ;
}

void	test_01(void)
{
TEST_ASSERT_EQUAL_STRING("TESTE", ft_printf("TESTE"));
// TEST_ASSERT_EQUAL_HEX8(33, AverageThreeBytes(33, 33, 33));
}

void	test_02(void)
{
	TEST_ASSERT_EQUAL_STRING_MESSAGE("TESTE", ft_printf("TEXTO"), "Complicaaado");
}

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(test_01);
RUN_TEST(test_02);
return UNITY_END();
}
