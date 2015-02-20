/* 
 * The program will try to identify the first argument given, if it's
 * identified as an image, it will be explicitly converted to the filenam
 * specified by the second argument as a VTF file. If a VTF file is detected,
 * the program will try and guess from the second argument's file extension
 * which format to use, falling back on TGA. 
 */

#include <stdio.h>
/* DEveloper's Imaging Library (DEVIL). */
#include <IL/il.h>

/* Number of arguments expected. */
#define ARGS (3)
void save_vtf(char** argv);
void load_image(char** argv);
void print_usage();
void print_help();

int main( int argc, char *argv[] ) 
{
	ilInit();
	if ( argc == 3) {
		load_image(argv);
	} else { 
		print_usage();
		return -1;
	}
	return 0;
}

void save_vtf(char** argv) 
{
	printf("Image loaded successfully.\n");
	printf("Trying to save as VTF.\n");
	ilEnable(IL_FILE_OVERWRITE);
	ilSave(IL_VTF, argv[2]);
	printf("Image saved successfully.\n");
}

void load_image(char** argv)
{
	if (ilLoadImage(argv[1])) {
		save_vtf(argv);
	} else {
		printf("Image failed to load.\n");
	}
}

void print_usage() 
{
	printf( "Usage: vtfconvert <input file> <output>\n" );
}
