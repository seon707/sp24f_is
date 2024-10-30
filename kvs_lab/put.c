#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	printf("put: %s, %s\n", key, value);
	/* do program here */
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (!new_node) {
        printf("Failed to allocate memory for new node\n");
        return -1;
    }

    // 키와 값을 설정
    strncpy(new_node->key, key, sizeof(new_node->key));
    new_node->value = strdup(value); // value를 동적으로 복사
    new_node->next = NULL;

    // 첫 번째 노드로 추가하거나 끝에 추가
    if (kvs->db == NULL) {
        kvs->db = new_node;
    } else {
	    node_t* current = kvs->db;
	    while (current->next != NULL) {
            	if (strcmp(current->key, key) == 0) {
                // 기존 키 업데이트
                	free(current->value);
                	current->value = strdup(value);
                	free(new_node);
                	return 0;
            	}
            	current = current->next;
	    }
	    current->next = new_node;
    	}

	kvs->items++;
	/* do program here */
	return 0;
}
