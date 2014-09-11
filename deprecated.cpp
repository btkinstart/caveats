//
// Deprecation warnings with GCC
//

#define DEPRECATED(msg) __attribute__((__deprecated__(msg)))

enum DeprecatedEnum {
  kDEValue,
  // kDeprecated DEPRECATED()  // This does not work under gcc 4.6
} DEPRECATED();

enum DeprecatedEnumMessage {
  kDEMValue
} DEPRECATED(
  "This enum is deprecated because we feel like making you change"
  " your code");

int
main(int argc, char** argv)
{
  DeprecatedEnum e1 = kDEValue;
  DeprecatedEnumMessage e2 = kDEMValue;
  return 0;
}
