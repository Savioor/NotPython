//
// Created by alexey on 31/05/2020.
//

#include "ClassCreation.h"
#include "../../../memory/MemoryManager.h"
#include "../../../memory/builtins/PyCodeblock.h"
#include "../../../memory/builtins/PyVariable.h"
#include "../../../memory/builtins/classes/PyClassStructure.h"
#include "../../../memory/builtins/PyList.h"
#include "../../../memory/builtins/classes/PyMethod.h"

PyClass* ClassCreation::reduce(PyClass* first, PyClass* second, PyClass* third)
{
	if (first->type != pyVAR ||
		(second->type != pyARRAY && second->type != pyVAR
			&& second != MemoryManager::getManager().getNone()) ||
		third->type != pyCODE_BLOCK)
	{
		throw std::runtime_error(
			"Attempting to define class with illegal operators");
	}

	// Find parent class
	// TODO make sure base class is PyClassStructure
	PyClass* to_add = nullptr;
	std::string to_add_name = "";
	if (second->type == pyVAR)
	{
		auto* asVar = (PyVariable*)second;
		auto& insides = asVar->getRaw();
		if (insides.type != pyOTHER)
		{
			throw std::runtime_error("Class attempting to primitive");
		}
		to_add = &insides;
		to_add_name = asVar->getName();
	}
	else if (second->type == pyARRAY)
	{
		auto* asArr = (PyList*)second;
		if (asArr->getElements().size() > 1)
		{
			throw std::runtime_error("Classes can only inherit one element");
		}
		else if (!asArr->getElements().empty())
		{
			auto* insides = asArr->getElements().at(1);
			if (insides->type != pyVAR)
			{
				throw std::runtime_error("Class attempting to primitive");
			}
			PyVariable* asVar = (PyVariable*) insides;
			to_add = &asVar->getRaw();
			to_add_name = asVar->getName();
		}
	}

	// Handle this class
	PyClassStructure* returnStructure = new PyClassStructure();
	PyCodeblock* asCB = (PyCodeblock*)third;

	MemoryManager::getManager().increaseStackDepth();

	asCB->runAsClassStructure();
	std::map<std::string, PyVariable*>& createdVars =
		MemoryManager::getManager().namedVariableStack.at(MemoryManager::getManager().getCurrentDepth());

	for (auto& x: createdVars)
	{
		returnStructure->pointerMap.insert({ x.first, x.second });
	}

	MemoryManager::getManager().decreaseStackDepth();

	// Add super
	if (to_add == nullptr)
	{
		returnStructure->baseClass = MemoryManager::getManager().getObject();
		to_add_name = "Object";
	}
	else
	{
		returnStructure->baseClass = (PyClassStructure*)to_add;
	}

	// prefix super.__init__
	if (returnStructure->pointerMap.count("__init__") == 0)
	{
		auto* code = new PyCodeblock(
			to_add_name + ".__init__(self); return self;");
		std::string self = "self";
		auto* varName = new PyVariable(self);
		auto* init = new PyFunction(varName, code);
		returnStructure->pointerMap.insert({ "__init__",
											 new PyVariable(init) });
	}
	else
	{
		auto* asFunc =
			(PyFunction*)&returnStructure->pointerMap["__init__"]->getRaw();
		auto* innerCodeblock = (PyCodeblock*)&asFunc->pointerMap["b"]->getRaw();
		innerCodeblock->prefixInnit(to_add_name);
	}


	first->setSelf(*returnStructure);

	return returnStructure;
}

ClassCreation::ClassCreation()
{
	precedence = 16;
}
