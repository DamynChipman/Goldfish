#ifndef HEAT_TIME_DERIVATIVE_H_
#define HEAT_TIME_DERIVATIVE_H_
#pragma once

#include "ADTimeDerivative.h"

class HeatTimeDerivative : public ADTimeDerivative {
public:
	static InputParameters validParams();
	HeatTimeDerivative(const InputParameters & parameters);

protected:
	virtual ADReal precomputeQpResidual() override;
	const Real & _bulkDensity;
	const Real & _heatCapacity;

};

#endif // HEAT_TIME_DERIVATIVE_H_