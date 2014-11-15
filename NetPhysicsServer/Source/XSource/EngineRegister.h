#ifndef ENGINE_REGISTER_H_INCLUDED
#define ENGINE_REGISTER_H_INCLUDED

#ifdef CLIENT
	#undef ENGINE_REGISTER_H	
	#pragma once
	#include "NetPhysicsClient.h"
#endif /* CLIENT */

#ifdef CLIENT
#include "Engine\World.h"
#include "AllowWindowsPlatformTypes.h"
#endif /* CLIENT */
#include "RakPeerInterface.h"
#ifdef CLIENT
#include "HideWindowsPlatformTypes.h"
#endif /* CLIENT */

#include "XLib.h"
#include "HandleManager.h"
#ifdef SERVER
	#include "GameObjectManager.h"
#endif /* SERVER */
#include "NetworkHandleManager.h"
#include "ComponentManager.h"
#include "ComponentType.h"
#include "SystemType.h"




class System;

class EngineRegister {
public:
	void init();
	void update(double dt);

	HandleManager* getHandleManager();
	NetworkHandleManager* getNetworkHandleManager();

#ifdef SERVER
	GameObjectManager* getGameObjectManager();
#endif /* SERVER */
#ifdef CLIENT
	void setWorld(UWorld* world);
	UWorld* getWorld();
#endif /* CLIENT */

	RakNet::RakPeerInterface* getRakPeerInstance();

	ComponentManager* getComponentManager(ComponentType type);
	System* getSystem(SystemType type);

	void initSystem(System* newSystem, SystemType type);
	void removeSystem(SystemType type);


private:

#ifdef CLIENT
	//Pointer to unreal engine world.
	UWorld* world;
#endif /* CLIENT */
	//Ptr to server instance of RakNet.
	RakNet::RakPeerInterface *rakPeerInstance;
	//"Data Indexers" for local and network data
	HandleManager handleManager;
	NetworkHandleManager networkHandleManager;

#ifdef SERVER
	//Game Object Manager
	GameObjectManager gameObjectManager;
#endif /* SERVER */

	//Abstract base class containers for components and systems.
	XLib::Vector<ComponentManager> componentManagerContainer;
	XLib::Vector<XLib::SharedPtr<System>> systemContainer;

};


#endif /* ENGINE_REGISTER_H_INCLUDED */