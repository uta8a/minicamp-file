// reference: http://inaz2.hatenablog.com/entry/2014/07/04/001851
/* bof.c */
#include <stdio.h>
void vuln() {
    system("/bin/sh");
}
int main(void) {
    char buf[50];
    setlinebuf(stdout);
    printf("buf = %p\n", buf);
    gets(buf);
    puts(buf);
    return 0;
}

//  gcc -fno-stack-protector -z execstack bof.c -o bof