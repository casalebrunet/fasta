# Rudimentary FASTA file reading API

A very rudimentary FASTA file reading API that I found online. Designed for simplicity and clarity, not for robustness. 
In this version all autocastings have been fixed, and it ca be compiled without any worning from the compiler.

 ```
 ffp = OpenFASTA(seqfile);
 
 while (ReadFASTA(ffp, &seq, &name, &seqlen)
 {
        do stuff with sequence;
        free(name);
        free(seq);
 }
 
 CloseFASTA(ffp);
 ```
 
Where the arguments are:
 
 - **seqfile**: name of a FASTA file to open.
 - **seq**: one sequence
 - **name**: name of the sequence
 - **seqlen**: length of the sequence in residues
 - **ffp**: ptr to a FASTAFILE object.
 
Note that the sequence ends with a  ```'\0' ``` character which is not counted in seqlen
 
 
## API 

- ```OpenFASTA()``` returns a FASTAFILE pointer, or NULL on failure (for instance, if the file doesn't exist, or isn't readable).
- ```ReadFASTA()``` returns 1 on success, or a 0 if there are no more sequences to read in the file.
- ```CloseFASTA()``` *always* succeeds and returns void.

## Limitations

There is no error handling, for clarity's sake. Also, the parser is brittle. Improper FASTA files (for instance, blank lines between records) will cause unexpected behavior. Real file parsers are more complex. In real life, they have to deal with absolutely anything the user might pass as a "FASTA file"; and either parse it correctly, or detect that it's an invalid format and fail cleanly.
 
Lines are read in from the file using ANSI C's ```fgets()```. fgets requires a maximum buffer length (here, ```FASTA_MAXLINE```, which is defined as 512 in ```bio5495.h```). Some FASTA files have very long description lines, however; notably the NCBI NR database. Static limitations on things like line or sequence lengths should be avoided. An example of a replacement for fgets that dynamically allocates its buffer size and allows any line length is ```SQUID sre_fgets()```.
 
We use ANSI C's ```strtok()``` to parse the sequence name out of the line. strtok is deprecated in modern programs because it is not threadsafe.
 
