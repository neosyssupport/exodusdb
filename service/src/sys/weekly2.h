//generated by exodus "compile ../sys/weekly2"
//#ifndef EXODUSDLFUNC_WEEKLY2_H
#define EXODUSDLFUNC_WEEKLY2_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_weekly2;
class efb_weekly2 : public ExodusFunctorBase
{
public:

efb_weekly2(MvEnvironment& mv) : ExodusFunctorBase("weekly2", "exodusprogrambasecreatedelete_", mv) {}

efb_weekly2& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in type, in input, in mode, out output)
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
 //return CALLMEMBERFUNCTION(*(efb_weekly2.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_weekly2.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (type,input,mode,output);

}

var operator() () {
 var type_in;
 var input_in;
 var mode_in;
 var output_out;
 return operator()(type_in, input_in, mode_in, output_out);
}

var operator() (in type) {
 var input_in;
 var mode_in;
 var output_out;
 return operator()(type, input_in, mode_in, output_out);
}

var operator() (in type, in input) {
 var mode_in;
 var output_out;
 return operator()(type, input, mode_in, output_out);
}

var operator() (in type, in input, in mode) {
 var output_out;
 return operator()(type, input, mode, output_out);
}

};
efb_weekly2 weekly2{mv};
//#endif
