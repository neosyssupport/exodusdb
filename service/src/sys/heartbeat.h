//generated by exodus "compile ../sys/heartbeat"
//#ifndef EXODUSDLFUNC_HEARTBEAT_H
#define EXODUSDLFUNC_HEARTBEAT_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_heartbeat;
class efb_heartbeat : public ExodusFunctorBase
{
public:

efb_heartbeat(MvEnvironment& mv) : ExodusFunctorBase("heartbeat", "exodusprogrambasecreatedelete_", mv) {}

efb_heartbeat& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode, in status0="")
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
 //return CALLMEMBERFUNCTION(*(efb_heartbeat.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_heartbeat.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode,status0);

}

var operator() () {
 var mode_in;
 var status0_in = "";
 return operator()(mode_in, status0_in);
}

};
efb_heartbeat heartbeat{mv};
//#endif
