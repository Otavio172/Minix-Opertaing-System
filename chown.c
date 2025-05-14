#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main() {
const char *fn = "chown.txt"; 
mode_t m = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
int c = creat(fn, m);
if (c == -1) {
perror("Error creating the file!");
return 1;
}

printf("File '%s' created successfully with mode %o.\n", fn, m);

uid_t no = 1002;
gid_t ng= 1001;

if (chown(fn, no, ng) == -1) {
perror("Error changing the ownership!");
close(c);
return 1;
}

printf("Ownership of '%s' changed successfully to UID: %d and GID: %d.\n", fn, no, ng);

if (close(c) == -1) {
perror("Error closing the file!");
return 1;
}

printf("File '%s' closed successfully.\n", fn);

return 0;
}