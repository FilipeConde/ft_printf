
#include "./Unity-2.6.1/src/unity.h"
#include "../libftprintf.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*read_file_to_str(const char *filename)
{
	FILE	*f;
	long	fsize;
	char	*str;

	fopen(filename, "rb");
	if (!f)
		return (NULL);
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	str = malloc(fsize + 1);
	if (!str)
		return (NULL);
	fread(str, fsize, 1, f);
	fclose(f);
	str[fsize] = '\0';
	return (str);
}

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
