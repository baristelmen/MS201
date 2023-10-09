/*!
* \file   src/asterNonLinearIsotropicNonLinearKinematicViscosity.cxx
* \brief  This file implements the aster interface for the NonLinearIsotropicNonLinearKinematicViscosity behaviour law
* \author Baris Telmen
* \date   
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/NonLinearIsotropicNonLinearKinematicViscosity.hxx"
#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterNonLinearIsotropicNonLinearKinematicViscosity.hxx"

static tfel::material::OutOfBoundsPolicy&
asternonlinearisotropicnonlinearkinematicviscosity_getOutOfBoundsPolicy(){
static auto policy = tfel::material::None;
return policy;
}

extern "C"{

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_author, "Baris Telmen");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_date, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_description, "Non - linear isotropic non - linear kinematic\nwith viscosity");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_build_id, "");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_mfront_ept, "asternonlinearisotropicnonlinearkinematicviscosity");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_tfel_version, "4.1.0");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_unit_system, "");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_mfront_mkt, 1u);

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_mfront_interface, "Aster");

MFRONT_EXPORT_SYMBOL(const char*, asternonlinearisotropicnonlinearkinematicviscosity_src, "NonLinearIsotropicNonLinearKinematicViscosity.mfront");

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nModellingHypotheses, 4u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_ModellingHypotheses, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("Axisymmetrical",
"PlaneStrain","GeneralisedPlaneStrain","Tridimensional"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nMainVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nGradients, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematicviscosity_GradientsTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_Gradients, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nThermodynamicForces, 1u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematicviscosity_ThermodynamicForcesTypes, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS(1));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_ThermodynamicForces, 1, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nTangentOperatorBlocks, 2u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_TangentOperatorBlocks, 2, MFRONT_EXPORT_ARRAY_ARGUMENTS("Stress",
"Strain"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_BehaviourType, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_BehaviourKinematic, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_SymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_ElasticSymmetryType, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_savesTangentOperator, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_TemperatureRemovedFromExternalStateVariables, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_UsableInPurelyImplicitResolution, 1u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nMaterialProperties, 11u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_MaterialProperties, 11, MFRONT_EXPORT_ARRAY_ARGUMENTS("YoungModulus",
"PoissonRatio","Rinf","R0","b","C[0]",
"C[1]","g[0]","g[1]","m","UNsurK"));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nInternalStateVariables, 4u);
MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_InternalStateVariables, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS("ElasticStrain",
"p","a[0]","a[1]"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematicviscosity_InternalStateVariablesTypes, 4, MFRONT_EXPORT_ARRAY_ARGUMENTS(1,0,1,1));

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nExternalStateVariables, 0u);
MFRONT_EXPORT_SYMBOL(const char * const *, asternonlinearisotropicnonlinearkinematicviscosity_ExternalStateVariables, nullptr);

MFRONT_EXPORT_SYMBOL(const int *, asternonlinearisotropicnonlinearkinematicviscosity_ExternalStateVariablesTypes, nullptr);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_nParameters, 6u);

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(const char *, asternonlinearisotropicnonlinearkinematicviscosity_Parameters, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS("theta",
"epsilon","iterMax","minimal_time_step_scaling_factor","maximal_time_step_scaling_factor","numerical_jacobian_epsilon"));

MFRONT_EXPORT_ARRAY_OF_SYMBOLS(int, asternonlinearisotropicnonlinearkinematicviscosity_ParametersTypes, 6, MFRONT_EXPORT_ARRAY_ARGUMENTS(0,0,2,0,0,0));

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematicviscosity_theta_ParameterDefaultValue, 1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematicviscosity_epsilon_ParameterDefaultValue, 1e-12);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_iterMax_ParameterDefaultValue, 200);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematicviscosity_minimal_time_step_scaling_factor_ParameterDefaultValue, 0.1);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematicviscosity_maximal_time_step_scaling_factor_ParameterDefaultValue, 1.7976931348623e+308);

MFRONT_EXPORT_SYMBOL(double, asternonlinearisotropicnonlinearkinematicviscosity_numerical_jacobian_epsilon_ParameterDefaultValue, 1e-13);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_requiresStiffnessTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_requiresThermalExpansionCoefficientTensor, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_ComputesInternalEnergy, 0u);

MFRONT_EXPORT_SYMBOL(unsigned short, asternonlinearisotropicnonlinearkinematicviscosity_ComputesDissipatedEnergy, 0u);

MFRONT_SHAREDOBJ int
asternonlinearisotropicnonlinearkinematicviscosity_setParameter(const char *const key,const double value){
using tfel::material::NonLinearIsotropicNonLinearKinematicViscosityParametersInitializer;
auto& i = NonLinearIsotropicNonLinearKinematicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
asternonlinearisotropicnonlinearkinematicviscosity_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::NonLinearIsotropicNonLinearKinematicViscosityParametersInitializer;
auto& i = NonLinearIsotropicNonLinearKinematicViscosityParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicnonlinearkinematicviscosity_setOutOfBoundsPolicy(const int p){
if(p==0){
asternonlinearisotropicnonlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
asternonlinearisotropicnonlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
asternonlinearisotropicnonlinearkinematicviscosity_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "asternonlinearisotropicnonlinearkinematicviscosity_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *asternonlinearisotropicnonlinearkinematicviscosity_getIntegrationErrorMessage(){
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
} // end of asternonlinearisotropicnonlinearkinematicviscosity_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
NonLinearIsotropicNonLinearKinematicViscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = asternonlinearisotropicnonlinearkinematicviscosity_getIntegrationErrorMessage();
if(aster::AsterInterface<tfel::material::NonLinearIsotropicNonLinearKinematicViscosity>::exe(msg,NTENS,DTIME,DROT,DDSOE,STRAN,DSTRAN,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,asternonlinearisotropicnonlinearkinematicviscosity_getOutOfBoundsPolicy(),aster::AsterStandardSmallStrainStressFreeExpansionHandler)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
asternonlinearisotropicnonlinearkinematicviscosity(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const STRAN,const aster::AsterReal *const DSTRAN,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
NonLinearIsotropicNonLinearKinematicViscosity(STRESS,STATEV,DDSOE,STRAN,DSTRAN,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
