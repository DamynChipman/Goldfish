[Mesh]
	type = GeneratedMesh
	dim = 3
	nx = 50
	ny = 1
	nz = 1
	xmin = 0 	# [m]
	xmax = 5 	# [m]
	ymin = 0 	# [m]
	ymax = 0.4 	# [m]
	zmin = 0  	# [m]
	zmax = 0.4	# [m]
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
		thermalConductivity = 0.25 	# [W/(m K)]
	[]
	[time]
		type = HeatTimeDerivative
		variable = temperature
		bulkDensity = 920.0			# [kg/m^3]
		heatCapacity = 635.0		# [J/(kg K)]
	[]
[]

[Functions]
	[surface_function]
		type = SoilSurfaceFunction
		meanAnnualTemperature = -7.0	# [C]
		amplitude = 17.5				# [C]
	[]
[]

[BCs]
	[surface]
		type = ADFunctionDirichletBC
		boundary = left
		variable = temperature
		function = surface_function
	[]
	[bottom]
		type = ADDirichletBC
		boundary = right
		variable = temperature
		value = -7.0 # [C]
	[]
[]

[ICs]
	[initial]
		type = ConstantIC
		value = -7.0 # [C]
		variable = temperature
	[]
[]

[Executioner]
	type = Transient
	scheme = implicit-euler
	end_time = 270000		# [sec]; 30 dts
	# end_time =  126144000	# [sec]; 4 years
	# end_time = 315360000	# [sec]; 10 years
	dt = 9000				# [sec]

	petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
	petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
	execute_on = 'timestep_end'
	exodus = true
[]