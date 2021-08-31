#include "HeatDiffusion.h"

registerMooseObject("GoldfishApp", HeatDiffusion);

InputParameters HeatDiffusion::validParams() {
	InputParameters params = ADKernelGrad::validParams();
	params.addClassDescription(
		"Heat diffusion kernel: `k` * `grad`^2. `k` is the thermal conductivity."
	);
	params.addParam<Real>(
		"thermalConductivity",
		1,
		"Thermal conductivity of the material."
	);

	return params;
}

HeatDiffusion::HeatDiffusion(const InputParameters & parameters) :
	ADKernelGrad(parameters),
	_thermalConductivity(getParam<Real>("thermalConductivity"))
		{}

ADRealVectorValue HeatDiffusion::precomputeQpResidual() {
	return _thermalConductivity * _grad_u[_qp];
}