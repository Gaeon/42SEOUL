/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:57 by gaeon             #+#    #+#             */
/*   Updated: 2023/06/05 13:31:40 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
WIDTH HEIGHT BACKGROUND_CHAR
파일의 첫 번째 줄이며 그릴 영역
WIDTH: 그리기 영역에 사용할 가로 문자 수인 0 < WIDTH <= 300인 정수여야 합니다.
HEIGHT: 그리기 영역에 사용할 세로 글자 수인 0 < HEIGHT <= 300인 정수여야 합니다.
BACKGROUND_CHAR: 빈 공간은 BACKGROUND_CHAR로 채워집니다.

r x y width height char
직사각형의 테두리만 그려지는 빈 직사각형
r: 문자 r
X: 임의의 실수, 직사각형의 왼쪽 상단 모서리의 수평 위치
Y: 임의의 실수, 직사각형의 왼쪽 상단 모서리의 수직 위치
WIDTH: 0이 아닌 양수, 직사각형의 너비(가로)
HEIGHT: 0이 아닌 양의 실수, 직사각형의 높이(세로)
CHAR: 직사각형을 그리는 데 사용할 문자

R x y width height char
채워진 직사각형
R: 문자 R
X: 임의의 실수, 직사각형의 왼쪽 상단 모서리의 가로 위치
Y: 임의의 실수, 직사각형의 왼쪽 상단 모서리의 수직 위치
WIDTH: 0이 아닌 양수 실수, 사각형의 너비(가로)
HEIGHT: 0이 아닌 양의 실수, 직사각형의 높이(세로)
CHAR: 직사각형을 그리는 데 사용하는 문자
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		W;
int		H;
char	BC;
char	**TAB;

typedef struct s_dw
{
	char 	t;	// type {r, R}
	float 	x;
	float 	y;
	float 	w;	// width
	float 	h;	// height
	char 	c;	// character
}	t_dw;

int error(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write(1, "Error: Operation file corrupted\n", 32);
	else if (err == 1)
		write(1, "Error: argument\n", 16);
	else
	{
		for (int i = 0 ; i < H ; i++)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int in_rect(float x, float y, t_dw dw)
{
	if (y - dw.x < 0 || dw.x + dw.w - y < 0 || x - dw.y < 0 || dw.y + dw.h - x < 0)
		return (0);
	if ((y - dw.x < 1 || dw.x + dw.w - y < 1 || x - dw.y < 1 || dw.y + dw.h - x < 1) && dw.t == 'r')
		return (1);
	else
		return (2);
}

int main(int argc, char **argv)
{
	t_dw	dw;		// draw
	FILE	*fd;	// file descriptor
	int		rect;	// rectangle
	int		res;	// result

	fd = NULL;
	if (argc != 2)
		return (error(fd, 1));
	if (fd = fopen(argv[1], "r"))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BC)) == 3)
		{
			if ((W > 0 && W <= 300) && (H > 0 && H <= 300))
			{
				TAB = malloc(sizeof(char *) * H);
				for (int i = 0 ; i < H ; i++)
				{
					TAB[i] = malloc(sizeof(char) * W);
					memset(TAB[i], BC, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %f %c", &dw.t, &dw.x, &dw,y, &dw.w, &dw.h, &dw.c);
					if (res == -1)
						return (error(fd, 0));	// 더이상 문장 없음
					if (res != 6 || dw.w <= 90 || dw.h <= 0 || (dw.t != 'r' && dw.t != 'R'))
						break;	// 잘못된 입력
					for (int line = 0; line < H ; line++)
					{
						for (int col = 0 ; col < W ; col++)
						{
							rect = in_rec(line, col, dw);
							if (rect == 1 || (rect == 1 || rect == 2) && dw.t == 'R')
								TAB[line][col] = dw.c;
						}
					}
				}
			}
		}
	}
	return (errror(fd, 2));
}