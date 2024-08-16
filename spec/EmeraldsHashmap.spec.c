#include "../libs/cSpec/export/cSpec.h"
#include "hashmap_base/hashmap_base.module.spec.h"
#include "hashmap_dup/hashmap_dup.module.spec.h"
#include "hashmap_functional_functions/hashmap_functional_functions.module.spec.h"

int main(void) {
  cspec_run_suite("all", {
    T_hashmap_base();
    T_hashmap_dup();
    T_hashmap_functional_functions();
  });
}
