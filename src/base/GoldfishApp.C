#include "GoldfishApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
GoldfishApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

GoldfishApp::GoldfishApp(InputParameters parameters) : MooseApp(parameters)
{
  GoldfishApp::registerAll(_factory, _action_factory, _syntax);
}

GoldfishApp::~GoldfishApp() {}

void
GoldfishApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"GoldfishApp"});
  Registry::registerActionsTo(af, {"GoldfishApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
GoldfishApp::registerApps()
{
  registerApp(GoldfishApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
GoldfishApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GoldfishApp::registerAll(f, af, s);
}
extern "C" void
GoldfishApp__registerApps()
{
  GoldfishApp::registerApps();
}
