//generated by exodus "compile dict_myclients"
//#ifndef EXODUSDLFUNC_DICT_MYCLIENTS_H
#define EXODUSDLFUNC_DICT_MYCLIENTS_H

//a member variable/object to cache a pointer/object for the shared library function
ExodusFunctorBase efb_dict_myclients;

//a member function with the right arguments, returning a var or void
var dict_myclients()
{

 //first time link to the shared lib and create/cache an object from it
 //passing current standard variables in mv
 if (efb_dict_myclients.pmemberfunction_==NULL)
  efb_dict_myclients.init("dict_myclients","exodusprogrambasecreatedelete_",mv);

 //define a function type (pExodusProgramBaseMemberFunction)
 //that can call the shared library object member function
 //with the right arguments and returning a var or void
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)();

 //call the shared library object main function with the right args,
 // returning a var or void
 return CALLMEMBERFUNCTION(*(efb_dict_myclients.pobject_),
 ((pExodusProgramBaseMemberFunction) (efb_dict_myclients.pmemberfunction_)))
  ();

}
//#endif