#include "kvs.h"

int close(kvs_t* kvs)
{
	/* do program */
	node_t* current = kvs->db;
	node_t* next;

	while (current != NULL) {
        	next = current->next;
        	free(current->value); // Free the value
		free(current); // Free the node
        	current = next;
    	}

    	free(kvs);
	/* do program */
	return 0;
}
