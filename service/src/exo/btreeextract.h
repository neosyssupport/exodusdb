//generated by exodus "compile btreeextract"
//#ifndef EXODUSDLFUNC_BTREEEXTRACT_H
#define EXODUSDLFUNC_BTREEEXTRACT_H

//a member variable/object to cache a pointer/object for the shared library function
//ExodusFunctorBase efb_btreeextract;
class efb_btreeextract : public ExodusFunctorBase
{
public:

efb_btreeextract(MvEnvironment& mv) : ExodusFunctorBase("btreeextract", "exodusprogrambasecreatedelete_", mv) {}

efb_btreeextract& operator=(const var& newlibraryname) {
        closelib();
        libraryname_=newlibraryname.toString();
        return (*this);
}

//a member function with the right arguments, returning a var or void
var operator() (in cmd, in filename, in dictfile, out hits)
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
 //return CALLMEMBERFUNCTION(*(efb_btreeextract.pobject_),
 //((pExodusProgramBaseMemberFunction) (efb_btreeextract.pmemberfunction_)))
 // (mode);
 return CALLMEMBERFUNCTION(*(this->pobject_),
 ((pExodusProgramBaseMemberFunction) (this->pmemberfunction_)))
  (cmd,filename,dictfile,hits);

}

var operator() () {
 var cmd_in;
 var filename_in;
 var dictfile_in;
 var hits_out;
 return operator()(cmd_in, filename_in, dictfile_in, hits_out);
}

var operator() (in cmd) {
 var filename_in;
 var dictfile_in;
 var hits_out;
 return operator()(cmd, filename_in, dictfile_in, hits_out);
}

var operator() (in cmd, in filename) {
 var dictfile_in;
 var hits_out;
 return operator()(cmd, filename, dictfile_in, hits_out);
}

var operator() (in cmd, in filename, in dictfile) {
 var hits_out;
 return operator()(cmd, filename, dictfile, hits_out);
}

};
efb_btreeextract btreeextract{mv};
//#endif