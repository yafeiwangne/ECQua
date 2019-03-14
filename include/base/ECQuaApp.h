//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef EC_QUAAPP_H
#define EC_QUAAPP_H

#include "MooseApp.h"

class ECQuaApp;

template <>
InputParameters validParams<ECQuaApp>();

class ECQuaApp : public MooseApp
{
public:
  ECQuaApp(InputParameters parameters);
  virtual ~ECQuaApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* EC_QUAAPP_H */
