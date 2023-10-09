/*!
* \file   src/asterLinearKinematic.cxx
* \brief  This file implements the aster interface for the LinearKinematic behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/LinearKinematic.hxx"
#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterLinearKinematic.hxx"

static tfel::material::OutOfBoundsPolicy&
asterlinearkinematic_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_description, "An explicit implementation of a simple\nlinear kinematic behaviour .");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_mfront_ept, "asterlinearkinematic");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearkinematic_src, "LinearKinematic.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematic_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematic_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nMaterialProperties, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_MaterialProperties, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","s0","HardeningSlope"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nInternalStateVariables, 2u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_InternalStateVariables, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"a"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematic_InternalStateVariablesTypes, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,1));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asterlinearkinematic_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asterlinearkinematic_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_nParameters, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearkinematic_Parameters, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("minimal_time_step_scaling_factor",
"maximal_time_step_scaling_factor"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearkinematic_ParametersTypes, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0));

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematic_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asterlinearkinematic_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_ComputesInternalEnergy, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearkinematic_ComputesDissipatedEnergy, 1u);

MFRONT_SHAREDOBJ int
asterlinearkinematic_setParameter(const char *const key,const double value){
using tfel::material::LinearKinematicParametersInitializer;
auto& i = LinearKinematicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asterlinearkinematic_setOutOfBoundsPolicy(const int p){
if(p==0){
asterlinearkinematic_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asterlinearkinematic_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asterlinearkinematic_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asterlinearkinematic_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asterlinearkinematic_getIntegrationErrorMessage(){
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
} // end of asterlinearkinematic_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
LinearKinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asterlinearkinematic_getIntegrationErrorMessage();
if(aster::AsterInterface<tfel::material::LinearKinematic>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asterlinearkinematic_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asterlinearkinematic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
LinearKinematic(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
