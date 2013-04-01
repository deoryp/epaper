#include <stdio.h>
#include <stdint.h>
#include <string.h>

int atoi(char *p) {
	int k = 0;
	while (*p) {
		k = (k*10)+(*p)-'0';
		p++;
	}
	printf("%d\n", k);
	return k;
}

char dot(uint8_t byte, int bit) {
	return ((((1<<bit) & byte) >> bit) > 0) ? ' ' : '1';  
}

uint8_t tod(char c, int bit) {
	return (uint8_t)((c == ' ' ? 1 : 0) << bit);  
}

void asciiImage_readImage(char * file, uint8_t * image, int h, int w) {
	FILE * f = fopen(file, "r");
	int i, j, k;
	uint8_t pixelGroup;
	char c;
	int file_h = 0;
	int file_w = 0;
	char line_ending = '?';

	char line[16];
	char * l = &line[0];
	memset((uint8_t*)&line[0], 0, sizeof(line));

	// read width
	do {
		c = fgetc(f);
		if (c == ',') break;
		*l++ = c;	
 	} while (c != EOF);
	file_w = atoi(line);
	
	// reset line	
 	l = &line[0];
	memset((uint8_t*)&line[0], 0, sizeof(line));

	// read height
	do {
		c = fgetc(f);
		if (c == ',') break;
		*l++ = c;	
	} while (c != EOF);
	file_h = atoi(line);

	// reset line	
 	l = &line[0];
	memset((uint8_t*)&line[0], 0, sizeof(line));

	// read line ending
	line_ending = fgetc(f);	

	// now we are pointing to either newline or first char on image line.

	printf("going to look at file[%d, %d] with endings %c\n", file_w, file_h, line_ending);

	// reset line	
 	l = &line[0];
	memset((uint8_t*)&line[0], 0, sizeof(line));


	if (h != file_h) printf("height mismatch, might explode the shit\n");
	if ((w*8) != file_w) printf("width mismatch, might explode the shit\n");

	//read the lines.
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			k = 0;
			pixelGroup = 0;
			do {
				c = getc(f);
				if (c == line_ending || c == '\n') continue;
				pixelGroup += tod(c, 7-k);
				k++;
			} while (c != EOF && k < 8);		
			if (c == EOF) return;
			image[i*w+j] = pixelGroup;
		}
	}	
	fclose(f);
}

void asciiImage_printImage(uint8_t * image, int h, int w) {
	int i, j;
	printf("%d,%d,~\n", w, h);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			printf("%c%c%c%c%c%c%c%c",
				dot(*image, 7),
				dot(*image, 6),
				dot(*image, 5),
				dot(*image, 4),
				dot(*image, 3),
				dot(*image, 2),
				dot(*image, 1),
				dot(*image, 0));
			image++;
		}
		printf("~\n");
	}
}

