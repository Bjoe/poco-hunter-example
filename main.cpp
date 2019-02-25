
#include "Poco/Base64Encoder.h"
#include "Poco/StreamCopier.h"
#include "Poco/Crypto/DigestEngine.h"

#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>

int main(int, char** argv)
{
  std::istringstream istr(argv[1], std::ios::binary);

  Poco::Crypto::DigestEngine engine{"SHA256"};
  engine.update(istr.str());
  const Poco::DigestEngine::Digest& digest = engine.digest();

  std::string hexDigest = Poco::Crypto::DigestEngine::digestToHex(digest);
  std::cout << hexDigest << '\n';

  // ---------------------------------------------------------------------------
  std::ostringstream ostr{};
  Poco::Base64Encoder encoder{ostr};
  for(const std::uint8_t byte : digest)
  {
    encoder << byte;
  }
  encoder.close();
  std::cout << ostr.str() << '\n';

  // ---------------------------------------------------------------------------
  std::ostringstream ostr2{};
  Poco::Base64Encoder encoder2{ostr2, Poco::BASE64_URL_ENCODING};
  encoder2 << hexDigest;
  encoder2.close();
  std::cout << ostr2.str() << '\n';

  return 0;
}
