[Mesh]
	file = goldfish.msh
[]

[Variables]
	[temperature]
		order = first
		family = lagrange
	[]
[]

[Kernels]
	[diffusion]
		type = HeatDiffusion
		variable = temperature
		thermalConductivity = 1
	[]
[]

[BCs]
	[tail]
		type = ADDirichletBC
		boundary = tail
		variable = temperature
		value = 1
	[]
	[head]
		type = ADDirichletBC
		boundary = head
		variable = temperature
		value = 0
	[]
[]

[Executioner]
	type = Steady
[]

[Outputs]
	execute_on = 'timestep_end'
	vtk = true
[]