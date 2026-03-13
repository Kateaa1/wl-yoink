#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("%s Error: Invalid argument count. See --help for usage.\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0){
        printf("USAGE= %s [file]\n", argv[0]);
        return 0;
    } else {
        FILE *pSource;
        pSource = fopen(argv[1], "r");
        if (pSource == NULL){
            perror(argv[0]);
            return 1;
        } 
        char copy_buffer[1024];
        FILE *pTarget;
        pTarget = popen("tr -d '\\r' | wl-copy", "w");
        if (pTarget == NULL){
            fprintf(stderr, "%s Error: call to wl-copy failed. Is it installed?\n", argv[0]);
            fclose(pSource);
            return 1;
        }
        while (fgets(copy_buffer, sizeof(copy_buffer), pSource)){
            fprintf(pTarget, "%s", copy_buffer);
        }
         
        fclose(pSource);
        pclose(pTarget);
        return 0;
    }
}


