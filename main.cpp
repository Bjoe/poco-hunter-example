
#include "Poco/Base64Encoder.h"
#include "Poco/Crypto/DigestEngine.h"

#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char** argv)
{

  std::istringstream istr(argv[1], std::ios::binary);
  std::string outstring;
  std::ostringstream ostr(outstring);

  Poco::Crypto::DigestEngine engine("SHA256");
  engine.update(istr.str());
  const Poco::DigestEngine::Digest& digest = engine.digest();

  Poco::Base64Encoder encoder(ostr);

  encoder << Poco::Crypto::DigestEngine::digestToHex(digest);

  std::cout << ostr.str() << '\n';
  return 0;
}
