/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:57:58 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/08 12:13:21 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bh_dispatch(t_fdf *fdf)
{
	fdf->dx = fdf->x2 - fdf->x1;
	fdf->dy = fdf->y2 - fdf->y1;
	fdf->dx = abs(fdf->dx);
	fdf->dy = abs(fdf->dy);
	fdf->incx = (fdf->x2 > fdf->x1) ? 1 : -1;
	fdf->incy = (fdf->y2 > fdf->y1) ? 1 : -1;
	if (fdf->dx > fdf->dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}

void	m_neg(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
	e = (2 * fdf->dy) - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (i < fdf->dx)
	{
		if (e >= 0)
		{
			fdf->y1 = fdf->y1 + fdf->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->x1 = fdf->x1 + fdf->incx;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
		i++;
	}
}

void	m_pos(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
	e = (2 * fdf->dx) - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (i < fdf->dy)
	{
		if (e >= 0)
		{
			fdf->x1 = fdf->x1 + fdf->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->y1 = fdf->y1 + fdf->incy;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
		i++;
	}
}
