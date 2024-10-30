#include "kvs.h"

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// workload execution  
	
	// 1) 	file read 
	FILE* file = fopen("query.dat", "r");
	if (!file) {
		printf("Failed to open file\n");
	        close(kvs);
	        return -1;
	    }
	
	char operation[10];
	char key[100];
	char value[100];
	// 2) 	if put, insert (key, value) into kvs.
	// 		if get, seach the key in kvs and return the value. 
	//		Return -1 if the key is not found  
	while (fscanf(file, "%s %s %s", operation, key, value) != EOF) {
		if (strcmp(operation, "put") == 0) {
            // put operation
			if (put(kvs, key, value) == -1) {
				printf("Failed to put key: %s\n", key);
			}
		} else if (strcmp(operation, "get") == 0) {
            // get operation
			char* result = get(kvs, key);
			if (result) {
				printf("Value for key %s: %s\n", key, result);
				free(result);
			} else {
                // Return -1 if the key is not found
				printf("Key %s not found\n", key);
			}
		}
	}
	
	fclose(file);
	/*edit end*/
	close(kvs);
	
	return 0;
}
