#include "INC/cub3d.h"

void	colorrangecheck(char **s, char **s2)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(s2[i]) < 0 || ft_atoi(s2[i]) > 255)
		{
			printf("ERROR COLOR OUT OF RANGE [0,255]");
			free(s2);
			free(s);
			exit(1);
		}
		i++;
	}
}

void	checkfloorceilingparam(int check, char **s, char **s2)
{
	if (check != 0)
	{
		printf("ERROR Double parametre Of FLOORc");
		free(s);
		free(s2);
		exit(0);
	}
	else
		check = 1;
}

void	ceillingcolor(char *line)
{
	char	**s;
	char	**s2;
	int		a;
	int		b;
	int		c;

	s = ft_split(line,' ');
	s2 = ft_split(s[1],',');
	checkfloorceilingparam(check.Ceillig, s, s2);
	/*if (s[2] != '\0' || s2[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(s2);
		exit(0);
	}*/ 
	colorrangecheck(s, s2);
	a = ft_atoi(s2[0]);
	b = ft_atoi(s2[1]);
	c = ft_atoi(s2[2]);
	param.Ceillingcolor = creatergb(a, b, c);
	a = -1;
	while (s[++a]!= NULL)
		free(s[a]);
	free(s[a]);
	free(s);
	a = -1;
	while (s2[++a]!=NULL)
		free(s2[a]);
	free(s2[a]);
	free(s2);
}

void	floorcolor(char *line)
{
	char	**s;
	char	**s2;
	int		a;
	int		b;
	int		c;

	s = ft_split(line,' ');
	s2 = ft_split(s[1],',');
	checkfloorceilingparam(check.Floor, s, s2);
/*	if (s[2] != '\0' || s2[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(s2);
		exit(0);
	}*/
	colorrangecheck(s, s2);
	a = ft_atoi(s2[0]);
	b = ft_atoi(s2[1]);
	c = ft_atoi(s2[2]);
	param.Florcolor = creatergb(a, b, c);
	a = -1;
	while (s[++a]!= '\0')
	free(s[a]);
	free(s);
	a = -1;
	//free_split(s2,3);
	while (s2[++a]!='\0')
	free(s2[a]);
	free(s2);
}

void	checkdigit(char **s, int i)
{
	int	j;

	j = 0;
	while (j < ft_strlen(s[i]))
	{
		if (ft_isdigit(s[i][j]) == 1)
			j++;
		else
		{
			printf("ERROR WITDH IS NOT NUM");
			free(s);
			exit(1);
		}
	}
}
