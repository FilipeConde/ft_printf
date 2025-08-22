
#include "./Unity-2.6.1/src/unity.h"
#include "../libftprintf.h"
#include "./utils/utils.h"

#include <stdio.h>

void	setUp()
{
	return ;
}

void	tearDown()
{
	remove("output.txt");
	remove("a.out");
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
	int		count = 0;

	freopen("output.txt", "w+", stdout);
	count += ft_printf("Hello %c world!", c_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_str_var(void)
{
	char	*output;
	char	*str = "Hello fuckin world!";
	char	*str_var = "fuckin";
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("Hello %s world!", str_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_null_var(void)
{
	char	*output;
	char	*str = "(null)";
	char	*str_var = (void *)0;
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%s", str_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_int_var(void)
{
	char	*output;
	char	*str = "Hello 70 world!";
	int		i_var = 70;
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("Hello %i world!", i_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_double_var(void)
{
	char	*output;
	char	*str = "Hello -70 world!";
	int		i_var = -70;
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("Hello %i world!", i_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_unsigned_int_var(void)
{
	char			*output;
	char			*str = "157";
	unsigned int	u_var = 157;
	int				count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%u", u_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_unsigned_int_max_var(void)
{
	char			*output;
	char			*str = "4294967295";
	unsigned int	u_var = -1;
	int				count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%u", u_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_hexadecimal_int_var_lowercase(void)
{
	char	*output;
	char	*str = "2b";
	int		x_var = 43;
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%x", x_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_hexadecimal_int_var_uppercase(void)
{
	char	*output;
	char	*str = "2B";
	int		x_var = 43;
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%X", x_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_two_different_var_flags(void)
{
	char	*output;
	char	*str = "Hello fuckin and -70 OH world!";
	int		i_var = -70;
	char	*str_var = "fuckin";
	char	*str_var2 = "OH";
	int		count = 0;
	
	freopen("output.txt", "w+", stdout);
	count += ft_printf("Hello %s and %i %s world!", str_var, i_var, str_var2);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_with_two_direct_percent(void)
{
	char	*output;
	char	*str = "%";
	int		count = 0;

	freopen("output.txt", "w+", stdout);
	count += ft_printf("%%");
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_with_percent_char_parameter(void)
{
	char	*output;
	char	*str = "%";
	char	c_var = '%';
	int		count = 0;

	freopen("output.txt", "w+", stdout);
	count += ft_printf("%c", c_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_with_percent_string_parameter(void)
{
	char	*output;
	char	*str = "%";
	char	*str_var = "%";
	int		count = 0;

	freopen("output.txt", "w+", stdout);
	count += ft_printf("%s", str_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_with_nil_pointer_parameter(void)
{
	char	*output;
	char	*str = "(nil)";
	char	*str_var = (void *)0;
	int		count = 0;

	freopen("output.txt", "w+", stdout);
	count += ft_printf("%p", str_var);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_with_valid_pointer_parameter(void)
{
	char	*control;
	char	*output;
	char	*str = "Teste";
	int		count = 0;

	freopen("control.txt", "w+", stdout);
	printf("%p", str);
	freopen("output.txt", "w+", stdout);
	count += ft_printf("%p", str);
	freopen("/dev/tty", "w", stdout);
	control = read_file_to_str("control.txt");
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(control, output);
	TEST_ASSERT_EQUAL_INT(strlen(control), count);
	free(control);
	free(output);
	remove("control.txt");
	remove("output.txt");
}

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(print_simple_direct_string);
RUN_TEST(print_string_with_one_char_var);
RUN_TEST(print_string_with_one_str_var);
RUN_TEST(print_string_with_null_var);
RUN_TEST(print_string_with_one_int_var);
RUN_TEST(print_string_with_one_unsigned_int_var);
RUN_TEST(print_string_with_one_unsigned_int_max_var);
RUN_TEST(print_string_with_one_hexadecimal_int_var_lowercase);
RUN_TEST(print_string_with_one_hexadecimal_int_var_uppercase);
RUN_TEST(print_string_with_one_double_var);
RUN_TEST(print_string_with_two_different_var_flags);
RUN_TEST(print_with_two_direct_percent);
RUN_TEST(print_with_percent_char_parameter);
RUN_TEST(print_with_percent_string_parameter);
RUN_TEST(print_with_nil_pointer_parameter);
RUN_TEST(print_with_valid_pointer_parameter);

return UNITY_END();
}
