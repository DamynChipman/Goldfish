#include "HeatTimeDerivative.h"

registerMooseObject("GoldfishApp", HeatTimeDerivative);

InputParameters HeatTimeDerivative::validParams() {
	InputParameters params = ADTimeDerivative::validParams();
	params.addClassDescription(
		"Computes the time derivative of the heat diffusion equation."
	);
	params.addParam<Real>(
		"bulkDensity",
		1,
		"Bulk density of the material in [kg/m^3]."
	);
	params.addParam<Real>(
		"heatCapacity",
		1,
		"Heat capacity of the material in [J/(kg K)]."
	);

	return params;
}

HeatTimeDerivative::HeatTimeDerivative(const InputParameters & parameters) :
	ADTimeDerivative(parameters),
	_bulkDensity(getParam<Real>("bulkDensity")),
	_heatCapacity(getParam<Real>("heatCapacity"))
		{}

ADReal HeatTimeDerivative::precomputeQpResidual() {
	return _bulkDensity * _heatCapacity * _u_dot[_qp];
}