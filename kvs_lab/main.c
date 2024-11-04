#include "kvs.h"
#include <stdio.h>
#include <string.h>

int main()
{
        kvs_t* kvs = open();

        if(!kvs) {
                printf("Failed to open kvs\n");
                return -1;
        }

        // workload execution  

        // 1)   file read 
        FILE* query_file = fopen("query.dat", "r");
        if (!query_file) {
                printf("Failed to open file\n");
                close(kvs);
                return -1;
            }

        FILE* answer_file = fopen("answer.dat", "w");
        if(!answer_file){
                printf("Failed to open answer file\n");
                fclose(query_file);
                close(kvs);
                return -1;

        char operation[10];
        char key[100];
        char value[100];
        // 2)   if put, insert (key, value) into kvs.
        //              if get, seach the key in kvs and return the value. 
        //              Return -1 if the key is not found  
        while (fscanf(query_file, "%[^,], %[^,], %s\n", operation, key, value) != EOF) {
                if (strcmp(operation, "set") == 0) {
            // set operation
                        if (put(kvs, key, value) == -1) {
                                fprintf(answer_file,"Failed to put key: %s\n", key);
                        }
                } else if (strcmp(operation, "get") == 0) {
            // get operation
                        char* result = get(kvs, key);
                        if (result) {
                                fprintf(answer_file,"Value for key %s: %s\n", key, result);
                                free(result);
                        } else {
                // Return -1 if the key is not found
                                fprintf(answer_file,"Key %s not found\n", key);
                        }
                }
        }

        fclose(query_file);
        fclose(answer_file);
        /*edit end*/
        close(kvs);

        return 0;
        }
}

