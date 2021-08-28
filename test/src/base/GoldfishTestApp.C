//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "GoldfishTestApp.h"
#include "GoldfishApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
GoldfishTestApp::validParams()
{
  InputParameters params = GoldfishApp::validParams();
  return params;
}

GoldfishTestApp::GoldfishTestApp(InputParameters parameters) : MooseApp(parameters)
{
  GoldfishTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

GoldfishTestApp::~GoldfishTestApp() {}

void
GoldfishTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  GoldfishApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"GoldfishTestApp"});
    Registry::registerActionsTo(af, {"GoldfishTestApp"});
  }
}

void
GoldfishTestApp::registerApps()
{
  registerApp(GoldfishApp);
  registerApp(GoldfishTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
GoldfishTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GoldfishTestApp::registerAll(f, af, s);
}
extern "C" void
GoldfishTestApp__registerApps()
{
  GoldfishTestApp::registerApps();
}
