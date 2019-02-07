//generated by exodus "compile ../add/quickdexer"
//#ifndef EXODUSDLFUNC_QUICKDEXER_H
#define EXODUSDLFUNC_QUICKDEXER_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_quickdexer;
class efb_quickdexer : private ExodusFunctorBase
{
public:

efb_quickdexer(MvEnvironment& mv) : ExodusFunctorBase("quickdexer", "exodusprogrambasecreatedelete_", mv) {}

efb_quickdexer& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in filename, in mode, in v3, in v4)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,in,in,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_quickdexer.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_quickdexer.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (filename,mode,v3,v4);

}
};
efb_quickdexer quickdexer{mv};
//#endif