//generated by exodus "compile autorun3"
//#ifndef EXODUSDLFUNC_AUTORUN3_H
#define EXODUSDLFUNC_AUTORUN3_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_autorun3;
class efb_autorun3 : private ExodusFunctorBase
{
public:

efb_autorun3(MvEnvironment& mv) : ExodusFunctorBase("autorun3", "exodusprogrambasecreatedelete_", mv) {}

efb_autorun3& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
}

//a member function with the right arguments, returning a var or void
var operator() (in docids0, in options0)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_autorun3.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_autorun3.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (docids0,options0);

}

};
efb_autorun3 autorun3{mv};
//#endif
