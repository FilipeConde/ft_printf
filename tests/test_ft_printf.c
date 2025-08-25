
#include "./Unity-2.6.1/src/unity.h"
#include "../libftprintf.h"
#include "./utils/utils.h"

#include <stdio.h>

#define CAPTURE_PRINT(file, count_var, function, ...) \
	do { \
		freopen((file), "w+", stdout); \
		(count_var) = (function)(__VA_ARGS__); \
		freopen("/dev/tty", "w", stdout); \
	} while (0)

void	setUp()
{
	return ;
}

void	tearDown()
{
	remove("output.txt");
	remove("control.txt");
	remove("a.out");
	return ;
}

void	print_simple_direct_string(void)
{
	char	*output;
	char	*str = "Hello world!";
	int		count = 0;

	CAPTURE_PRINT("output.txt", count, ft_printf, str);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(str), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_char_var(void)
{
	char	*output;
	char	*str = "Hello F world!";
	char	c_var = 'F';
	int		count;

	CAPTURE_PRINT("output.txt", count, ft_printf, "Hello %c world!", c_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "Hello %s world!", str_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%s", str_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "Hello %i world!", i_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "Hello %i world!", i_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%u", u_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%u", u_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%x", x_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%X", x_var);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(str, output);
	TEST_ASSERT_EQUAL_INT(strlen(output), count);
	free(output);
	remove("output.txt");
}

void	print_string_with_one_hexadecimal_int_var_max_value(void)
{
	char	*output;
	char	*str = "ffffffff";
	int		x_var = -1;
	int		count = 0;

	CAPTURE_PRINT("output.txt", count, ft_printf, "%x", x_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "Hello %s and %i %s world!",
		str_var, i_var, str_var2);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%%");
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%c", c_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%s", str_var);
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

	CAPTURE_PRINT("output.txt", count, ft_printf, "%p", str_var);
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
	int		count_ft;
	int		dummy_count;

	CAPTURE_PRINT("control.txt", dummy_count, printf, "%p", str);
	CAPTURE_PRINT("output.txt", count_ft, ft_printf, "%p", str);
	control = read_file_to_str("control.txt");
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(control, output);
	TEST_ASSERT_EQUAL_INT(strlen(control), count_ft);
	free(control);
	free(output);
}

void	print_with_valid_pointer_parameter_to_max_hex(void)
{
	char	*control;
	char	*output;
	void	*ptr = (void *)-1;
	int		count_ft;
	int		dummy_count;

	CAPTURE_PRINT("control.txt", dummy_count, printf, "%p", ptr);
	CAPTURE_PRINT("output.txt", count_ft, ft_printf, "%p", ptr);
	control = read_file_to_str("control.txt");
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(control, output);
	TEST_ASSERT_EQUAL_INT(dummy_count, count_ft);
	free(control);
	free(output);
}

void	print_trailing_percent(void)
{
	char	*output;
	char	*expected = "hello";
	int		count = 0;

	CAPTURE_PRINT("output.txt", count, ft_printf, "hello%");
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING(expected, output);
	TEST_ASSERT_EQUAL_INT(strlen(expected), count);
	free(output);
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
RUN_TEST(print_string_with_one_hexadecimal_int_var_max_value);
RUN_TEST(print_string_with_one_double_var);
RUN_TEST(print_string_with_two_different_var_flags);
RUN_TEST(print_with_two_direct_percent);
RUN_TEST(print_with_percent_char_parameter);
RUN_TEST(print_with_percent_string_parameter);
RUN_TEST(print_with_nil_pointer_parameter);
RUN_TEST(print_with_valid_pointer_parameter);
RUN_TEST(print_with_valid_pointer_parameter_to_max_hex);
RUN_TEST(print_trailing_percent);

return UNITY_END();
}
