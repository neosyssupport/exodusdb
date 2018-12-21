//generated by exodus "compile ../sys/printtx"
//#ifndef EXODUSDLFUNC_PRINTTX_H
#define EXODUSDLFUNC_PRINTTX_H

//a member variable/object to cache a pointer/object for the shared library function
ExodusFunctorBase efb_printtx;

//a member function with the right arguments, returning a var or void
var printtx(io tx, in mode="", in modevalue="")
{

 //first time link to the shared lib and create/cache an object from it
 //passing current standard variables in mv
 if (efb_printtx.pmemberfunction_==NULL)
  efb_printtx.init("printtx","exodusprogrambasecreatedelete_",mv);

 //define a function type (pExodusProgramBaseMemberFunction)
 //that can call the shared library object member function
 //with the right arguments and returning a var or void
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(io,in,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 return CALLMEMBERFUNCTION(*(efb_printtx.pobject_),
 ((pExodusProgramBaseMemberFunction) (efb_printtx.pmemberfunction_)))
  (tx,mode,modevalue);

}
//#endif