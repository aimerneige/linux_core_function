#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    char *filename = argv[1];

    struct stat sb;
    if (stat(filename, &sb) != -1) {
        printf("%s is %ld bytes long.\n", filename, sb.st_size);
    }

    return 0;
}


