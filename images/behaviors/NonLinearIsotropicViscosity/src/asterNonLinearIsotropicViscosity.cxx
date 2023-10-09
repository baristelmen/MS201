/*!
* \file   src/asterNonLinearIsotropicViscosity.cxx
* \brief  This file implements the aster interface for the NonLinearIsotropicViscosity behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/NonLinearIsotropicViscosity.hxx"
#include"MFront/BehaviourProfiler.hxx"

#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterNonLinearIsotropicViscosity.hxx"

static tfel::material::OutOfBoundsPolicy&
asternonlinearisotropicviscosity_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_description, "Non - Linear isotropic hardening with\nviscosity addition");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_mfront_ept, "asternonlinearisotropicviscosity");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicviscosity_src, "NonLinearIsotropicViscosity.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicviscosity_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicviscosity_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nMaterialProperties, 7u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_MaterialProperties, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","R_inf","R_0","b","K",
"m"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nInternalStateVariables, 2u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_InternalStateVariables, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"EquivalentPlasticStrain"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicviscosity_InternalStateVariablesTypes, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asternonlinearisotropicviscosity_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asternonlinearisotropicviscosity_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_nParameters, 8u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicviscosity_Parameters, 8, MFRONT_EXPORT_ARRAY_ARGUMENTS("RelativeValueForTheEquivalentStressLowerBoundDefinition",
"theta","epsilon","jacobianComparisonCriterion","minimal_time_step_scaling_factor","maximal_time_step_scaling_factor",
"numerical_jacobian_epsilon","iterMax"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicviscosity_ParametersTypes, 8, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,0,0,0,0,0,2));

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_RelativeValueForTheEquivalentStressLowerBoundDefinition_ParameterDefaultValue, 1e-12);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_epsilon_ParameterDefaultValue, 1e-13);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_jacobianComparisonCriterion_ParameterDefaultValue, 1e-10);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicviscosity_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-14);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_iterMax_ParameterDefaultValue, 100);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicviscosity_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asternonlinearisotropicviscosity_setParameter(const char *const key,const double value){
using tfel::material::NonLinearIsotropicViscosityParametersInitializer;
auto& i = NonLinearIsotropicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asternonlinearisotropicviscosity_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::NonLinearIsotropicViscosityParametersInitializer;
auto& i = NonLinearIsotropicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicviscosity_setOutOfBoundsPolicy(const int p){
if(p==0){
asternonlinearisotropicviscosity_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asternonlinearisotropicviscosity_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asternonlinearisotropicviscosity_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asternonlinearisotropicviscosity_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asternonlinearisotropicviscosity_getIntegrationErrorMessage(){
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
} // end of asternonlinearisotropicviscosity_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
NonLinearIsotropicViscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asternonlinearisotropicviscosity_getIntegrationErrorMessage();
using mfront::BehaviourProfiler;
using tfel::material::NonLinearIsotropicViscosityProfiler;
BehaviourProfiler::Timer total_timer(NonLinearIsotropicViscosityProfiler::getProfiler(),
BehaviourProfiler::TOTALTIME);
if(aster::AsterInterface<tfel::material::NonLinearIsotropicViscosity>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asternonlinearisotropicviscosity_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicviscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
NonLinearIsotropicViscosity(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
