/*!
* \file   NonLinearIsotropicViscosity.cxx
* \brief  this file implements the NonLinearIsotropicViscosity Behaviour.
*         File generated by tfel version 4.1.0
* \author Baris Telmen
 */

#include<string>
#include<cstring>
#include<sstream>
#include<fstream>
#include<stdexcept>

#include"TFEL/Raise.hxx"
#include"TFEL/Material/NonLinearIsotropicViscosityBehaviourData.hxx"
#include"TFEL/Material/NonLinearIsotropicViscosityIntegrationData.hxx"
#include"TFEL/Material/NonLinearIsotropicViscosity.hxx"

namespace tfel::material{

mfront::BehaviourProfiler&
NonLinearIsotropicViscosityProfiler::getProfiler()
{
static mfront::BehaviourProfiler profiler("NonLinearIsotropicViscosity");
return profiler;
}

NonLinearIsotropicViscosityParametersInitializer&
NonLinearIsotropicViscosityParametersInitializer::get()
{
static NonLinearIsotropicViscosityParametersInitializer i;
return i;
}

NonLinearIsotropicViscosityParametersInitializer::NonLinearIsotropicViscosityParametersInitializer()
{
this->relative_value_for_the_equivalent_stress_lower_bound = 1e-12;
this->theta = 1;
this->epsilon = 1e-13;
this->jacobianComparisonCriterion = 1e-10;
this->minimal_time_step_scaling_factor = 0.1;
this->maximal_time_step_scaling_factor = 1.7976931348623e+308;
this->numerical_jacobian_epsilon = 1e-14;
this->iterMax = 100;
// Reading parameters from a file
NonLinearIsotropicViscosityParametersInitializer::readParameters(*this,"NonLinearIsotropicViscosity-parameters.txt");
}

void
NonLinearIsotropicViscosityParametersInitializer::set(const char* const key,
const double v){
using namespace std;
if(::strcmp("RelativeValueForTheEquivalentStressLowerBoundDefinition",key)==0){
this->relative_value_for_the_equivalent_stress_lower_bound = v;
} else if(::strcmp("theta",key)==0){
this->theta = v;
} else if(::strcmp("epsilon",key)==0){
this->epsilon = v;
} else if(::strcmp("jacobianComparisonCriterion",key)==0){
this->jacobianComparisonCriterion = v;
} else if(::strcmp("minimal_time_step_scaling_factor",key)==0){
this->minimal_time_step_scaling_factor = v;
} else if(::strcmp("maximal_time_step_scaling_factor",key)==0){
this->maximal_time_step_scaling_factor = v;
} else if(::strcmp("numerical_jacobian_epsilon",key)==0){
this->numerical_jacobian_epsilon = v;
} else {
tfel::raise("NonLinearIsotropicViscosityParametersInitializer::set: "
" no parameter named '"+std::string(key)+"'");
}
}

void
NonLinearIsotropicViscosityParametersInitializer::set(const char* const key,
const unsigned short v){
using namespace std;
if(::strcmp("iterMax",key)==0){
this->iterMax = v;
} else {
tfel::raise("NonLinearIsotropicViscosityParametersInitializer::set: "
"no parameter named '"+std::string(key)+"'");
}
}

double
NonLinearIsotropicViscosityParametersInitializer::getDouble(const std::string& n,
const std::string& v)
{
double value;
std::istringstream converter(v);
converter >> value;
tfel::raise_if(!converter||(!converter.eof()),
"NonLinearIsotropicViscosityParametersInitializer::getDouble: "
"can't convert '"+v+"' to double for parameter '"+ n+"'");
return value;
}

unsigned short
NonLinearIsotropicViscosityParametersInitializer::getUnsignedShort(const std::string& n,
const std::string& v)
{
unsigned short value;
std::istringstream converter(v);
converter >> value;
tfel::raise_if(!converter||(!converter.eof()),
"NonLinearIsotropicViscosityParametersInitializer::getUnsignedShort: "
"can't convert '"+v+"' to unsigned short for parameter '"+ n+"'");
return value;
}

void
NonLinearIsotropicViscosityParametersInitializer::readParameters(NonLinearIsotropicViscosityParametersInitializer& pi,const char* const fn){
auto tokenize = [](const std::string& line){
std::istringstream tokenizer(line);
std::vector<std::string> tokens;
std::copy(std::istream_iterator<std::string>(tokenizer),
std::istream_iterator<std::string>(),
std::back_inserter(tokens));
return tokens;
};
std::ifstream f(fn);
if(!f){
return;
}
size_t ln = 1u;
auto line = std::string{};
while(std::getline(f,line)){
auto tokens = tokenize(line);
auto throw_if = [ln = ln, line, fn](const bool mfront_c,
const std::string& mfront_error_message){
tfel::raise_if(mfront_c,"NonLinearIsotropicViscosityParametersInitializer::readParameters: "
"error at line '"+std::to_string(ln)+"' "
"while reading parameter file '"+std::string(fn)+"'"
"("+mfront_error_message+")");
};
if(tokens.empty()){
continue;
}
if(tokens[0][0]=='#'){
continue;
}
throw_if(tokens.size()!=2u,"invalid number of tokens");
if("RelativeValueForTheEquivalentStressLowerBoundDefinition"==tokens[0]){
pi.relative_value_for_the_equivalent_stress_lower_bound = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("theta"==tokens[0]){
pi.theta = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("epsilon"==tokens[0]){
pi.epsilon = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("jacobianComparisonCriterion"==tokens[0]){
pi.jacobianComparisonCriterion = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("minimal_time_step_scaling_factor"==tokens[0]){
pi.minimal_time_step_scaling_factor = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("maximal_time_step_scaling_factor"==tokens[0]){
pi.maximal_time_step_scaling_factor = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("numerical_jacobian_epsilon"==tokens[0]){
pi.numerical_jacobian_epsilon = NonLinearIsotropicViscosityParametersInitializer::getDouble(tokens[0],tokens[1]);
} else if("iterMax"==tokens[0]){
pi.iterMax = NonLinearIsotropicViscosityParametersInitializer::getUnsignedShort(tokens[0],tokens[1]);
} else {
throw_if(true,"invalid parameter '"+tokens[0]+"'");
}
}
}

} // end of namespace tfel::material
