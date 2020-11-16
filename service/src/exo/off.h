//generated by exodus "compile off"
//#ifndef EXODUSDLFUNC_OFF_H
#define EXODUSDLFUNC_OFF_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_off;
class efb_off : public ExodusFunctorBase
{
public:

efb_off(MvEnvironment& mv) : ExodusFunctorBase("off", "exodusprogrambasecreatedelete_", mv) {}

efb_off& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() ()
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)();

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_off.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_off.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  ();

}
};
efb_off off{mv};
//#endif