
#include "./Unity-2.6.1/src/unity.h"
#include "../libftprintf.h"
#include "./utils/utils.h"

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
	TEST_ASSERT_EQUAL_STRING_MESSAGE("Hello world!", output, "Erro no processo!");
	free(output);
	remove("output.txt");
}

void	print_simple_direct_string(void)
{
	char	*output;
	char	*str = "Hello world!";

	freopen("output.txt", "w+", stdout);
	ft_printf(str);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(str), strlen(output));
	free(output);
	remove("output.txt");
}

void	print_string_with_one_char_var(void)
{
	char	*output;
	char	*str = "Hello F world!";
	char	c_var = 'F';

	freopen("output.txt", "w+", stdout);
	ft_printf("Hello %c world!", c_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), ft_printf("Hello %c world!", c_var));
	free(output);
	remove("output.txt");
}

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(print_simple_direct_string);
RUN_TEST(print_string_with_one_char_var);
return UNITY_END();
}
