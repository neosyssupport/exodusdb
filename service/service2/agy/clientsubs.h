//generated by exodus "compile clientsubs"
//#ifndef EXODUSDLFUNC_CLIENTSUBS_H
#define EXODUSDLFUNC_CLIENTSUBS_H

//a member variable/object to cache a pointer/object for the shared library function
ExodusFunctorBase efb_clientsubs;

//a member function with the right arguments, returning a var or void
var clientsubs(in mode)
{

 //first time link to the shared lib and create/cache an object from it
 //passing current standard variables in mv
 if (efb_clientsubs.pmemberfunction_==NULL)
  efb_clientsubs.init("clientsubs","exodusprogrambasecreatedelete_",mv);

 //define a function type (pExodusProgramBaseMemberFunction)
 //that can call the shared library object member function
 //with the right arguments and returning a var or void
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in);

 //call the shared library object main function with the right args,
 // returning a var or void
 return CALLMEMBERFUNCTION(*(efb_clientsubs.pobject_),
 ((pExodusProgramBaseMemberFunction) (efb_clientsubs.pmemberfunction_)))
  (mode);

}
//#endif
