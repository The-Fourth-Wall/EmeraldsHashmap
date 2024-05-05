#include "hashmap_functional_functions.h"

EmeraldsHashmap *hashmap_map(
  EmeraldsHashmap *map,
  EmeraldsHashmapLambda1 modifier,
  enum EmeraldsHashmapElementType element_type
) {
  size_t i;

  if(map == NULL || modifier == NULL) {
    return NULL;
  }

  /* Iterate with linear probing */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      switch(element_type) {
      case EM_HASH_KEYS:
        /* TODO CREATE ACCESSOR METHODS */
        map->data[i].key = modifier(map->data[i].key);
        break;
      case EM_HASH_VALUES:
        hashmap_set(map, map->data[i].key, modifier(map->data[i].data));
        break;
      default:
        return NULL;
      }
    }
  }

  return map;
}

EmeraldsHashmap *hashmap_filter(
  EmeraldsHashmap *map,
  EmeraldsHashmapLambda1 filter,
  enum EmeraldsHashmapElementType element_type
) {
  size_t i;

  if(map == NULL || filter == NULL) {
    return NULL;
  }

  /* Iterate with linear probing */
  for(i = 0; i < map->alloced; i++) {
    if(map->data[i].in_use != 0) {
      switch(element_type) {
      case EM_HASH_KEYS:
        /* If the key passes the filter we continue to the next */
        if(!filter(map->data[i].key)) {
          continue;
        }

        /* Delete the element with the specific key from the hashmap */
        hashmap_delete(map, map->data[i].key);
        break;
      case EM_HASH_VALUES:
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
  EmeraldsHashmap *map,
  EmeraldsHashmapLambda2 fold,
  enum EmeraldsHashmapElementType element_type
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
      case EM_HASH_KEYS:
        /* Set accumulator to some arbitrary hashmap key */
        accumulator = map->data[i].key;
        break;
      case EM_HASH_VALUES:
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
      case EM_HASH_KEYS:
        /* Get the current item */
        current = map->data[i].key;

        /* Accumulate the result */
        accumulator = fold(accumulator, current);
        break;
      case EM_HASH_VALUES:
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
