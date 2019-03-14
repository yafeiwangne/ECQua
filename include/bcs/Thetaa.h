//* This file is revised from CoupledNeumannBC

#ifndef THETAA_H
#define THETAA_H

#include "IntegratedBC.h"

// Forward Declarations
class Thetaa;
class Function;

template <>
InputParameters validParams<Thetaa>();

/**
 * Implements Neumann BC where grad(u)=-grad(v) on the boundary.
 */

class Thetaa : public IntegratedBC
{
public:

  Thetaa(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:

  const VariableValue & _coupled_var;
  /// int label for coupled_var for Jac
  unsigned int _coupled_var_jac;
 /**
   * Diffusivity.
 */ 
  const MaterialProperty<Real> & _K_O;
  
  
  Function & _func_1;
 
  Function & _func_2;
  
 
};

#endif
