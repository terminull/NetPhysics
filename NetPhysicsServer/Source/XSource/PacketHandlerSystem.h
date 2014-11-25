#ifndef PACKET_HANDLER_SYSTEM_H_INCLUDED
#define PACKET_HANDLER_SYSTEM_H_INCLUDED

#ifdef CLIENT
	#undef PACKET_HANDLER_SYSTEM_H_INCLUDED	
	#pragma once
	#include "NetPhysicsClient.h"
#endif /* CLIENT */

#include "XLib.h"
#include "System.h"
#include "PacketToBitStream.h"

class Register;

class PacketHandlerSystem : public System {
public:
	void handle(Register &engineRegister,
				XLib::Vector<PacketToBitStream> packets);
};

#endif