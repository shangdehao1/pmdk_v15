// reader.c -- example from introduction part 1
#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>

#include "layout.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s file-name\n", argv[0]);
        return 1;
    }
    
    // Here we create the pool file with the name from the first argument.

    PMEMobjpool *pop = pmemobj_open(argv[1], LAYOUT_NAME);
    if (pop == NULL) {
        perror("pmemobj_open");
        return 1;
    }
    
    PMEMoid root = pmemobj_root(pop, sizeof(struct my_root));
    struct my_root *rootp = pmemobj_direct(root);
   
    if (rootp->len == strlen(rootp->buf)) {
        printf("%s\n", rootp->buf);
    }
    
    pmemobj_close(pop);
    
    return 0;
}
