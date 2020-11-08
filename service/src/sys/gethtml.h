//generated by exodus "compile ../sys/gethtml"
//#ifndef EXODUSDLFUNC_GETHTML_H
#define EXODUSDLFUNC_GETHTML_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_gethtml;
class efb_gethtml : public ExodusFunctorBase
{
public:

efb_gethtml(MvEnvironment& mv) : ExodusFunctorBase("gethtml", "exodusprogrambasecreatedelete_", mv) {}

efb_gethtml& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode0, out html, in compcode0="")
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,out,in);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_gethtml.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_gethtml.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode0,html,compcode0);

}

var operator() () {
 var mode0_in;
 var html_out;
 var compcode0_in = "";
 return operator()(mode0_in, html_out, compcode0_in);
}

var operator() (in mode0) {
 var html_out;
 var compcode0_in = "";
 return operator()(mode0, html_out, compcode0_in);
}

};
efb_gethtml gethtml{mv};
//#endif
