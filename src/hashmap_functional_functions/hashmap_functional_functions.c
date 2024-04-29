#include "hashmap_functional_functions.h"

hashmap *hashmap_map(
  hashmap *map, hashmap_lambda1 modifier, enum hashmap_element_type element_type
) {
  size_t i;

  if(map == NULL || modifier == NULL) {
    return NULL;
  }

  /* Iterate with linear probing */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      switch(element_type) {
      case KEYS:
        /* TODO CREATE ACCESSOR METHODS */
        map->data[i].key = modifier(map->data[i].key);
        break;
      case VALUES:
        hashmap_set(map, map->data[i].key, modifier(map->data[i].data));
        break;
      default:
        return NULL;
      }
    }
  }

  return map;
}

hashmap *hashmap_filter(
  hashmap *map, hashmap_lambda1 filter, enum hashmap_element_type element_type
) {
  size_t i;

  if(map == NULL || filter == NULL) {
    return NULL;
  }

  /* Iterate with linear probing */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      switch(element_type) {
      case KEYS:
        /* If the key passes the filter we continue to the next */
        if(!filter(map->data[i].key)) {
          continue;
        }

        /* Delete the element with the specific key from the hashmap */
        hashmap_delete(map, map->data[i].key);
        break;
      case VALUES:
        /* If the value passes the filter we continue to the next */
        if(!filter(map->data[i].data)) {
          continue;
        }

        /* Delete the element with the specific key from the hashmap */
        hashmap_delete(map, map->data[i].key);
        break;
      default:
        return NULL;
      }
    }
  }

  return map;
}

void *hashmap_reduce(
  hashmap *map, hashmap_lambda2 fold, enum hashmap_element_type element_type
) {
  void *accumulator = NULL;
  void *current     = NULL;
  int skip_first    = 1;
  size_t i;

  if(map == NULL || fold == NULL) {
    return NULL;
  }

  /* In general this takes constant time no matter the hashmap size */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      switch(element_type) {
      case KEYS:
        /* Set accumulator to some arbitrary hashmap key */
        accumulator = map->data[i].key;
        break;
      case VALUES:
        /* Set accumulator to some arbitrary hashmap value  */
        accumulator = hashmap_get(map, map->data[i].key);
        break;
      default:
        return NULL;
      }
      break;
    }
  }

  /* Iterate through the hashmap */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      if(skip_first == 1) {
        skip_first = 0;
        continue;
      }
      switch(element_type) {
      case KEYS:
        /* Get the current item */
        current = map->data[i].key;

        /* Accumulate the result */
        accumulator = fold(accumulator, current);
        break;
      case VALUES:
        /* Get the current item */
        current = hashmap_get(map, map->data[i].key);

        /* Accumulate the result */
        accumulator = fold(accumulator, current);
        break;
      default:
        return NULL;
      }
    }
  }

  return accumulator;
}
