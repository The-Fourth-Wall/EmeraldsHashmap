#include "headers/hashmap_dup.h"

hashmap *hashmap_dup(hashmap *map) {
    hashmap *dup = NULL;
    size_t i;

    if(map == NULL) return NULL;

    dup = hashmap_new();
    
    /* Iteratively copy all hashmap elements from one pointer to another */
    for(i = 0; i < map->alloced; i++)
        if(map->data[i].in_use != 0)
            hashmap_add(dup, map->data[i].key, map->data[i].data);

    return dup;
}
