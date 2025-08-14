
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
void	teste_write_char(void)
{
	char	*output;
	char	s[] = "Ops!";

	freopen("output.txt", "w+", stdout);
	ft_write_char(s);
	fflush(stdout);
	freopen("/dev/tty", "w", stdout);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("Ops!", output, "Erro no processo!");
	free(output);
	remove("output.txt");
}

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(teste_write_char);
return UNITY_END();
}
