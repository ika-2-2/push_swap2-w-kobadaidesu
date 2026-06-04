#include "push_swap.h"

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

static int is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++ ;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++ ;
    }
    return 1;
}

long    ft_atol(char *str)
{
    long    n;
    int     sign;
    int     i;

    i = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    n = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = n * 10 + (str[i] - '0');
        i++;
    }
    return (n * sign);
}

void error_check(char **args)
{
    int i;
    int j;
    long n;
    long m;

    //split でmalloc が失敗してreturn NULl　check
    if (!args || !args[0])
        error_exit();
    i = 0;
    while (args[i])
    {
        //数字はんてい
        if (!is_valid_number(args[i]))
            error_exit();
        //atoiじゃなくてatolなのはINTMINのはんていをするため
        //long min long max の対応もしたほうがいいかも
        n = ft_atol(args[i]);
        if (n > INT_MAX || n < INT_MIN)
            error_exit();
        j = i + 1;
        //重複チェック
        while (args[j])
        {
            m = ft_atol(args[j]);
            if (n == m)
                error_exit();
            j++ ;
        }
        i++ ;
    }
}

size_t stack_size(t_stack *stack)
{
	t_stack *current;
	size_t size;

	size = 1;
	current = stack->next;
	while (current != stack)
	{
		current = stack->next;
		size++ ;
	}
	return (size);
}

calc_disorder(t_stack *a)
{
	size_t i;
	size_t j;
	size_t total_pairs;
	size_t mistakes;

	size = stack_size(a);
	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size - 1)
		{
			total_pairs++ ;
			if ()
		}
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		bench;
	char	**args;

	if (argc < 2)
		return (0);
	i = 1;
	bench = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			; // flag on
		else if (ft_strcmp(argv[i], "--complex") == 0)
			; // flag on
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			; // flag on
		else
			break ;
		i++ ;
	}
	if (i >= argc)
		error_exit();
	if (ft_strchr(argv[i], ' '))
		args = ft_split(argv[i], ' ');
	else
		args = &argv[i];
	error_check(args);
	init_stack(args);
	/*
		disorder はここ
		座圧もここらへん
		sort
	*/
	if (bench)
	{
		/*
			bench表示
		*/
	}

	return (0);
}
