//generated by exodus "compile ranges"
//#ifndef EXODUSDLFUNC_RANGES_H
#define EXODUSDLFUNC_RANGES_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_ranges;
class efb_ranges : public ExodusFunctorBase
{
public:

efb_ranges(MvEnvironment& mv) : ExodusFunctorBase("ranges", "exodusprogrambasecreatedelete_", mv) {}

efb_ranges& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (io ranges0, in basekey0="", in listid0="")
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(io,in,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_ranges.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_ranges.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (ranges0,basekey0,listid0);

}

var operator() () {
 var ranges0_io;
 var basekey0_in = "";
 var listid0_in = "";
 return operator()(ranges0_io, basekey0_in, listid0_in);
}

};
efb_ranges ranges{mv};
//#endif
