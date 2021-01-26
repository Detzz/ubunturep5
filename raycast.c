#include "INC/cub3d.h"

void	horiraycasthelper(float rayangle, float ystep, float xstep)
{
	float	xtocheck;
	float	ytocheck;

	while (g_cord.nexthorx >= 0 && g_cord.nexthorx < param.num_col * 64 &&
			g_cord.nexthory >= 0 && g_cord.nexthory < param.num_rows * 64)
	{
		xtocheck = g_cord.nexthorx;
		ytocheck = g_cord.nexthory;
		if (haswallat(xtocheck, ytocheck -=
			(rayfacingupdown(rayangle) == 1) ? 1 : 0) == 1)
		{
			g_foundhortwallhit = 1;
			g_cord.wallhorhitx = g_cord.nexthorx;
			g_cord.wallhorhity = g_cord.nexthory;
			break ;
		}
		else
		{
			g_cord.nexthorx += xstep;
			g_cord.nexthory += ystep;
		}
	}
}

void	casthorizontal(float rayangle)
{
	float	xstep;
	float	ystep;
	float	xintercept;
	float	yintercept;

	g_foundhortwallhit = 0;
	yintercept = floor(g_cord.y / TITLESIZE) * TITLESIZE;
	yintercept += (rayfacingupdown(rayangle) == 0) ? TITLESIZE : 0;
	xintercept = g_cord.x + ((yintercept - g_cord.y) / tan(rayangle));
	ystep = TITLESIZE;
	ystep *= (rayfacingupdown(rayangle) == 1) ? -1 : 1;
	xstep = ystep / tan(rayangle);
	xstep *= (rayfacingrightleft(rayangle) == 0 && xstep > 0) ? -1 : 1;
	xstep *= (rayfacingrightleft(rayangle) == 1 && xstep < 0) ? -1 : 1;
	g_cord.nexthorx = xintercept;
	g_cord.nexthory = yintercept;
	horiraycasthelper(rayangle, ystep, xstep);
}

void	verraycasthelper(float rayangle, float xstep, float ystep)
{
	float	xtocheck;
	float	ytocheck;

	while (g_cord.nextverx >= 0 && g_cord.nextverx < param.num_col * 64 &&
			g_cord.nextvery >= 0 && g_cord.nextvery < param.num_rows * 64)
	{
		xtocheck = g_cord.nextverx;
		ytocheck = g_cord.nextvery;
		if (haswallat(xtocheck -=
			(rayfacingrightleft(rayangle) == 0) ? 1 : 0, ytocheck) == 1)
		{
			g_foundvertwallhit = 1;
			g_cord.wallverhitx = g_cord.nextverx;
			g_cord.wallverhity = g_cord.nextvery;
			break ;
		}
		else
		{
			g_cord.nextverx += xstep;
			g_cord.nextvery += ystep;
		}
	}
}

void	castvertical(float rayangle)
{
	float	xstep;
	float	ystep;
	float	xintercept;
	float	yintercept;

	g_foundvertwallhit = 0;
	xintercept = floor(g_cord.x / TITLESIZE) * TITLESIZE;
	xintercept += (rayfacingrightleft(rayangle) == 1) ? TITLESIZE : 0;
	yintercept = g_cord.y + ((xintercept - g_cord.x) * tan(rayangle));
	xstep = TITLESIZE;
	xstep *= (rayfacingrightleft(rayangle) == 0) ? -1 : 1;
	ystep = xstep * tan(rayangle);
	ystep *= (rayfacingupdown(rayangle) == 1 && ystep > 0) ? -1 : 1;
	ystep *= (rayfacingupdown(rayangle) == 0 && ystep < 0) ? -1 : 1;
	g_cord.nextverx = xintercept;
	g_cord.nextvery = yintercept;
	verraycasthelper(rayangle, xstep, ystep);
}

void	decide(void)
{
	float	horhitdistance;
	float	verhitdistance;

	g_washithorizontal = 0;
	g_washitvertical = 0;
	horhitdistance = (g_foundhortwallhit == 1) ?
		get_distance(g_cord.x, g_cord.y, g_cord.wallhorhitx, g_cord.wallhorhity)
			: 500000000000;
	verhitdistance = (g_foundvertwallhit == 1) ?
		get_distance(g_cord.x, g_cord.y, g_cord.wallverhitx, g_cord.wallverhity)
			: 500000000000;
	if (horhitdistance < verhitdistance)
	{
		g_wallhitx = g_cord.wallhorhitx;
		g_wallhity = g_cord.wallhorhity;
		g_distance = horhitdistance;
		g_washithorizontal = 1;
	}
	else
	{
		g_wallhitx = g_cord.wallverhitx;
		g_wallhity = g_cord.wallverhity;
		g_distance = verhitdistance;
		g_washitvertical = 1;
	}
}

void	casthelper(float rayangle, int j, int i, int columnid)
{
	float	ray;

	while (i < param.g_width)
	{
		j = 0;
		ray = newray(rayangle);
		casthorizontal(ray);
		castvertical(ray);
		decide();
		g_rays[i].rayangle = rayangle;
		g_rays[i].washitvertical = (g_washitvertical == 1) ? 1 : 0;
		g_rays[i].washithorizontal = (g_washithorizontal == 1) ? 1 : 0;
		g_rays[i].wallhitx = g_wallhitx;
		g_rays[i].wallhity = g_wallhity;
		g_rays[i].facingupdown = (rayfacingupdown(ray) == 1) ? 1 : 0;
		g_rays[i].facingrightleft = (rayfacingrightleft(ray) == 1) ? 1 : 0;
		g_rays[i].distance =
			get_distance(g_cord.x, g_cord.y, g_wallhitx, g_wallhity);
		rayangle += (FOVANGLE / param.g_width);
		columnid++;
		i++;
	}
}

void	castalleays(void)
{
	int		columnid;
	float	rayangle;
	int		i;
	int		j;
	float	ray;

	i = 0;
	columnid = 0;
	rayangle = g_cord.rotationangle - (FOVANGLE / 2);
	rayangle = newray(rayangle);
	casthelper(rayangle, j, i, columnid);
	render3dprojectwalls();
}
