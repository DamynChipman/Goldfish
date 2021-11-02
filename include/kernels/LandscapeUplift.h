#ifndef LANDSCAPE_UPLIFT_H_
#define LANDSCAPE_UPLIFT_H_
#pragma once

#include "ADKernelValue.h"

class LandscapeUplift : public ADKernelValue {

public:
	static InputParameters validParams();
	LandscapeUplift(const InputParameters & parameters);

protected:
	virtual ADReal precomputeQpResidual() override;
	const Real & _uplift;

};


#endif // LANDSCAPE_UPLIFT_H_