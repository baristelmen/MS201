/*!
* \file   src/asterNonLinearIsotropicNonLinearKinematic.cxx
* \brief  This file implements the aster interface for the NonLinearIsotropicNonLinearKinematic behaviour law
* \author 
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/NonLinearIsotropicNonLinearKinematic.hxx"
#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterNonLinearIsotropicNonLinearKinematic.hxx"

static tfel::material::OutOfBoundsPolicy&
asternonlinearisotropicnonlinearkinematic_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_author, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_description, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_mfront_ept, "asternonlinearisotropicnonlinearkinematic");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematic_src, "NonLinearIsotropicNonLinearKinematic.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematic_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematic_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nMaterialProperties, 9u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_MaterialProperties, 9, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","R_inf","R_0","b","C[0]",
"C[1]","g[0]","g[1]"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nInternalStateVariables, 4u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_InternalStateVariables, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"p","a[0]","a[1]"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematic_InternalStateVariablesTypes, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0,1,1));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asternonlinearisotropicnonlinearkinematic_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asternonlinearisotropicnonlinearkinematic_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_nParameters, 6u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematic_Parameters, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS("theta",
"minimal_time_step_scaling_factor","maximal_time_step_scaling_factor","epsilon","numerical_jacobian_epsilon","iterMax"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematic_ParametersTypes, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,0,0,0,2));

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematic_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematic_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematic_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematic_epsilon_ParameterDefaultValue, 1e-08);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematic_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-09);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_iterMax_ParameterDefaultValue, 100);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematic_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asternonlinearisotropicnonlinearkinematic_setParameter(const char *const key,const double value){
using tfel::material::NonLinearIsotropicNonLinearKinematicParametersInitializer;
auto& i = NonLinearIsotropicNonLinearKinematicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asternonlinearisotropicnonlinearkinematic_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::NonLinearIsotropicNonLinearKinematicParametersInitializer;
auto& i = NonLinearIsotropicNonLinearKinematicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicnonlinearkinematic_setOutOfBoundsPolicy(const int p){
if(p==0){
asternonlinearisotropicnonlinearkinematic_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asternonlinearisotropicnonlinearkinematic_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asternonlinearisotropicnonlinearkinematic_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asternonlinearisotropicnonlinearkinematic_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asternonlinearisotropicnonlinearkinematic_getIntegrationErrorMessage(){
#if (defined __GNUC__) && (!defined __clang__) && (!defined __INTEL_COMPILER) && (!defined __PGI)
#if __GNUC__ * 10000+__GNUC_MINOR__ * 100 <  40800
static __thread char msg[128];
#else
static thread_local char msg[128];
#endif
#else /* (defined __GNUC__) ...*/
static thread_local char msg[128];
#endif /* (defined __GNUC__) ...*/
return msg;
} // end of asternonlinearisotropicnonlinearkinematic_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
NonLinearIsotropicNonLinearKinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asternonlinearisotropicnonlinearkinematic_getIntegrationErrorMessage();
if(aster::AsterInterface<tfel::material::NonLinearIsotropicNonLinearKinematic>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asternonlinearisotropicnonlinearkinematic_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicnonlinearkinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
NonLinearIsotropicNonLinearKinematic(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
