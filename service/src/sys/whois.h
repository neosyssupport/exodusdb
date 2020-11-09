//generated by exodus "compile whois"
//#ifndef EXODUSDLFUNC_WHOIS_H
#define EXODUSDLFUNC_WHOIS_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_whois;
class efb_whois : public ExodusFunctorBase
{
public:

efb_whois(MvEnvironment& mv) : ExodusFunctorBase("whois", "exodusprogrambasecreatedelete_", mv) {}

efb_whois& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode, in ipno, out text)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,in,out);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_whois.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_whois.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode,ipno,text);

}

var operator() () {
 var mode_in;
 var ipno_in;
 var text_out;
 return operator()(mode_in, ipno_in, text_out);
}

var operator() (in mode) {
 var ipno_in;
 var text_out;
 return operator()(mode, ipno_in, text_out);
}

var operator() (in mode, in ipno) {
 var text_out;
 return operator()(mode, ipno, text_out);
}

};
efb_whois whois{mv};
//#endif
