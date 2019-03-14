//* This file is is revised from CoupledNeumannBC, C_R take the flux from C_O


#include "Thetaa.h"
#include "Function.h"

registerMooseObject("ECQuaApp", Thetaa);

template <>
InputParameters
validParams<Thetaa>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_var", "Coupled the variable C_R.");
  
  params.addParam<MaterialPropertyName>("K_O","K_O", "standard reaction rate.");
  params.addParam<MaterialPropertyName>("D_R","D_R", "Diffusivity for reducing agent.");
  params.addRequiredParam<FunctionName>("Exp_1", "Exp_1 term in Butler Volmer Eq");
  params.addRequiredParam<FunctionName>("Exp_2", "Exp_2 term in Butler Volmer Eq");

  return params;
}

Thetaa::Thetaa(const InputParameters & parameters)
  : IntegratedBC(parameters),

    _coupled_var(coupledValue("coupled_var")),
    _coupled_var_jac(coupled("coupled_var")),
    _K_O(getMaterialProperty<Real>("K_O")),
    _func_1(getFunction("Exp_1")),
    _func_2(getFunction("Exp_2"))

{
}


Real
Thetaa::computeQpResidual()
{
    return  _test[_i][_qp] *(_u[_qp]*_func_1.value(_t, _q_point[_qp])- _coupled_var[_qp]*_func_2.value(_t, _q_point[_qp]))* _K_O[_qp];
}

//This will improve convergence
Real
Thetaa::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _coupled_var_jac)
    return _test[_i][_qp] *_phi[_j][_qp] * (-_K_O[_qp])*_func_2.value(_t, _q_point[_qp]);
  else
    return 0.;
}

