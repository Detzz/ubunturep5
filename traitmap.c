
#include "INC/cub3d.h"

void	remplirmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < param.num_rows + 2)
	{
		j = 0;
		while (j < param.num_col + 2)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	swappingmaps(char **map, char **S)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (S[i][j] != '\0')
		{
			map[i + 1][j + 1] = S[i][j];
			j++;
		}
		i++;
	}
}

void	handleerroe1(void)
{
	if (linecount != param.num_rows)
	{
		printf("ERROR MAP IS OPEN");
		free(param.s5);
		exit(1);
	}
}

void	findingnumofcols(void)
{
	int	i;
	int	top;
	int	j;

	i = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (param.s5[i][j++] != '\0')
		{
			if (j > top)
				top = j;
		}
		i++;
	}
	param.num_col = top;
}

void	treatmap(char *string)
{
	int	i;
	int j;
	int top;
	char **S;

	S = ft_split(string, '\n');
	//free(s);




	//function_readingmaptogivespritecount(param.s5);
	i = 0;
	while (S[i] != '\0')
		i++;
	param.num_rows = i;
	i = 0;
	while (i < param.num_rows)
	{
		j = -1;
		while (S[i][++j] != '\0')
		{
			if (j > top)
				top = j;
		}
		i++;
	}
	param.num_col = top;
	
	mapp = malloc(sizeof(char*) * (param.num_rows + 3));
	i = 0;
	while (i < param.num_rows + 3)
	{
		mapp[i] = malloc(sizeof(char) * (param.num_col + 3));
		i++;
	}
	remplirmap(mapp);
	swappingmaps(mapp, S);
	find_zero_in_map(mapp);
	handleerroe1();
	handleerror2(mapp);
	function_readingmaptogivespritecount(mapp);
	g_sp = malloc(sizeof(g_param) * (g_spritecount + 1));
	free(S);
}
