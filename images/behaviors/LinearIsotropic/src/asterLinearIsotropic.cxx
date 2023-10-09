/*!
* \file   src/asterLinearIsotropic.cxx
* \brief  This file implements the aster interface for the LinearIsotropic behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/LinearIsotropic.hxx"
#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterLinearIsotropic.hxx"

static tfel::material::OutOfBoundsPolicy&
asterlinearisotropic_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_description, "A simple implementation of\nisotropic linear hardening plasticity .");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_mfront_ept, "asterlinearisotropic");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asterlinearisotropic_src, "LinearIsotropic.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearisotropic_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearisotropic_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nMaterialProperties, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_MaterialProperties, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","HardeningSlope","YieldStrength"));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nInternalStateVariables, 2u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_InternalStateVariables, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"EquivalentPlasticStrain"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearisotropic_InternalStateVariablesTypes, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0));

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asterlinearisotropic_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asterlinearisotropic_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_nParameters, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asterlinearisotropic_Parameters, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("minimal_time_step_scaling_factor",
"maximal_time_step_scaling_factor"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asterlinearisotropic_ParametersTypes, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0));

MFRONT_EXPORT_SYMBOL(double, asterlinearisotropic_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asterlinearisotropic_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asterlinearisotropic_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asterlinearisotropic_setParameter(const char *const key,const double value){
using tfel::material::LinearIsotropicParametersInitializer;
auto& i = LinearIsotropicParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asterlinearisotropic_setOutOfBoundsPolicy(const int p){
if(p==0){
asterlinearisotropic_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asterlinearisotropic_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asterlinearisotropic_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asterlinearisotropic_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asterlinearisotropic_getIntegrationErrorMessage(){
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
} // end of asterlinearisotropic_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
LinearIsotropic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asterlinearisotropic_getIntegrationErrorMessage();
if(aster::AsterInterface<tfel::material::LinearIsotropic>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asterlinearisotropic_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asterlinearisotropic(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
LinearIsotropic(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
