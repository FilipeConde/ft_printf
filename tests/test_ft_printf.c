
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

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(teste_printf_original);
return UNITY_END();
}
