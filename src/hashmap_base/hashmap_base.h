#ifndef __HASHMAP_BASE_H_
#define __HASHMAP_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */
/* TODO -> REPLACE WITH CUSTOM FUNCTIONS */
#include <string.h> /* strlen, strcmp */

/* Initial capacity of the hashmap */
static const size_t hashmap_init_capacity = 32;
static const size_t max_chain_length      = 8;

/**
 * @enum: EmeraldsHashmapElementType
 * @desc: Defines an enum of EM_HASH_KEYS or EM_HASH_VALUES
 **/
enum EmeraldsHashmapElementType { EM_HASH_KEYS, EM_HASH_VALUES };

/**
 * @struct: EmeraldsHashmapElement
 * @desc: Elements contained in the hashmap both keys and values
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
 * @desc: A hashmap struct that has some maximum size and
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

/* Return a 32-bit CRC of the contents of the buffer. */
/**
 * @func: crc32
 * @desc: Gets a 32-bit CEC of the contents of the buffer
 * @param s -> The key string
 * @param len -> The length of the key string
 * @return The crc32 value of the key string
 **/
static unsigned long crc32(const unsigned char *s, unsigned int len);

/**
 * @func: hashmap_hash_int
 * @desc: Hashing functions for a string
 * @param map -> The hashmap we want to modify the table size of
 * @param keystring -> The string to hash
 * @return A unique hashed int
 **/
static unsigned int hashmap_hash_int(EmeraldsHashmap *map, char *keystring);

/**
 * @func: hashmap_hash
 * @desc: Get the integer of the location in data to store it to the item
 * @param in -> The hashmap
 * @param key -> The key to hash
 * @return The location
 **/
static size_t hashmap_hash(EmeraldsHashmap *map, char *key);

/**
 * @func: hashmap_rehash
 * @desc: Doubles the size of the hashmap and rehashes all the elements
 * @param in -> The hashmap to rehash
 **/
static void hashmap_rehash(EmeraldsHashmap *map);

/**
 * @func: hashmap_new
 * @desc: Create an empty hashmap
 * @return: The hashmap
 **/
EmeraldsHashmap *hashmap_new(void);

/**
 * @func: hashmap_add
 * @desc: Add an element to the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the new element
 * @param value -> The value of the new element
 **/
void hashmap_add(EmeraldsHashmap *map, char *key, void *value);

/**
 * @func: hashmap_set
 * @desc: Set an element from the hashmap to a new one
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @param value -> The item to set to the specific key
 **/
void hashmap_set(EmeraldsHashmap *map, char *key, void *value);

/**
 * @func: hashmap_get
 * @desc: Get an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @return The value we are searching for
 **/
void *hashmap_get(EmeraldsHashmap *map, char *key);

/**
 * @func: hashmap_delete
 * @desc: Remove an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the element to remove
 **/
void hashmap_delete(EmeraldsHashmap *map, char *key);

/**
 * @func: hashmap_length
 * @desc: Get the current size of the hashmap
 * @param map -> The hashmap to use
 * @return The size of the provided hashmap
 **/
size_t hashmap_length(EmeraldsHashmap *map);

/**
 * @func: hashmap_free
 * @brief Frees the memory out of the hashmap
 * @param map -> The hashmap to free
 */
void hashmap_free(EmeraldsHashmap *map);

#endif
