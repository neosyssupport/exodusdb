//generated by exodus "compile ../add/videorw"
//#ifndef EXODUSDLFUNC_VIDEORW_H
#define EXODUSDLFUNC_VIDEORW_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_videorw;
class efb_videorw : public ExodusFunctorBase
{
public:

efb_videorw(MvEnvironment& mv) : ExodusFunctorBase("videorw", "exodusprogrambasecreatedelete_", mv) {}

efb_videorw& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in x, in y, in x2, in y2, in readwrite, io buffer)
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
 typedef var (ExodusProgramBase::*pExodusProgramBaseMemberFunction)(in,in,in,in,in,io);

 //call the shared library object main function with the right args,
 // returning a var or void
 //return CALLMEMBERFUNCTION(*(efb_videorw.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_videorw.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (x,y,x2,y2,readwrite,buffer);

}

var operator() () {
 var x_in;
 var y_in;
 var x2_in;
 var y2_in;
 var readwrite_in;
 var buffer_io;
 return operator()(x_in, y_in, x2_in, y2_in, readwrite_in, buffer_io);
}

var operator() (in x) {
 var y_in;
 var x2_in;
 var y2_in;
 var readwrite_in;
 var buffer_io;
 return operator()(x, y_in, x2_in, y2_in, readwrite_in, buffer_io);
}

var operator() (in x, in y) {
 var x2_in;
 var y2_in;
 var readwrite_in;
 var buffer_io;
 return operator()(x, y, x2_in, y2_in, readwrite_in, buffer_io);
}

var operator() (in x, in y, in x2) {
 var y2_in;
 var readwrite_in;
 var buffer_io;
 return operator()(x, y, x2, y2_in, readwrite_in, buffer_io);
}

var operator() (in x, in y, in x2, in y2) {
 var readwrite_in;
 var buffer_io;
 return operator()(x, y, x2, y2, readwrite_in, buffer_io);
}

var operator() (in x, in y, in x2, in y2, in readwrite) {
 var buffer_io;
 return operator()(x, y, x2, y2, readwrite, buffer_io);
}

};
efb_videorw videorw{mv};
//#endif
