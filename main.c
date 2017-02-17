#include <stdlib.h>
#include "fasta.h"

int main(int argc, char **argv) {
    FASTAFILE *ffp;
    char *seq;
    char *name;
    int L;
    /* argv[1] is the name of a FASTA file */
    ffp = OpenFASTA(argv[1]);
    while (ReadFASTA(ffp, &seq, &name, &L)) {
        printf("name: %s\n", name);
        printf("size: %d\n", L);
        printf("%s\n\n", seq);


        free(seq);
        free(name);

    }
    CloseFASTA(ffp);

    exit(0);
}