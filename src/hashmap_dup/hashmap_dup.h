#ifndef __HASHMAP_DUP_H_
#define __HASHMAP_DUP_H_

#include "../hashmap_base/hashmap_base.h"

/**
 * @func: hashmap_dup
 * @desc: Create a memory duplicate of the hashmap
 * @param map -> The map to copy
 * @return The duplicate hashmap
 **/
EmeraldsHashmap *hashmap_dup(EmeraldsHashmap *map);

#endif
