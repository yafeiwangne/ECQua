#include "ECQuaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ECQuaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ECQuaApp::ECQuaApp(InputParameters parameters) : MooseApp(parameters)
{
  ECQuaApp::registerAll(_factory, _action_factory, _syntax);
}

ECQuaApp::~ECQuaApp() {}

void
ECQuaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"ECQuaApp"});
  Registry::registerActionsTo(af, {"ECQuaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ECQuaApp::registerApps()
{
  registerApp(ECQuaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ECQuaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ECQuaApp::registerAll(f, af, s);
}
extern "C" void
ECQuaApp__registerApps()
{
  ECQuaApp::registerApps();
}
