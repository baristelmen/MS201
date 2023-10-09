/*!
* \file   src/asterLinearKinematicViscosity.cxx
* \brief  This file implements the aster interface for the LinearKinematicViscosity behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/LinearKinematicViscosity.hxx"
#include"MFront/BehaviourProfiler.hxx"

#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterLinearKinematicViscosity.hxx"

static tfel::material::OutOfBoundsPolicy&
asterlinearkinematicviscosity_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_description, "Simple kinematic behavior with\nviscosity addition");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_mfront_ept, "asterlinearkinematicviscosity");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematicviscosity_src, "LinearKinematicViscosity.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematicviscosity_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematicviscosity_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nMaterialProperties, 5u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_MaterialProperties, 5, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","C","K","m"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nInternalStateVariables, 3u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_InternalStateVariables, 3, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"EquivalentPlasticStrain","a"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematicviscosity_InternalStateVariablesTypes, 3, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0,1));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asterlinearkinematicviscosity_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asterlinearkinematicviscosity_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_nParameters, 7u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematicviscosity_Parameters, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS("RelativeValueForTheEquivalentStressLowerBoundDefinition",
"theta","minimal_time_step_scaling_factor","maximal_time_step_scaling_factor","epsilon","numerical_jacobian_epsilon",
"iterMax"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematicviscosity_ParametersTypes, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,0,0,0,0,2));

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_RelativeValueForTheEquivalentStressLowerBoundDefinition_ParameterDefaultValue, 1e-12);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_epsilon_ParameterDefaultValue, 1e-08);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematicviscosity_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-09);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_iterMax_ParameterDefaultValue, 100);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematicviscosity_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asterlinearkinematicviscosity_setParameter(const char *const key,const double value){
using tfel::material::LinearKinematicViscosityParametersInitializer;
auto& i = LinearKinematicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asterlinearkinematicviscosity_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::LinearKinematicViscosityParametersInitializer;
auto& i = LinearKinematicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asterlinearkinematicviscosity_setOutOfBoundsPolicy(const int p){
if(p==0){
asterlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asterlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asterlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asterlinearkinematicviscosity_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asterlinearkinematicviscosity_getIntegrationErrorMessage(){
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
} // end of asterlinearkinematicviscosity_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
LinearKinematicViscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asterlinearkinematicviscosity_getIntegrationErrorMessage();
using mfront::BehaviourProfiler;
using tfel::material::LinearKinematicViscosityProfiler;
BehaviourProfiler::Timer total_timer(LinearKinematicViscosityProfiler::getProfiler(),
BehaviourProfiler::TOTALTIME);
if(aster::AsterInterface<tfel::material::LinearKinematicViscosity>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asterlinearkinematicviscosity_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asterlinearkinematicviscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
LinearKinematicViscosity(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
