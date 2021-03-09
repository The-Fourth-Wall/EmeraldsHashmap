#ifndef __HASHMAP_FUNCTIONAL_FUNCTIONS_H_
#define __HASHMAP_FUNCTIONAL_FUNCTIONS_H_

#include "hashmap_base.h"

/**
 * @func: hashmap_lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void* (*hashmap_lambda)();

/**
 * @func: hashmap_map
 * @desc: Maps all hashmap elements in iteration using a modifier function pointer
 * @param map -> The hashmap to use
 * @param modifier -> The modifier function
 * @param element_type -> A type signaling whether we operate on keys or values
 * @return The mapped hashmap duplicate
 **/
hashmap *hashmap_map(hashmap *map, hashmap_lambda modifier, enum hashmap_element_type element_type);

/**
 * @func: hashmap_filter
 * @desc: Filters all hashmap elements in iteration using a filter function pointer
 * @param map -> The hashmap to use
 * @param filter -> The filter function
 * @param element_type -> A type signaling whether we operate on keys or values
 * @return The filtered hashmap duplicate
 **/
hashmap *hashmap_filter(hashmap *map, hashmap_lambda filter, enum hashmap_element_type element_type);

/**
 * @func: hashmap_reduce
 * @desc: Recudes all hashmap elements into a void* result using a foldl function pointer
 * @param map -> The hashmap to use
 * @param fold -> The folding function to use
 * @param element_type -> A type signaling whether we operate on keys or values
 * @return The folder void* result
 **/
void *hashmap_reduce(hashmap *map, hashmap_lambda fold, enum hashmap_element_type element_type);

#endif
