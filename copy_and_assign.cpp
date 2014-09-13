


#include <sstream>
#include <vector>


int
main(
  int argc, char** argv)
{

  std::ostringstream s1;
  //std::ostringstream s2 = s1;  // fails to compile on gcc 4.6
  //std::vector<std::ostringstream> svec;
  //svec.push_back(s1);
  return 0;
}

