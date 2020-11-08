//generated by exodus "compile ../sys/xbytes"
//#ifndef EXODUSDLFUNC_XBYTES_H
#define EXODUSDLFUNC_XBYTES_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_xbytes;
class efb_xbytes : public ExodusFunctorBase
{
public:

efb_xbytes(MvEnvironment& mv) : ExodusFunctorBase("xbytes", "exodusprogrambasecreatedelete_", mv) {}

efb_xbytes& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in type, in input0, in mode, out output)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,in,in,out);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_xbytes.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_xbytes.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (type,input0,mode,output);

}

var operator() () {
 var type_in;
 var input0_in;
 var mode_in;
 var output_out;
 return operator()(type_in, input0_in, mode_in, output_out);
}

var operator() (in type) {
 var input0_in;
 var mode_in;
 var output_out;
 return operator()(type, input0_in, mode_in, output_out);
}

var operator() (in type, in input0) {
 var mode_in;
 var output_out;
 return operator()(type, input0, mode_in, output_out);
}

var operator() (in type, in input0, in mode) {
 var output_out;
 return operator()(type, input0, mode, output_out);
}

};
efb_xbytes xbytes{mv};
//#endif
