/*!
* \file   src/asterFullChabocheMemory.cxx
* \brief  This file implements the aster interface for the FullChabocheMemory behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/FullChabocheMemory.hxx"
#include"MFront/BehaviourProfiler.hxx"

#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterFullChabocheMemory.hxx"

static tfel::material::OutOfBoundsPolicy&
asterfullchabochememory_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_description, "FullChabocheMemory");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_mfront_ept, "asterfullchabochememory");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asterfullchabochememory_src, "FullChabocheMemory.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterfullchabochememory_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterfullchabochememory_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nMaterialProperties, 17u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_MaterialProperties, 17, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","R_0","C[0]","C[1]","g[0]",
"g[1]","ainf","b","m","K",
"Eta","Qm","Q0","Mu","delta[0]",
"delta[1]"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nInternalStateVariables, 7u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_InternalStateVariables, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"EquivalentPlasticStrain","a[0]","a[1]","q","Ksi",
"R"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterfullchabochememory_InternalStateVariablesTypes, 7, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0,1,1,0,1,0));

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asterfullchabochememory_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asterfullchabochememory_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_nParameters, 6u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterfullchabochememory_Parameters, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS("theta",
"epsilon","minimal_time_step_scaling_factor","maximal_time_step_scaling_factor","numerical_jacobian_epsilon","iterMax"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterfullchabochememory_ParametersTypes, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,0,0,0,2));

MFRONT_EXPORT_SYMBOL(double, asterfullchabochememory_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asterfullchabochememory_epsilon_ParameterDefaultValue, 1e-12);

MFRONT_EXPORT_SYMBOL(double, asterfullchabochememory_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asterfullchabochememory_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asterfullchabochememory_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-13);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_iterMax_ParameterDefaultValue, 100);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterfullchabochememory_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asterfullchabochememory_setParameter(const char *const key,const double value){
using tfel::material::FullChabocheMemoryParametersInitializer;
auto& i = FullChabocheMemoryParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asterfullchabochememory_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::FullChabocheMemoryParametersInitializer;
auto& i = FullChabocheMemoryParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asterfullchabochememory_setOutOfBoundsPolicy(const int p){
if(p==0){
asterfullchabochememory_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asterfullchabochememory_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asterfullchabochememory_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asterfullchabochememory_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asterfullchabochememory_getIntegrationErrorMessage(){
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
} // end of asterfullchabochememory_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
FullChabocheMemory(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asterfullchabochememory_getIntegrationErrorMessage();
using mfront::BehaviourProfiler;
using tfel::material::FullChabocheMemoryProfiler;
BehaviourProfiler::Timer total_timer(FullChabocheMemoryProfiler::getProfiler(),
BehaviourProfiler::TOTALTIME);
if(aster::AsterInterface<tfel::material::FullChabocheMemory>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asterfullchabochememory_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asterfullchabochememory(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
FullChabocheMemory(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
