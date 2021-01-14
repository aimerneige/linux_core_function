#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Get the size of a file.
 * @return The filesize, or 0 if the file does not exist.
 */
size_t getFilesize(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;   
}

int main(int argc, char const *argv[])
{
    char *filename = argv[1];

    struct stat sb;
    if (stat(filename, &sb) != -1) {
        printf("%s is %ld bytes long.\n", filename, sb.st_size);
    }

    return 0;
}


