#ifndef __HASHMAP_BASE_H_
#define __HASHMAP_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */
#include <string.h> /* strlen, strcmp */

/* Initial capacity of the hashmap */
static const size_t hashmap_init_capacity = 32;
static const size_t max_chain_length      = 8;

/**
 * @enum: EmeraldsHashmapElementType
 * @brief Defines an enum of EM_HASH_KEYS or EM_HASH_VALUES
 **/
enum EmeraldsHashmapElementType { EM_HASH_KEYS, EM_HASH_VALUES };

/**
 * @struct: EmeraldsHashmapElement
 * @brief Elements contained in the hashmap both keys and values
 * @param key -> The key of the element
 * @param data -> The value of the element
 * @param map_use -> Boolean used for hashmap operations and linear probing
 **/
struct EmeraldsHashmapElement {
  char *key;
  void *data;
  size_t in_use;
};

/**
 * @struct: EmeraldsHashmap
 * @brief A hashmap struct that has some maximum size and
 *          current size as well as the data to hold
 * @param alloced -> The maximum allocated size
 * @param length -> The current total size
 * @param data -> The data array contained
 **/
typedef struct EmeraldsHashmap {
  size_t alloced;
  size_t length;
  struct EmeraldsHashmapElement *data;
} EmeraldsHashmap;

/**
 * @brief Create an empty hashmap
 * @return: The hashmap
 **/
EmeraldsHashmap *hashmap_new(void);

/**
 * @brief Add an element to the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the new element
 * @param value -> The value of the new element
 **/
void hashmap_add(EmeraldsHashmap *map, char *key, void *value);

/**
 * @brief Set an element from the hashmap to a new one
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @param value -> The item to set to the specific key
 **/
void hashmap_set(EmeraldsHashmap *map, char *key, void *value);

/**
 * @brief Get an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @return The value we are searching for
 **/
void *hashmap_get(EmeraldsHashmap *map, char *key);

/**
 * @brief Remove an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the element to remove
 **/
void hashmap_delete(EmeraldsHashmap *map, char *key);

/**
 * @brief Get the current size of the hashmap
 * @param map -> The hashmap to use
 * @return The size of the provided hashmap
 **/
size_t hashmap_length(EmeraldsHashmap *map);

/**
 * @brief Frees the memory out of the hashmap
 * @param map -> The hashmap to free
 */
void hashmap_free(EmeraldsHashmap *map);

#endif
