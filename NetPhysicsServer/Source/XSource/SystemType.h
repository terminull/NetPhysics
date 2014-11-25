#ifndef SYSTEM_TYPE_H_INCLUDED
#define SYSTEM_TYPE_H_INCLUDED

#ifdef CLIENT
	#undef SYSTEM_TYPE_H_INCLUDED	
	#pragma once
	#include "NetPhysicsClient.h"
#endif /* CLIENT */

enum SystemType {
	SERVER_SYSTEM,
#ifdef SERVER
	CLIENT_SYSTEM,
	PHYSICS_SYSTEM,
	PLAYER_INIT_SYSTEM,
#endif /* SERVER */
#ifdef CLIENT
	CONNECTION_SYSTEM,
#endif /* CLIENT */
	PACKET_HANDLER_SYSTEM,
	NETWORK_SYSTEM,
	NUM_SYSTEM_TYPES,
};

#endif