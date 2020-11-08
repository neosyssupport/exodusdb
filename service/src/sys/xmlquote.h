//generated by exodus "compile ../sys/xmlquote"
//#ifndef EXODUSDLFUNC_XMLQUOTE_H
#define EXODUSDLFUNC_XMLQUOTE_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_xmlquote;
class efb_xmlquote : public ExodusFunctorBase
{
public:

efb_xmlquote(MvEnvironment& mv) : ExodusFunctorBase("xmlquote", "exodusprogrambasecreatedelete_", mv) {}

efb_xmlquote& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in string0)
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
 //return CALLMEMBERFUNCTION(*(efb_xmlquote.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_xmlquote.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (string0);

}

var operator() () {
 var string0_in;
 return operator()(string0_in);
}

};
efb_xmlquote xmlquote{mv};
//#endif
