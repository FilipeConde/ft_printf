
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

	f = fopen(filename, "rb");
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
void	teste_printf_original(void)
{
	char	*output;

	freopen("output.txt", "w+", stdout);
	printf("Hello world!");
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("Hello, world!", output, "Erro no processo!");
	free(output);
	// remove("output.txt");
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
RUN_TEST(teste_printf_original);
// RUN_TEST(test_02);
return UNITY_END();
}
