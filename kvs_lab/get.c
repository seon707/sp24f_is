#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */
	node_t* current = kvs->db;

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
            // Found the key, return the value
			return strdup(current->value);
		}
		current = current->next;
	}

    // Key not found
	printf("Key not found: %s\n", key);
	return NULL;
	/* do program here */
	
	char* value = (char*)malloc(sizeof(char)*100);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}

	strcpy(value, "deadbeaf");
	return value;

}
