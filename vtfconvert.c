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
void convert_vtf(char** argv);
void load_image(char** argv);
void print_usage();
void print_help(); /* TODO: Implement me. */
void verify_vtf(char* file);
void verify_file(char* file);

int main( int argc, char *argv[] ) 
{
	ilInit();
	printf("%o\n", ilTypeFromExt(argv[1]));
	if ( argc == ARGS) {
		load_image(argv);
	} else { 
		print_usage();
		return -1;
	}
	return 0;
}

void save_vtf(char** argv) 
{
	printf("Converting %s to %s.\n", argv[1], argv[2]);
	ilEnable(IL_FILE_OVERWRITE);
	ilSave(IL_VTF, argv[2]);
	verify_vtf(argv[2]);
}

void convert_vtf(char** argv) 
{
	ilEnable(IL_FILE_OVERWRITE);
	ilSaveImage(argv[2]);
	verify_file(argv[2]);
}

void load_image(char** argv)
{
	if (ilLoadImage(argv[1])) {
		printf("%s loaded successfully.\n", argv[1]);
		if (ilTypeFromExt(argv[1]) != IL_VTF) {
			save_vtf(argv);
		} else {
			convert_vtf(argv);
		}
	} else {
		printf("Image failed to load.\n");
	}
}

void print_usage() 
{
	printf( "Usage: vtfconvert <input file> <output>\n" );
}

void verify_vtf(char* file)
{
	if (ilIsValid(IL_VTF, file)) {
		printf("%s saved successfully.\n", file);
	} else {
		printf("ERROR: %s is corrupt.\n", file);
	}
}

void verify_file(char* file)
{
	if (ilIsValid(ilTypeFromExt(file), file)) {
		printf("%s saved successfully.\n", file);
	} else {
		printf("ERROR: %s is corrupt.\n", file);
	}
}
