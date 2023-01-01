#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static size_t get_commands_num(char *str, char *delim)
{
    size_t  pos;
    size_t  commands_num;

    pos = 0;
    commands_num = 0;
	while (strchr(delim, str[pos]) == NULL  && str[pos] != '\0')
		pos++;
	// printf("%ld\n", pos);
    while (str[pos] != '\0')
    {
        if (pos != 0 && strchr(delim, str[pos - 1]) != NULL && strchr(delim , str[pos]) == NULL)
            commands_num++;
        pos++;
    }
    return (commands_num + 1);
}
//command num is ok

static size_t get_command_len(char *com_seq, char *delim, int pos)
{
	size_t 	command_len;
	
	command_len = 0;
	// printf("%d\n", pos);
	while(strchr(delim , com_seq[pos]) == NULL && com_seq[pos] != '\0')
	{
		pos++;
		command_len++;
	}
	return command_len;
}
//obtain_commandlen is ok

char **split(char *src, char *delim)
{
	size_t 	commands_num;
	char **	input;
	size_t 	command_len;
	int 	pos;
	int 	j;
	size_t	 k;

	pos = 0;
	j = 0;
	k = 0;
	commands_num = get_commands_num(src, delim);
	// printf("commands_num is ...%ld\n", commands_num);
	input = (char **)malloc(sizeof(char *) * (commands_num + 1));
	while (src[pos] != '\0')
	{
		// while(strchr(delim, src[pos]) == NULL && src[pos] != '\0')
		//	pos++;
		if (strchr(delim, src[pos]) != NULL)
		{
			pos++;
			continue;
		}
		command_len = get_command_len(src, delim, pos);
		// printf("command len is ... %ld\n", command_len);
		input[j] = (char *)malloc(sizeof(char) * (command_len + 1));
		while (k != command_len)
		{
			input[j][k] = src[pos]; // ???
			pos++;
			k++;
		}
		input[j][k] = '\0';
		// printf("%s\n", input[j]);
		j++;
		k = 0;
	}
	input[j] = NULL;
	return input;
}

/*bool    has_duplicate(char **src)
{
    for(char **i = src; i != NULL; i++)
    {
        // printf("%s\n", src[i]);
        for(char **j = i++ ; j != NULL;  j++)
        {
            // printf("%s\n", src[j]);
            if(strcmp(*i, *j) == 0)
                return true;
        }
    }
    return false;
}*/

bool	has_duplicate(char **src)
{
	char	**i;
	char	**j;

	i = src;	
	while(i != NULL)
	{
		j = i++;
		// puts("hoge");
		while(j != NULL)
		{
			// puts("hoge");
			if (strcmp(*i, *j) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int main(void)
{
    char    *src = "0 1 0";
    char    **argv = split(src, " ");
    for(int i = 0; i < 2; i++)
    {
        printf("%s\n", argv[i]);
    }
    if(has_duplicate(argv))
        puts("duplicated...");
    else
        puts("unique!");
}