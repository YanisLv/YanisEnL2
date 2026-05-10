#include "pgm.h"
//#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* #define DEBUG 1 */
/* #define DEBUG_DEC 1 */


/* ********************************************************************* */
/* PGM Functions */
/* ********************************************************************* */
pgm_t *pgm_alloc(int width, int height)
{
	pgm_t *pgm=(pgm_t *)malloc(sizeof(pgm_t));
	if (pgm!=NULL)
	{
		pgm->height = height;
		pgm->width = width;

		pgm->max_value = 255;
		pgm->pixels = (unsigned char **)malloc(height*sizeof(unsigned char *));
		for (int l=0; l<height; ++l)
		{
			pgm->pixels[l] = (unsigned char *)malloc(width*sizeof(unsigned char));
		}
	}
	return pgm;
}

int pgm_free(pgm_t *pgm)
{
	for (int l=0; l<pgm->height; ++l)
	{
		free(pgm->pixels[l]);
	}
	free(pgm->pixels);
	free(pgm);
	return 0;
}

pgm_t *pgm_read(const char *fname)
{
	FILE *fd=fopen(fname, "r");
	if (fd==NULL) { exit(EXIT_FAILURE); }

	int height=0;
	int width=0;
	size_t read=0;
	size_t n=0;

	/* char str[BUFF_SIZE]; */
	char *format=NULL;
	read = getline(&format, &n, fd);
	/* free(format); */
	char *comment=NULL;
	read = getline(&comment, &n, fd);
	/* free(comment); */
	char *img_size=NULL;
	read = getline(&img_size, &n, fd);

#ifdef DEBUG
	printf("\n[DEBUG] pgm_read(): img_size:%s  \n",img_size);
#endif
	char *max_val=NULL;
	read = getline(&max_val, &n, fd);
	/* free(read); */

	/* char *sptr; */
	char *dummy = strtok(img_size," ");
	width = atoi(dummy);
	dummy = strtok(NULL," ");
	height = atoi(dummy);

	/* width = atoi(strtok_r(img_size," ",&sptr)); */
	/* height = atoi(strtok_r(img_size," ",&sptr)); */


	pgm_t *rpgm=pgm_alloc(width, height);
	rpgm->max_value = atoi(max_val);

#ifdef DEBUG
	printf("\n[DEBUG] pgm_read(): img_size:%s  W: %d   H:%d \n",img_size , rpgm->width, rpgm->height);
#endif
	/* free(img_size); */

	char *line=NULL;

	int lig=0;
	int col=0;
	int cnt=0;
	while ((read=getline(&line, &n, fd)) != -1)
	{
#ifdef DEBUG
		if (cnt<20){
			printf("%s",line);
		}
#endif

		lig = cnt/(rpgm->width);
		col = cnt%(rpgm->width);

		rpgm->pixels[lig][col] = (unsigned char)atoi(line);

		cnt = cnt + 1;
	}

	free(format);
	free(comment);
	free(img_size);
	free(max_val);
	free(line);

	fclose(fd);
	return rpgm;
}

int pgm_write(const char *fname, pgm_t *pgm)
{
	FILE *fd=fopen(fname, "w");
	if (fd==NULL) { exit(EXIT_FAILURE); }

#ifdef DEBUG
	printf("\n[DEBUG] pgm_write(): W:%d   H:%d  \n", pgm->width, pgm->height);
#endif

	fprintf(fd, "P2\n");
	fprintf(fd, "# Generated with MY_PGM_LIB version 0.0\n");
	fprintf(fd, "%d %d\n", pgm->width, pgm->height);
	fprintf(fd, "%d\n", pgm->max_value);

	for (int lig=0; lig < pgm->height; ++lig)
	{
		for (int col=0; col < pgm->width; ++col)
		{
			fprintf(fd, "%u\n", pgm->pixels[lig][col]);
		}
	}

	fclose(fd);
	return 0;
}

