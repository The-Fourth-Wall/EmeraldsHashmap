#include "Hashmap.spec.h"

module(T_Hashmap, {
  describe("#get_value", {
    it("returns `Hello, World!`", {
      assert_that_charptr("Hello, World!" equals to "Hello, World!");
    });
  });
});

spec_suite({
  T_Hashmap();
});

int main(void) {
  run_spec_suite("all");
}
