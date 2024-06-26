#include "../export/EmeraldsHashmap.h" /* IWYU pragma: keep */

#include <stdio.h>

int double_item(int item) { return item * 2; }

int positive_filter(int item) { return item < 0; }

int adder(int accumulator, int current) { return accumulator + current; }

int main(void) {
  EmeraldsHashmap *testh = hashmap_new();
  void *null_value       = NULL;
  void *hsum;

  hashmap_add(testh, "1", (void *)-11);
  hashmap_add(testh, "20", (void *)-2);
  hashmap_add(testh, "3", (void *)3);
  hashmap_add(testh, "42", (void *)-4);
  hashmap_add(testh, "5", (void *)5);
  hashmap_add(testh, "56", (void *)5);
  hashmap_add(testh, "500", (void *)6);
  hashmap_add(testh, "64", (void *)1);
  hashmap_add(testh, "7", (void *)1);

  printf("TESTING NON EXISTENT HASHMAP ELEMENT\n");
  null_value = hashmap_get(testh, "1241241");
  if(null_value == NULL) {
    printf("its null\n");
  } else {
    printf("its not null\n");
  }

  printf("TESTING HASH MAP FILTER REDUCE\n");
  testh =
    hashmap_map(testh, (EmeraldsHashmapLambda1)double_item, EM_HASH_VALUES);
  testh = hashmap_filter(
    testh, (EmeraldsHashmapLambda1)positive_filter, EM_HASH_VALUES
  );
  hsum = hashmap_reduce(testh, (EmeraldsHashmapLambda2)adder, EM_HASH_VALUES);
  printf("HASH SUM: `%ld` should be `42`\n\n", (long)hsum);

  hashmap_free(testh);

  return 0;
}
