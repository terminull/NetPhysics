#ifndef SCRIPT_COMPONENT_H_INCLUDED
#define SCRIPT_COMPONENT_H_INCLUDED

//Inherits Component
#include "Component.h"
//Assigning handle
#include "HandleManager.h"

//Forward Declarations
class Register;

class ScriptComponent : public Component {
public:
	
	ScriptComponent(HandleManager &handleManager, Register &engineRegister) : 
					Component(SCRIPT, handleManager.add(this, COMPONENT)),
					engineRegister(&engineRegister) {
		start();
	}

	~ScriptComponent() {
		destroy();
	}

	virtual void update(const double dt) = 0;
	virtual void start() {}
	virtual void destroy() {}

protected:

	Register* engineRegister;

};

#endif /* SCRIPT_COMPONENT_H_INCLUDED */