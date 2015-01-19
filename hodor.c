#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char hodor;
typedef int hhodor;

void HODOR(hodor* _hodor_input) {
    hodor* hodor_input = malloc((strlen(_hodor_input) + 1) * sizeof(hodor));
    strcpy(hodor_input, _hodor_input);

    hodor hodor_tokens_length = 100;
    hodor** hodor_tokens = malloc(hodor_tokens_length * sizeof(hodor*));

    hhodor hodor_count = 0;
    hodor* hodor_tok = strtok(hodor_input, " \n\t");

    while (hodor_tok != NULL) {
        if (hodor_count > hodor_tokens_length) {
            hodor_tokens_length *= 2;
            hodor_tokens = realloc(hodor_tokens, hodor_tokens_length * sizeof(hodor*));
        }

        hodor_tokens[hodor_count] = malloc(11 * sizeof(hodor));
        strcpy(hodor_tokens[hodor_count], hodor_tok);
        ++hodor_count;

        hodor_tok = strtok(NULL, " \n\t");
    }

    hodor hodor_data_length = 100;
    hodor* hodor_data = malloc(hodor_data_length * sizeof(hodor));
    hhodor hodor_tmp;
    for (hodor_tmp = 0; hodor_tmp < hodor_data_length; ++hodor_tmp) {
        hodor_data[hodor_tmp] = 0;
    }

    hhodor h = 0;
    hhodor hodor_marker = 0;
    while (h != hodor_count) {
        if (!strcmp(hodor_tokens[h], "hodorHODOR")) {
                ++hodor_marker;

                if (hodor_marker == hodor_data_length) {
                    hodor_data = realloc(hodor_data, hodor_data_length * 2 * sizeof(hodor));

                    for (hodor_tmp = hodor_data_length; hodor_tmp < hodor_data_length * 2; ++hodor_tmp) {
                        hodor_data[hodor_tmp] = 0;
                    }
                }
        } else if (!strcmp(hodor_tokens[h], "hodorhodor")) {
            --hodor_marker;
        } else if (!strcmp(hodor_tokens[h], "HODORHODOR")) {
            if (hodor_marker >= 0) {
                ++hodor_data[hodor_marker];
            }
        } else if (!strcmp(hodor_tokens[h], "HODORhodor")) {
            if (hodor_marker >= 0) {
                --hodor_data[hodor_marker];
            }
        } else if (!strcmp(hodor_tokens[h], "HODOR!")) {
            if (hodor_marker >= 0) {
                printf("%d ", hodor_data[hodor_marker]);
            }
        } else if (!strcmp(hodor_tokens[h], "HODOR?")) {
            if (hodor_marker >= 0) {
                hodor_data[hodor_marker] = getchar();
            }
        } else if (!strcmp(hodor_tokens[h], "hodor?")) {
            if (hodor_marker >= 0) {
                if (hodor_data[hodor_marker] == 0) {
                    do { ++h; }  while (h != hodor_count && strcmp(hodor_tokens[h], "hodor!"));
                    if (h == hodor_count) { return; }
                }
            }
        } else if (!strcmp(hodor_tokens[h], "hodor!")) {
            if (hodor_marker >= 0) {
                if (hodor_data[hodor_marker] != 0) {
                    do { --h; }  while (h != -1 && strcmp(hodor_tokens[h], "hodor?"));
                    if (h == -1) { return; }
                }
            }
        }

        ++h;
    }

    free(hodor_input);
    for (hodor_tmp = 0; hodor_tmp < hodor_tokens_length; ++hodor_tmp) {
        free(hodor_tokens[hodor_tmp]);
    }

    free(hodor_tokens);
    free(hodor_data);
}

int main(hhodor hodor_argc, hodor* hodor_argv[]) {
    if (hodor_argc == 2) {
        HODOR(hodor_argv[1]);
    } else if (hodor_argc == 3) {
        if (!strcmp(hodor_argv[1], "--hodor")) {
            char* buffer = 0;
            long length = 0;
            FILE* f = fopen(hodor_argv[2], "rb");

            if (f) {
                fseek (f, 0, SEEK_END);
                length = ftell(f);
                fseek (f, 0, SEEK_SET);
                buffer = malloc(length + 1);

                if (buffer) {
                    fread(buffer, 1, length, f);
                }

               fclose(f);

               buffer[length] = '\0';

               if (buffer) {
                   HODOR(buffer);
                   free(buffer);
               }
            } else {
                puts("HODOR?");
            }
        } else {
            puts("HODOR?");
        }
    } else {
        puts("HODOR HODOR HODOR HODOR!");
    }

    return 0;
}
