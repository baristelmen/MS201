/*!
* \file   src/asterNonLinearIsotropicLinearKinematic.cxx
* \brief  This file implements the aster interface for the NonLinearIsotropicLinearKinematic behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/NonLinearIsotropicLinearKinematic.hxx"
#include"MFront/BehaviourProfiler.hxx"

#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterNonLinearIsotropicLinearKinematic.hxx"

static tfel::material::OutOfBoundsPolicy&
asternonlinearisotropiclinearkinematic_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_description, "Implementation of non - linear isotropic\nhardening with linear kinematic hardening\nwith viscosity addition");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_mfront_ept, "asternonlinearisotropiclinearkinematic");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropiclinearkinematic_src, "NonLinearIsotropicLinearKinematic.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropiclinearkinematic_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropiclinearkinematic_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nMaterialProperties, 8u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_MaterialProperties, 8, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","R_inf","R_0","C","b",
"K","m"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nInternalStateVariables, 3u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_InternalStateVariables, 3, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"EquivalentPlasticStrain","BackStress"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropiclinearkinematic_InternalStateVariablesTypes, 3, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0,1));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asternonlinearisotropiclinearkinematic_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asternonlinearisotropiclinearkinematic_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_nParameters, 7u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropiclinearkinematic_Parameters, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS("RelativeValueForTheEquivalentStressLowerBoundDefinition",
"theta","epsilon","minimal_time_step_scaling_factor","maximal_time_step_scaling_factor","numerical_jacobian_epsilon",
"iterMax"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropiclinearkinematic_ParametersTypes, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,0,0,0,0,2));

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_RelativeValueForTheEquivalentStressLowerBoundDefinition_ParameterDefaultValue, 1e-12);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_epsilon_ParameterDefaultValue, 1e-13);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropiclinearkinematic_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-14);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_iterMax_ParameterDefaultValue, 100);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropiclinearkinematic_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asternonlinearisotropiclinearkinematic_setParameter(const char *const key,const double value){
using tfel::material::NonLinearIsotropicLinearKinematicParametersInitializer;
auto& i = NonLinearIsotropicLinearKinematicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asternonlinearisotropiclinearkinematic_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::NonLinearIsotropicLinearKinematicParametersInitializer;
auto& i = NonLinearIsotropicLinearKinematicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asternonlinearisotropiclinearkinematic_setOutOfBoundsPolicy(const int p){
if(p==0){
asternonlinearisotropiclinearkinematic_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asternonlinearisotropiclinearkinematic_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asternonlinearisotropiclinearkinematic_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asternonlinearisotropiclinearkinematic_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asternonlinearisotropiclinearkinematic_getIntegrationErrorMessage(){
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
} // end of asternonlinearisotropiclinearkinematic_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
NonLinearIsotropicLinearKinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asternonlinearisotropiclinearkinematic_getIntegrationErrorMessage();
using mfront::BehaviourProfiler;
using tfel::material::NonLinearIsotropicLinearKinematicProfiler;
BehaviourProfiler::Timer total_timer(NonLinearIsotropicLinearKinematicProfiler::getProfiler(),
BehaviourProfiler::TOTALTIME);
if(aster::AsterInterface<tfel::material::NonLinearIsotropicLinearKinematic>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asternonlinearisotropiclinearkinematic_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asternonlinearisotropiclinearkinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
NonLinearIsotropicLinearKinematic(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
