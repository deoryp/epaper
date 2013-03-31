#include <stdio.h>
#include <stdint.h>

char dot(uint8_t byte, int bit) {

	return ((((1<<bit) & byte) >> bit) > 0) ? ' ' : '1';  
}

void asciiImage_printImage(uint8_t * pimage, int h, int w) {

	uint8_t * image = pimage;

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

