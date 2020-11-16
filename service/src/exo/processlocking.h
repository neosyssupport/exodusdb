//generated by exodus "compile processlocking"
//#ifndef EXODUSDLFUNC_PROCESSLOCKING_H
#define EXODUSDLFUNC_PROCESSLOCKING_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_processlocking;
class efb_processlocking : public ExodusFunctorBase
{
public:

efb_processlocking(MvEnvironment& mv) : ExodusFunctorBase("processlocking", "exodusprogrambasecreatedelete_", mv) {}

efb_processlocking& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in mode, in processno, out result)
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
 //return CALLMEMBERFUNCTION(*(efb_processlocking.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_processlocking.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (mode,processno,result);

}

var operator() () {
 var mode_in;
 var processno_in;
 var result_out;
 return operator()(mode_in, processno_in, result_out);
}

var operator() (in mode) {
 var processno_in;
 var result_out;
 return operator()(mode, processno_in, result_out);
}

var operator() (in mode, in processno) {
 var result_out;
 return operator()(mode, processno, result_out);
}

};
efb_processlocking processlocking{mv};
//#endif