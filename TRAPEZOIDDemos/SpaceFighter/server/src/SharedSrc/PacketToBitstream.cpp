#include "packettobitstream.h"

PacketToBitStream::PacketToBitStream(RakNet::Packet* packet) :
	bitStream(new RakNet::BitStream(packet->data, packet->length, true)),
	guid(packet->guid)
{
	bitStream->Read(messageID);
	bitStream->ResetReadPointer();
}