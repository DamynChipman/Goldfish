#include "LandscapeDiffusion.h"

registerMooseObject("GoldfishApp", LandscapeDiffusion);

InputParameters LandscapeDiffusion::validParams() {
	InputParameters params = ADKernelGrad::validParams();
	params.addClassDescription(
		"Land diffusion kernel: `D` * `grad`^2. `D` is the land diffusivity."
	);
	params.addParam<Real>(
		"landDiffusivity",
		1,
		"Diffusivity of the land."
	);

	return params;
}

LandscapeDiffusion::LandscapeDiffusion(const InputParameters & parameters) :
	ADKernelGrad(parameters),
	_landDiffusivity(getParam<Real>("landDiffusivity"))
		{}

ADRealVectorValue LandscapeDiffusion::precomputeQpResidual() {
	return _landDiffusivity * _grad_u[_qp];
}