#include "LandscapeUplift.h"

registerMooseObject("GoldfishApp", LandscapeUplift);

InputParameters LandscapeUplift::validParams() {
	InputParameters params = ADKernelValue::validParams();
	params.addClassDescription(
		"Uplift term `U` for landscape evolution."
	);
	params.addParam<Real>(
		"uplift",
		0,
		"Uplift of the land."
	);

	return params;
}

LandscapeUplift::LandscapeUplift(const InputParameters & parameters) :
	ADKernelValue(parameters),
	_uplift(getParam<Real>("uplift"))
		{}

ADReal LandscapeUplift::precomputeQpResidual() {
	return _uplift;
}