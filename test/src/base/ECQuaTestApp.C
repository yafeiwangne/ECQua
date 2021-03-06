//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ECQuaTestApp.h"
#include "ECQuaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ECQuaTestApp>()
{
  InputParameters params = validParams<ECQuaApp>();
  return params;
}

ECQuaTestApp::ECQuaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ECQuaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ECQuaTestApp::~ECQuaTestApp() {}

void
ECQuaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ECQuaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ECQuaTestApp"});
    Registry::registerActionsTo(af, {"ECQuaTestApp"});
  }
}

void
ECQuaTestApp::registerApps()
{
  registerApp(ECQuaApp);
  registerApp(ECQuaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ECQuaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ECQuaTestApp::registerAll(f, af, s);
}
extern "C" void
ECQuaTestApp__registerApps()
{
  ECQuaTestApp::registerApps();
}
