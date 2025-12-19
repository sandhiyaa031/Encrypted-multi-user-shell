#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>  // for wait()

int main() {
    chdir("/tmp");       // test chdir
    mkdir("testdir", 0700); // test mkdir
    rmdir("testdir");    // test rmdir
    unlink("file.txt");  // test unlink
    struct stat sb;
    stat("file.txt", &sb); // test stat
    pid_t pid = fork();     // test fork
    if(pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args); // test execvp
    }
    wait(NULL);
    return 0;
}
