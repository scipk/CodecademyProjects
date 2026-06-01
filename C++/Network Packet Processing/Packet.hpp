#include <string>
#include "PacketType.hpp"
#include "Protocol.hpp"
#include "Status.hpp"

class Packet {
private:
  std::string getPacketTypeName() const;
  std::string getStatusName() const;
  PacketType type;
  Protocol protocol;
  Status packetStatus;

public:
  Packet(PacketType pType, Protocol prtcl) : type(pType), protocol(prtcl) {};
  std::string getProtocolName();
  void validatePacket();
  bool isError();
  void displayInfo();
  void setType(PacketType newType);
};
