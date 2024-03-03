#include <stdio.h>
#include <ctype.h>
#include <string.h>
 #include <Windows.h>
void output_w(FILE* _out, const char* s, const char* pfx){
    const char*  p = s;
    const size_t n = strlen(pfx);
 
    while((p = strstr(p, pfx)) != NULL){
        if((p == s) || ! isalpha(*(p - 1))){
            if(! strncmp(p, pfx, n)){
 
                while(isalpha(*p))
                    fputc(*p++, _out);
 
                fputc('\n', _out);
                continue;
            }
        }
        p += n;
    }
}
 
int main(void){
	
    char buf[64] = "подъезд, подн€ть, мышь, €блоко, экран";
    char pfx[16] = "под";

    output_w(stdout, buf, pfx);
    return 0;
}
