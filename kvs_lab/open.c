#include "kvs.h"


kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));

	if(kvs) {
		kvs->items = 0;
		/* 추가 코드 */
        	kvs->db = NULL; // Initialize the database as empty
	}
	/* 추가 코드 */
	printf("Open: kvs has %d items\n", kvs->items);

	return kvs;
}
