//generated by exodus "compile ../sys/definitionsubs"
//#ifndef EXODUSDLFUNC_DEFINITIONSUBS_H
#define EXODUSDLFUNC_DEFINITIONSUBS_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_definitionsubs;
class efb_definitionsubs : public ExodusFunctorBase
{
public:

efb_definitionsubs(MvEnvironment& mv) : ExodusFunctorBase("definitionsubs", "exodusprogrambasecreatedelete_", mv) {}

efb_definitionsubs& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_definitionsubs.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_definitionsubs.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode);

}

var operator() () {
 var mode_in;
 return operator()(mode_in);
}

};
efb_definitionsubs definitionsubs{mv};
//#endif
