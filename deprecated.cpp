//
// Deprecation warnings with GCC
//

#define DEPRECATED() __attribute__((__deprecated__))
#define DEPRECATED_MSG(x) __attribute__ ((__deprecated__(x)))

enum DeprecatedEnum {
  kDEValue,
  // kDeprecated DEPRECATED()  // This does not work under gcc 4.6
} DEPRECATED();

enum DeprecatedEnumMessage {
  kDEMValue
} DEPRECATED_MSG(
  "This enum is deprecated because we feel like making you change"
  " your code");

int
main(int argc, char** argv)
{
  DeprecatedEnum e1 = kDEValue;
  DeprecatedEnumMessage e2 = kDEMValue;
  return 0;
}
