#ifndef HEAT_DIFFUSION_H_
#define HEAT_DIFFUSION_H_
#pragma once

#include "ADKernelGrad.h"

class HeatDiffusion : public ADKernelGrad {

public:
	static InputParameters validParams();
	HeatDiffusion(const InputParameters & parameters);

protected:
	virtual ADRealVectorValue precomputeQpResidual() override;
	const Real & _thermalConductivity;

};

#endif // HEAT_DIFFUSION_H_