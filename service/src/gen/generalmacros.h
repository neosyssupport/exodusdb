//generated by exodus "compile ../gen/generalmacros"
//#ifndef EXODUSDLFUNC_GENERALMACROS_H
#define EXODUSDLFUNC_GENERALMACROS_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_generalmacros;
class efb_generalmacros : public ExodusFunctorBase
{
public:

efb_generalmacros(MvEnvironment& mv) : ExodusFunctorBase("generalmacros", "exodusprogrambasecreatedelete_", mv) {}

efb_generalmacros& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode, out ftx, in clientmark0, in companycode0, in username0, in usercode0, in datetime0, in station0, in xglang0)
{

 //first time link to the shared lib and create/cache an object from it
 //passing current standard variables in mv
 //first time link to the shared lib and create/cache an object from it
 //passing current standard variables in mv
 //if (efb_getlang.pmemberfunction_==NULL)
 // efb_getlang.init("getlang","exodusprogrambasecreatedelete_",mv);
 if (this->pmemberfunction_==NULL)
  this->init();

 //define a function type (pExodusProgramBaseMemberFunction)
 //that can call the shared library object member function
 //with the right arguments and returning a var or void
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,out,in,in,in,in,in,in,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_generalmacros.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_generalmacros.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode,ftx,clientmark0,companycode0,username0,usercode0,datetime0,station0,xglang0);

}

var operator() () {
 var mode_in;
 var ftx_out;
 var clientmark0_in;
 var companycode0_in;
 var username0_in;
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode_in, ftx_out, clientmark0_in, companycode0_in, username0_in, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode) {
 var ftx_out;
 var clientmark0_in;
 var companycode0_in;
 var username0_in;
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx_out, clientmark0_in, companycode0_in, username0_in, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx) {
 var clientmark0_in;
 var companycode0_in;
 var username0_in;
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0_in, companycode0_in, username0_in, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0) {
 var companycode0_in;
 var username0_in;
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0_in, username0_in, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0, in companycode0) {
 var username0_in;
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0, username0_in, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0, in companycode0, in username0) {
 var usercode0_in;
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0, username0, usercode0_in, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0, in companycode0, in username0, in usercode0) {
 var datetime0_in;
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0, username0, usercode0, datetime0_in, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0, in companycode0, in username0, in usercode0, in datetime0) {
 var station0_in;
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0, username0, usercode0, datetime0, station0_in, xglang0_in);
}

var operator() (in mode, out ftx, in clientmark0, in companycode0, in username0, in usercode0, in datetime0, in station0) {
 var xglang0_in;
 return operator()(mode, ftx, clientmark0, companycode0, username0, usercode0, datetime0, station0, xglang0_in);
}

};
efb_generalmacros generalmacros{mv};
//#endif
